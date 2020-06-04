#ifndef CLIENTWIN_H
#define CLIENTWIN_H

#include "recvmsg.h"

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

#include <iostream>
using namespace std;

namespace Ui {
class ClientWin;
}

// 常规msg(base64传文件)，连接server，新建群组，  断开server，向xxx发文件，拒绝接受文件
enum MessageType{Message, NewParticipant, NewGroup, Participantleft, FileSend, Refuse};

class ClientWin :public QWidget {
    Q_OBJECT
public:
    ClientWin(QWidget *parent, std::string user_name, std::string ip, USHORT port);
    ~ClientWin();

    /* AboutpushButton按钮下的菜单 */
    QAction *b1,*b2,*b3,*b4,*b;
private:
    Ui::ClientWin *ui;
    QColor color;

    std::string user_name;
    std::string ip;
    USHORT port;

    SOCKET connect_socket;
    sockaddr_in server_addr;

    json chat_list;

    recvMsg* recv_thread;

    // 重写鼠标拖动事件
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    QPoint StartPos; // 用于记录窗口位置

protected:
    // 向服务器发送msg
    void sendMessage(MessageType type, std::string msg="");

    // 重载widget事件函数
    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_recv_msg(std::string);  // 处理接收到的msg

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

class NoFocusDelegate : public QStyledItemDelegate
{
protected:
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const {
        QStyleOptionViewItem itemOption(option);
        if (itemOption.state & QStyle::State_HasFocus)
            itemOption.state = itemOption.state ^ QStyle::State_HasFocus;
        QStyledItemDelegate::paint(painter, itemOption, index);
    }
};



#endif // CLIENTWIN_H
