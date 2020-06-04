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
    
    
}

ClientWin::~ClientWin() {
    ::closesocket(connect_socket);
    WSACleanup();

    if (recv_thread) {
        recv_thread->quit();
    }

    delete ui;
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

void ClientWin::on_recv_msg(std::string msg){
    cout<<msg<<endl;
    auto js = json::parse(msg);
    std::string method;

    js["method"].get_to<std::string>(method);

    if (method == "hello") {
        chat_list = js["chat list"];
        

        cout<<"updated chat list"<<endl;
    }
}

void ClientWin::on_sendButton_clicked(){}
void ClientWin::on_sendToolButton_clicked(){}
void ClientWin::on_fontComboBox_currentFontChanged(const QFont &f){}
void ClientWin::on_sizeComboBox_currentIndexChanged(QString){}
void ClientWin::on_boldToolButton_clicked(bool checked){}
void ClientWin::on_italicToolButton_clicked(bool checked){}
void ClientWin::on_underlineToolButton_clicked(bool checked){}
void ClientWin::on_colorToolButton_clicked(){}
void ClientWin::currentFormatChanged(const QTextCharFormat &format){}
void ClientWin::on_exitButton_clicked(){}
void ClientWin::on_saveToolButton_clicked(){}
void ClientWin::on_clearToolButton_clicked(){}
void ClientWin::on_closeButton_clicked(){}
void ClientWin::on_minButton_clicked(){}
void ClientWin::on_maxButton_clicked(){}
void ClientWin::bg(){}
void ClientWin::bg1(){}
void ClientWin::bg2(){}
void ClientWin::bg3(){}
void ClientWin::bg4(){}
