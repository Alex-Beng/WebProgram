#include "clientwin.h"
#include "ui_clientwin.h"


#include<QDebug>
#include<QtNetwork/QUdpSocket>
#include<QtNetwork/QHostInfo>
#include<QMessageBox>
#include<QScrollBar>
#include<QDateTime>
#include<QtNetwork/QNetworkInterface>
#include<QProcess>

#include <QFileDialog>

#include <QColorDialog>

#include <QPropertyAnimation>
#include <QMouseEvent>

ClientWin::ClientWin(QWidget *parent, std::string user_name, std::string ip, USHORT port) : QWidget(parent), ui(new Ui::ClientWin) {     
    ui->setupUi(this);

    // 连接server
    this->user_name = user_name;
    this->ip = ip;
    this->port = port;
    
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        QMessageBox::warning(0,tr("警告"),tr("winsock can't startup"),QMessageBox::Ok);
        throw std::runtime_error("winsock can't startup");
    }
    connect_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (connect_socket == INVALID_SOCKET) {
        QMessageBox::warning(0,tr("警告"),tr("can't init socket"),QMessageBox::Ok);
        throw std::runtime_error("can't init socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    server_addr.sin_port = htons(port);

    iResult = ::connect(connect_socket, (SOCKADDR*) &server_addr, sizeof(server_addr));
    if ( iResult == SOCKET_ERROR) {
        closesocket(connect_socket);
        QMessageBox::warning(0,tr("警告"),tr("can't connect to server"),QMessageBox::Ok);
        throw std::runtime_error("can't connect to server");
    }

    qDebug()<<"connected to server";

    // 创建recv thread
    recv_thread = new recvMsg(connect_socket);
    recv_thread->start();

    connect(recv_thread, &recvMsg::isMsg, this, &ClientWin::on_recv_msg);

    qDebug()<<"created recv thread";

    // say hello to server update chat list
    sendMessage(NewParticipant);
    
    // 窗口相关设置
    // 设置字符格式
    connect(ui->messageTextEdit, SIGNAL(currentCharFormatChanged(QTextCharFormat)),this, SLOT(currentFormatChanged(const QTextCharFormat)));

    setWindowFlags(Qt::FramelessWindowHint);//无边框
    setAttribute(Qt::WA_TranslucentBackground);//背景透明
    //-------------------------------
    ui->sendButton->setFocus();    //设置默认焦点
    ui->sendButton->setShortcut( QKeySequence::InsertParagraphSeparator );  //设置快捷键为键盘的“回车”键
    ui->sendButton->setShortcut(Qt::Key_Enter);  //设置快捷键为enter键
    ui->sendButton->setShortcut(Qt::Key_Return); //设置快捷键为小键盘上的enter键
    ui->sendButton->setFocus();    //设置默认焦点
    ui->sendButton->setDefault(true);  //设置默认按钮，设置了这个属性，当用户按下回车的时候，就会按下该按钮
    //-------------------------------


    ui->messageBrowser->verticalScrollBar()->setStyleSheet(
    "QScrollBar:vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;padding-top:9px;padding-bottom:9px;}"//留9px给上下箭头
    "QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%);border-radius:4px;min-height:20;}"//上下设置为椭圆
    "QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%);border-radius:4px;min-height:20;}"//鼠标悬浮颜色变深
    "QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/bottom.png);subcontrol-position:bottom;}"//下箭头
    "QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/top.png);subcontrol-position:top;}"//上箭头
    "QScrollBar::add-line:vertical:hover{height:7px;width:6px;border-image:url(:/images/bottom.png);border:1px;subcontrol-position:bottom;}"//鼠标悬浮下箭头
    "QScrollBar::sub-line:vertical:hover{height:7px;width:6px;border-image:url(:/images/top.png);border:1px;subcontrol-position:top;}"//鼠标悬浮上箭头
    "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;}");//滚动时部分
    ui->messageTextEdit->verticalScrollBar()->setStyleSheet(
    "QScrollBar:vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;padding-top:9px;padding-bottom:9px;}"//留9px给上下箭头
    "QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%);border-radius:4px;min-height:20;}"//上下设置为椭圆
    "QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%);border-radius:4px;min-height:20;}"//鼠标悬浮颜色变深
    "QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/bottom.png);subcontrol-position:bottom;}"//下箭头
    "QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/top.png);subcontrol-position:top;}"//上箭头
    "QScrollBar::add-line:vertical:hover{height:7px;width:6px;border-image:url(:/images/bottom.png);border:1px;subcontrol-position:bottom;}"//鼠标悬浮下箭头
    "QScrollBar::sub-line:vertical:hover{height:7px;width:6px;border-image:url(:/images/top.png);border:1px;subcontrol-position:top;}"//鼠标悬浮上箭头
    "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;}");//滚动时部分
    ui->userTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//表格只读
    ui->userTableWidget->setItemDelegate(new NoFocusDelegate());//去掉表格虚框
    ui->userTableWidget->setTextElideMode(Qt::ElideRight);//防止文本过长显示右边

    QMenu * menu = ui->menuButton->getmenu();
    b1 = new QAction(QIcon(":/images/menu.png"), tr("&星球皮肤"), this);
    b2 = new QAction(QIcon(":/images/menu.png"), tr("&绿草皮肤"), this);
    b3 = new QAction(QIcon(":/images/menu.png"), tr("&唯美皮肤"), this);
    b4 = new QAction(QIcon(":/images/menu.png"), tr("&秋季皮肤"), this);
    b = new QAction(QIcon(":/images/menu.png"), tr("&原始皮肤"), this);
    menu->addAction(b1);
    menu->addAction(b2);
    menu->addAction(b3);
    menu->addAction(b4);
    menu->addAction(b);
    connect(b1,SIGNAL(triggered(bool)),this,SLOT(bg1()));
    connect(b2,SIGNAL(triggered(bool)),this,SLOT(bg2()));
    connect(b3,SIGNAL(triggered(bool)),this,SLOT(bg3()));
    connect(b4,SIGNAL(triggered(bool)),this,SLOT(bg4()));
    connect(b,SIGNAL(triggered(bool)),this,SLOT(bg())); // 放最后实现默认皮肤
    ui->messageTextEdit->installEventFilter(this);//回车键发消息监听
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);//任务栏使程序最小化


}

