#ifndef CLIENTWIN_H
#define CLIENTWIN_H

#include "json.hpp"
using json = nlohmann::json;

#include <windows.h>
#include <windowsx.h>
#include <winsock2.h>

#include <QWidget>
#include <QTextCharFormat>
#include <QtGui>
#include <QItemDelegate>
#include <QStyledItemDelegate>
#include <QMenu>
#include <QAction>
#include <QtNetwork/QUdpSocket>

namespace Ui {
class ClientWin;
}

enum MessageType{Message,NewParticipant,Participantleft,FileName,Refuse};

class ClientWin :public QWidget {
    Q_OBJECT
public:
    explicit ClientWin(QWidget *parent = 0);
    ~ClientWin();

    void setPersonInfo(std::string user_name, std::string ip, USHORT port);
private:
    Ui::ClientWin *ui;

    std::string user_name;
    std::string ip;
    USHORT port;

    SOCKET connect_socket;
    sockaddr_in server_addr;

    json chat_list;
protected:

private slots:
    void processPendingDatagrams();
    void getFileName(QString);
    void on_sendButton_clicked();
    void on_sendToolButton_clicked();
    void on_fontComboBox_currentFontChanged(const QFont &f);
    void on_sizeComboBox_currentIndexChanged(QString);
    void on_boldToolButton_clicked(bool checked);
    void on_italicToolButton_clicked(bool checked);
    void on_underlineToolButton_clicked(bool checked);
    void on_colorToolButton_clicked();
    void currentFormatChanged(const QTextCharFormat &format);
    void on_exitButton_clicked();
    void on_saveToolButton_clicked();
    void on_clearToolButton_clicked();
    void on_closeButton_clicked();
    void on_minButton_clicked();
    void on_maxButton_clicked();
    void bg();
    void bg1();
    void bg2();
    void bg3();
    void bg4();

};


#endif // CLIENTWIN_H
