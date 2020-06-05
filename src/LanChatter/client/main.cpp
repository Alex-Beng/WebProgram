#include "clientwin.h"  

#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <fstream>
using namespace std;

#include <QMetaType>
#include <QApplication>
#include <QCommandLineParser>


int main(int argc, char *argv[]) {
    qRegisterMetaType<std::string>("std::string"); 

    QApplication a(argc, argv);
    QApplication::setApplicationName("ab-lan-chatter-client");
    QApplication::setApplicationVersion("1.0");
    


    // 解析命令行参数，获得server ip 和端口
    QCommandLineParser parser;
    parser.setApplicationDescription("ab-lan-chatter-client");
    parser.addHelpOption();
    parser.addVersionOption();

    parser.setApplicationDescription(QGuiApplication::translate("main", "Qt"));  
    QCommandLineOption ipOption(QStringList() << "ip",
                                   QGuiApplication::translate("main", "IP of the server (default is localhost)."),
                                   QGuiApplication::translate("main", "IP"), "127.0.0.1");
    QCommandLineOption portOption(QStringList() << "port" << "p",
                                   QGuiApplication::translate("main", "port of the server (default is 666)."),
                                   QGuiApplication::translate("main", "port"), "666");

    QCommandLineOption nameOption(QStringList() << "name" << "n",
                                   QGuiApplication::translate("main", "name of user (default is Anonymous)."),
                                   QGuiApplication::translate("main", "name"), "Anonymous");
    parser.addOption(ipOption);
    parser.addOption(portOption);
    parser.addOption(nameOption);

    parser.process(a);

    std::string ip = parser.value(ipOption).toStdString();
    USHORT port =  parser.value(portOption).toUShort();
    std::string user_name = parser.value(nameOption).toStdString();

    cout<<user_name<<endl;

    ClientWin cw(0, user_name, ip, port);
    // cw.setPersonInfo(user_name, ip, port);
    cw.show();

    return a.exec();
}