ClientWin::~ClientWin() {
    ::closesocket(connect_socket);
    WSACleanup();

    if (recv_thread) {
        recv_thread->quit();
    }

    delete ui;
}

void ClientWin::mouseMoveEvent(QMouseEvent *event) {
    //去表格虚框
    QPoint EndPos;
    if ( event->buttons() == Qt::LeftButton ) {
        EndPos = event->globalPos() - StartPos;
        this->move(EndPos);
    }
}

void ClientWin::mousePressEvent(QMouseEvent *event) {
    if(event->buttons() == Qt::LeftButton) {
        //记录窗口此时的坐标
        StartPos = event->globalPos() - this->frameGeometry().topLeft();
    }
}

void ClientWin::sendMessage(MessageType type, std::string msg) {
    if (type == NewParticipant) {
        json hello_msg;
        hello_msg["user name"] = this->user_name;
        hello_msg["method"] = "hello";
        std::string t_s = hello_msg.dump();
        cout<<t_s<<endl;
        send(connect_socket, t_s.c_str(), t_s.length(), 0);
    }
    
}

// 重载事件函数
void ClientWin::paintEvent(QPaintEvent *) {
    QPainter p(this);
    if(this->width() > 45 && this->height() > 45) {
        QList<QPixmap> pixmaps;
        pixmaps.append(QPixmap(":/images/shadow_left.png"));
        pixmaps.append(QPixmap(":/images/shadow_right.png"));
        pixmaps.append(QPixmap(":/images/shadow_top.png"));
        pixmaps.append(QPixmap(":/images/shadow_bottom.png"));
        pixmaps.append(QPixmap(":/images/shadow_corner1.png"));
        pixmaps.append(QPixmap(":/images/shadow_corner2.png"));
        pixmaps.append(QPixmap(":/images/shadow_corner3.png"));
        pixmaps.append(QPixmap(":/images/shadow_corner4.png"));

        p.drawPixmap(0,0,5,5,pixmaps[4]);
        p.drawPixmap(this->width() - 5,0,5,5,pixmaps[5]);
        p.drawPixmap(0,this->height() - 5,5,5,pixmaps[6]);
        p.drawPixmap(this->width() - 5,this->height() - 5,5,5,pixmaps[7]);

        p.drawPixmap(0,5,5,this->height() - 10,pixmaps[0].scaled(5,this->height() - 10));
        p.drawPixmap(this->width() - 5,5,5,this->height() - 10,pixmaps[1].scaled(5,this->height() - 10));
        p.drawPixmap(5,0,this->width() - 10,5,pixmaps[2].scaled(this->width() - 10,5));
        p.drawPixmap(5,this->height() - 5,this->width() - 10,5,pixmaps[3].scaled(this->width() - 10,5));
    }
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::white);
    p.drawRoundedRect(QRect(5,5,this->width() - 10,this->height() - 10),2.0f,2.0f);

}
bool ClientWin::eventFilter(QObject *obj, QEvent *event) {
    if(obj == ui->messageTextEdit) {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast <QKeyEvent *>(event);
            if(keyEvent->key()==Qt::Key_Return) {
                qDebug()<<"int envent filter";
                emit sendMessage(Message);
                return true;
            }
        }
    }
    return QObject::eventFilter(obj, event);

}



