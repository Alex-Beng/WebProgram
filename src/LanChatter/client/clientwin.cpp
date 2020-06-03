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

ClientWin::ClientWin(QWidget *parent) : QWidget(parent), ui(new Ui::ClientWin) {     
    ui->setupUi(this);

    
}


ClientWin::~ClientWin() {
    delete ui;
}

void ClientWin::processPendingDatagrams(){}
void ClientWin::getFileName(QString){}
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