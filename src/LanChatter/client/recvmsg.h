#ifndef RECVMSG_H
#define RECVMSG_H

#include <winsock2.h>

#include <QWidget>
#include <QThread>
#include <QTime>
#include <QDebug>
#include<QMessageBox>

#include <iostream>
using namespace std;


class recvMsg : public QThread {
    Q_OBJECT
public:
    explicit recvMsg(SOCKET mSocket, QWidget *parent = nullptr) : QThread(parent) {
        this->mSocket = mSocket;
    }
    void run() {
        // QMessageBox::warning(0,tr("警告"), tr("recv thread running.."), QMessageBox::Ok);
        // qDebug()<<"recv thread running..."<<endl;
        char buf[10240] = {0};
        while(1) {
            int ret = ::recv(mSocket, buf, 10240, 0);
            
            // 服务器down了
            if( ret <= 0){
                QMessageBox::warning(0,tr("警告"), tr("服务器关闭了鸭"), QMessageBox::Ok);
                throw std::runtime_error("server closed");
            }
            else {
                std::string recv_msg(buf, buf+strlen(buf));
                // cout<<"get "<<ret<<":"<<recv_msg<<endl;
                emit isMsg(recv_msg);
            }
            
        }

    }

signals:
    void isMsg(std::string msg);

private:
    SOCKET mSocket;
};

#endif