void ClientWin::on_recv_msg(std::string msg){
    cout<<"get: "<<msg<<endl;
    auto js = json::parse(msg);
    std::string method;

    js["method"].get_to<std::string>(method);

    if (method == "hello") {
        // update data
        chat_list = js["chat list"];

        // update window
        // chat_list.dump(); bug？
        for (int i=0; i<chat_list.size(); i++) {
            std::string tname;
            chat_list[i].get_to<std::string>(tname);

            
        }

        cout<<"updated chat list"<<endl;
    }
}

void ClientWin::on_sendButton_clicked(){

}
void ClientWin::on_sendToolButton_clicked(){}
void ClientWin::on_fontComboBox_currentFontChanged(const QFont &f){}
void ClientWin::on_sizeComboBox_currentIndexChanged(QString){}
void ClientWin::on_boldToolButton_clicked(bool checked){}
void ClientWin::on_italicToolButton_clicked(bool checked){}
void ClientWin::on_underlineToolButton_clicked(bool checked){}
void ClientWin::on_colorToolButton_clicked(){}

void ClientWin::currentFormatChanged(const QTextCharFormat &format) {//鼠标点击不同大小文字，转换到对应状态
    ui->fontComboBox->setCurrentFont(format.font());

    if (format.fontPointSize() < 9) {
        ui->sizeComboBox->setCurrentIndex(3);
    } else {
        ui->sizeComboBox->setCurrentIndex( ui->sizeComboBox
                                          ->findText(QString::number(format.fontPointSize())));
    }
    ui->boldToolButton->setChecked(format.font().bold());
    ui->italicToolButton->setChecked(format.font().italic());
    ui->underlineToolButton->setChecked(format.font().underline());
    color = format.foreground().color();
}

// 下方关闭键
void ClientWin::on_exitButton_clicked(){
    /* 慢慢消失的效果 */
    QPropertyAnimation *animation = new QPropertyAnimation(this,"windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation,SIGNAL(finished()),this,SLOT(close()));//效果显示完后关闭
}

void ClientWin::on_saveToolButton_clicked(){}
void ClientWin::on_clearToolButton_clicked(){}



// 右上三键
void ClientWin::on_closeButton_clicked() {
    /* 慢慢消失的效果 */
    QPropertyAnimation *animation = new QPropertyAnimation(this,"windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation,SIGNAL(finished()),this,SLOT(close()));//效果显示完后关闭
}
void ClientWin::on_minButton_clicked() {
    this->showMinimized();//最小化
}
void ClientWin::on_maxButton_clicked() {
    QMessageBox::warning(0,tr("警告"),tr("不想写了，写吐了"),QMessageBox::Ok);
}


// 菜单栏选项
void ClientWin::bg(){
    ui->stackedWidget->setStyleSheet("QStackedWidget {background-image: url(:/images/background.jpg);}");
}
void ClientWin::bg1(){
    ui->stackedWidget->setStyleSheet("QStackedWidget {background-image: url(:/images/background1.jpg);}");
}
void ClientWin::bg2(){
    ui->stackedWidget->setStyleSheet("QStackedWidget {background-image: url(:/images/background2.jpg);}");
}
void ClientWin::bg3(){
    ui->stackedWidget->setStyleSheet("QStackedWidget {background-image: url(:/images/background3.jpg);}");
}
void ClientWin::bg4(){
    ui->stackedWidget->setStyleSheet("QStackedWidget {background-image: url(:/images/background4.jpg);}");
}
