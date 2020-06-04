#include "base64.h"

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
    QPoint EndPos;
    if ( event->buttons() == Qt::LeftButton ) {
        EndPos = event->globalPos() - StartPos;
        this->move(EndPos);
    }
}
void ClientWin::mousePressEvent(QMouseEvent *event) {
    if(event->buttons() == Qt::LeftButton) {
        StartPos = event->globalPos() - this->frameGeometry().topLeft();
    }
}

void ClientWin::sendMessage(MessageType type) {
    if (type == NewParticipant) {
        json hello_msg;
        hello_msg["user name"] = this->user_name;
        hello_msg["method"] = "hello";
        std::string t_s = hello_msg.dump();
        cout<<t_s<<endl;
        send(connect_socket, t_s.c_str(), t_s.length(), 0);
    }
    else if (type == Message){
        json jmsg;
        jmsg["method"] = "message";
        // get receiver
        if(ui->userTableWidget->selectedItems().isEmpty()) {
            QMessageBox::warning(0, tr("选择用户"),
                       tr("请先从右侧列表选择要传送的用户！"), QMessageBox::Ok);
            return;
        }
        
        // get message
        if(ui->messageTextEdit->toPlainText()=="") {
            QMessageBox::warning(0, tr("警告"), tr("发送内容不为空"), QMessageBox::Ok);
            return;
        }
        QString msg=ui->messageTextEdit->toPlainText();
        ui->messageTextEdit->clear();
        ui->messageTextEdit->setFocus();
        jmsg["msg"] = msg.toStdString();

        // get receiver
        QList<QTableWidgetItem*> items = ui->userTableWidget->selectedItems();
        int row = ui->userTableWidget->row(items.at(0));
        QTableWidgetItem *item = items.at(0);
        QString receiver_qs = item->text();
        jmsg["receiver"] = receiver_qs.toStdString();
        jmsg["sender"] = user_name;
        
        cout<<jmsg.dump()<<endl;
        std::string t_s = jmsg.dump();
        send(connect_socket, t_s.c_str(), t_s.length(), 0);
    }
    else if (type == FileSend) {
        json jmsg;
        jmsg["method"] = "file";
        // get receiver
        if(ui->userTableWidget->selectedItems().isEmpty()) {
            QMessageBox::warning(0, tr("选择用户"),
                       tr("请先从右侧列表选择要传送的用户！"), QMessageBox::Ok);
            return;
        }
        // get file & its base64
        QString file_path = QFileDialog::getOpenFileName(this);
        QString file_name = file_path.right(file_path.size() - file_path.lastIndexOf('/')-1);
        qDebug()<<file_path<<endl;
        ifstream ifs(file_path.toStdString(), ifstream::in|ifstream::binary);
        ifs.seekg (0, ios::end);   
        size_t length = ifs.tellg();  
        ifs.seekg (0, ios::beg);
        char buffer[length];
        std::string file_encoded = base64_encode(string(buffer, buffer+length), length);
        jmsg["file name"] = file_name.toStdString();
        jmsg["file"] = file_encoded;
        
        std::string t_s = jmsg.dump();
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
    // 先获得时间
    QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    cout<<"get: "<<msg<<endl;

    auto js = json::parse(msg);

    std::string method;
    js["method"].get_to<std::string>(method);

    if (method == "hello") {
        cout<<"updating chat list..."<<endl;
        // update data
        chat_list = js["chat list"];

        // update window
        // chat_list.dump(); bug？
        ui->userTableWidget->clear();
        for (int i=0; i<chat_list.size(); i++) {
            std::string tname;
            chat_list[i].get_to<std::string>(tname);

            // update user table
            QString tname_qs = QString::fromStdString(tname);

            QTableWidgetItem *user_name = new QTableWidgetItem(tname_qs);
            user_name->setTextAlignment(Qt::AlignLeft);
            ui->userTableWidget->insertRow(0);
            ui->userTableWidget->setItem(0, 0, user_name);

            ui->messageBrowser->setTextColor(Qt::gray);
            ui->messageBrowser->setCurrentFont(QFont("黑体",10));
            ui->messageBrowser->append(tr("%1: %2 在线！").arg(time).arg(tname_qs));
            ui->userNumLabel->setText(tr("在线人数：%1").arg(chat_list.size()));
        }
    }
    else if (method == "message") {
        std::string sender;
        std::string msg;
        js["sender"].get_to<std::string>(sender);
        js["msg"].get_to<std::string>(msg);

        QString sender_qs = QString::fromStdString(sender);
        QString msg_qs = QString::fromStdString(msg);
        ui->messageBrowser->setTextColor(Qt::blue);
        ui->messageBrowser->setCurrentFont(QFont("黑体",12));
        ui->messageBrowser->append("["+sender_qs+"]"+time);
        ui->messageBrowser->append(msg_qs);
    
    }
    else if (method == "file") {
        std::string sender;
        std::string file_name;
        std::string file_base64;
        js["sender"].get_to<std::string>(sender);
        js["file name"].get_to<std::string>(file_name);
        js["file"].get_to<std::string>(file_base64);

        QString sender_qs = QString::fromStdString(sender);
        QString file_name_qs = QString::fromStdString(file_name);

        std::string decoded_file = base64_decode(file_base64);
        int btn = QMessageBox::information(this, tr("接受文件"),
                                           tr("来自%1的文件：%2,是否接收？")
                                           .arg(sender_qs).arg(file_name_qs),
                                           QMessageBox::Yes,QMessageBox::No);
        json respond;
        respond["method"] = "file respond";
        respond["receiver"] = sender;
        if (btn == QMessageBox::Yes) {
            QString file_path = QFileDialog::getSaveFileName(0, tr("保存文件"), file_name_qs);
            if(!file_path.isEmpty()) {
                std::ofstream out(file_path.toStdString().c_str(), ios_base::out|ios_base::binary);
                out.write(decoded_file.c_str(), decoded_file.length());
                out.close();
                QMessageBox::information(this, tr("information"), tr("接受成功"));
                respond["succeed"] = true;
            }
            else {
                respond["succeed"] = false;
            }
        }
        else {
            respond["succeed"] = false;
        }
        std::string t_s = respond.dump();
        send(connect_socket, t_s.c_str(), t_s.length(), 0);
    }
}

// 传消息
void ClientWin::on_sendButton_clicked() {
    sendMessage(Message);
}

// 传文件
void ClientWin::on_sendToolButton_clicked() {
    sendMessage(FileSend);
}

// 字体槽
void ClientWin::on_fontComboBox_currentFontChanged(const QFont &f) {
    ui->messageTextEdit->setCurrentFont(f);
    ui->messageTextEdit->setFocus();
}
void ClientWin::on_sizeComboBox_currentIndexChanged(QString size) {
    ui->messageTextEdit->setFontPointSize(size.toDouble());
    ui->messageTextEdit->setFocus();
}
void ClientWin::on_boldToolButton_clicked(bool checked) {
    if(checked)
        ui->messageTextEdit->setFontWeight(QFont::Bold);
    else
        ui->messageTextEdit->setFontWeight(QFont::Normal);
    ui->messageTextEdit->setFocus();
}
void ClientWin::on_italicToolButton_clicked(bool checked) {
    ui->messageTextEdit->setFontItalic(checked);
    ui->messageTextEdit->setFocus();
}
void ClientWin::on_underlineToolButton_clicked(bool checked) {
    ui->messageTextEdit->setFontUnderline(checked);
    ui->messageTextEdit->setFocus();
}
void ClientWin::on_colorToolButton_clicked() {
    color = QColorDialog::getColor(color, this);
    if (color.isValid()) {
        ui->messageTextEdit->setTextColor(color);
        ui->messageTextEdit->setFocus();
    }
}
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

// 保存聊天记录
void ClientWin::on_saveToolButton_clicked() {
    if (ui->messageBrowser->document()->isEmpty()) {
        QMessageBox::warning(0, tr("警告"), tr("聊天记录为空，无法保存！"), QMessageBox::Ok);
    } 
    else {
        QString fileName = QFileDialog::getSaveFileName(this, tr("保存聊天记录"), tr("聊天记录"), tr("文本(*.txt);;All File(*.*)"));
        if(!fileName.isEmpty()) {
            QFile file(fileName);
            if (!file.open(QFile::WriteOnly | QFile::Text)) {
                QMessageBox::warning(this, tr("保存文件"), tr("无法保存文件 %1:\n %2").arg(fileName).arg(file.errorString()));
                return ;
            }
            QTextStream out(&file);
            out << ui->messageBrowser->toPlainText();
            return ;
        }
    }

}

// 清空聊天记录
void ClientWin::on_clearToolButton_clicked() {
    ui->messageBrowser->clear();
}



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
