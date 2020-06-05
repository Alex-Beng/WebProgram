/********************************************************************************
** Form generated from reading UI file 'clientwin.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIN_H
#define UI_CLIENTWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "menubutton.h"

QT_BEGIN_NAMESPACE

class Ui_ClientWin
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTextBrowser *messageBrowser;
    QTextEdit *messageTextEdit;
    QPushButton *sendButton;
    QPushButton *exitButton;
    QFrame *line;
    QFrame *line_2;
    QFontComboBox *fontComboBox;
    QComboBox *sizeComboBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *boldToolButton;
    QToolButton *italicToolButton;
    QToolButton *underlineToolButton;
    QToolButton *colorToolButton;
    QToolButton *sendToolButton;
    QToolButton *saveToolButton;
    QToolButton *clearToolButton;
    QFrame *line_3;
    QToolButton *toolButton_8;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *createGroup;
    QToolButton *toolButton_7;
    QPushButton *pushButton;
    QLabel *userNumLabel;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    MenuButton *menuButton;
    QToolButton *minButton;
    QToolButton *maxButton;
    QToolButton *closeButton;
    QTableWidget *userTableWidget;
    QWidget *page_2;

    void setupUi(QWidget *ClientWin)
    {
        if (ClientWin->objectName().isEmpty())
            ClientWin->setObjectName(QStringLiteral("ClientWin"));
        ClientWin->resize(750, 500);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ClientWin->sizePolicy().hasHeightForWidth());
        ClientWin->setSizePolicy(sizePolicy);
        ClientWin->setMinimumSize(QSize(750, 500));
        ClientWin->setMaximumSize(QSize(750, 500));
        ClientWin->setAutoFillBackground(false);
        ClientWin->setStyleSheet(QStringLiteral(""));
        stackedWidget = new QStackedWidget(ClientWin);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(5, 5, 740, 490));
        stackedWidget->setMinimumSize(QSize(740, 490));
        stackedWidget->setMaximumSize(QSize(740, 490));
        stackedWidget->setStyleSheet(QLatin1String("QStackedWidget {background-image: url(:/images/background.jpg);}\n"
""));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        stackedWidget->setFrameShadow(QFrame::Sunken);
        stackedWidget->setLineWidth(1);
        stackedWidget->setMidLineWidth(0);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        messageBrowser = new QTextBrowser(page);
        messageBrowser->setObjectName(QStringLiteral("messageBrowser"));
        messageBrowser->setGeometry(QRect(10, 100, 480, 250));
        messageBrowser->setMinimumSize(QSize(480, 250));
        messageBrowser->setMaximumSize(QSize(480, 250));
        QFont font;
        font.setPointSize(12);
        messageBrowser->setFont(font);
        messageBrowser->setStyleSheet(QStringLiteral("QTextBrowser { background-color: rgb(255, 255, 255,0); border-radius: 3px; color: rgb(0, 0, 0); }"));
        messageBrowser->setLineWidth(1);
        messageBrowser->setTabStopWidth(80);
        messageBrowser->setCursorWidth(1);
        messageTextEdit = new QTextEdit(page);
        messageTextEdit->setObjectName(QStringLiteral("messageTextEdit"));
        messageTextEdit->setGeometry(QRect(10, 390, 480, 70));
        messageTextEdit->setMinimumSize(QSize(480, 70));
        messageTextEdit->setMaximumSize(QSize(16777215, 16777215));
        messageTextEdit->setFont(font);
        messageTextEdit->setStyleSheet(QLatin1String("QTextEdit { background-color: rgb(255, 255, 255,0); border-radius: 3px;color: rgb(0, 0, 0);  }\n"
"\n"
"\n"
""));
        messageTextEdit->setLineWidth(1);
        sendButton = new QPushButton(page);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(400, 462, 60, 25));
        sendButton->setMinimumSize(QSize(60, 25));
        sendButton->setMaximumSize(QSize(103, 41));
        sendButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(50, 50, 50,200); border-radius: 3px; color: rgb(255, 255, 255); }\n"
" QPushButton:hover { background-color: rgb(50, 50, 50,255);}\n"
""));
        exitButton = new QPushButton(page);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(330, 462, 60, 25));
        exitButton->setMinimumSize(QSize(60, 25));
        exitButton->setMaximumSize(QSize(103, 41));
        exitButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(50, 50, 50,200); border-radius: 3px; color: rgb(255, 255, 255); }\n"
" QPushButton:hover { background-color: rgb(50, 50, 50,255);}\n"
""));
        line = new QFrame(page);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 347, 480, 2));
        line->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 125);"));
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);
        line_2 = new QFrame(page);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(490, 80, 2, 415));
        line_2->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 125);"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        fontComboBox = new QFontComboBox(page);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setEnabled(true);
        fontComboBox->setGeometry(QRect(10, 350, 155, 30));
        fontComboBox->setMinimumSize(QSize(155, 30));
        fontComboBox->setMaximumSize(QSize(155, 30));
        fontComboBox->setFont(font);
        fontComboBox->setMouseTracking(false);
        fontComboBox->setAcceptDrops(false);
        fontComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	background-color: rgb(255, 255, 255);\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 2px 1px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"    /*min-width: 9em;   \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"\n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid; \n"
"    border-top-right-radius: 3px; \n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: url(:/images/QComboBox);\n"
"}\n"
"QComboBox::drop-down:hover { background-color: rgb(50, 50, 50,255);}"));
        fontComboBox->setEditable(false);
        sizeComboBox = new QComboBox(page);
        sizeComboBox->setObjectName(QStringLiteral("sizeComboBox"));
        sizeComboBox->setGeometry(QRect(180, 350, 45, 30));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(sizeComboBox->sizePolicy().hasHeightForWidth());
        sizeComboBox->setSizePolicy(sizePolicy1);
        sizeComboBox->setMinimumSize(QSize(45, 30));
        sizeComboBox->setMaximumSize(QSize(45, 30));
        sizeComboBox->setFont(font);
        sizeComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	background-color: rgb(255, 255, 255);\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 2px 1px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"    /*min-width: 9em;   \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"\n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid; \n"
"    border-top-right-radius: 3px; \n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: url(:/images/QComboBox);\n"
"}\n"
"QComboBox::drop-down:hover { background-color: rgb(50, 50, 50,255);}"));
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(240, 350, 254, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        boldToolButton = new QToolButton(layoutWidget);
        boldToolButton->setObjectName(QStringLiteral("boldToolButton"));
        boldToolButton->setMinimumSize(QSize(30, 30));
        boldToolButton->setMaximumSize(QSize(30, 30));
        boldToolButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldToolButton->setIcon(icon);
        boldToolButton->setCheckable(true);

        horizontalLayout->addWidget(boldToolButton);

        italicToolButton = new QToolButton(layoutWidget);
        italicToolButton->setObjectName(QStringLiteral("italicToolButton"));
        italicToolButton->setMinimumSize(QSize(30, 30));
        italicToolButton->setMaximumSize(QSize(30, 30));
        italicToolButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicToolButton->setIcon(icon1);
        italicToolButton->setCheckable(true);

        horizontalLayout->addWidget(italicToolButton);

        underlineToolButton = new QToolButton(layoutWidget);
        underlineToolButton->setObjectName(QStringLiteral("underlineToolButton"));
        underlineToolButton->setMinimumSize(QSize(30, 30));
        underlineToolButton->setMaximumSize(QSize(30, 30));
        underlineToolButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        underlineToolButton->setIcon(icon2);
        underlineToolButton->setCheckable(true);

        horizontalLayout->addWidget(underlineToolButton);

        colorToolButton = new QToolButton(layoutWidget);
        colorToolButton->setObjectName(QStringLiteral("colorToolButton"));
        colorToolButton->setMinimumSize(QSize(30, 30));
        colorToolButton->setMaximumSize(QSize(30, 30));
        colorToolButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorToolButton->setIcon(icon3);

        horizontalLayout->addWidget(colorToolButton);

        sendToolButton = new QToolButton(layoutWidget);
        sendToolButton->setObjectName(QStringLiteral("sendToolButton"));
        sendToolButton->setMinimumSize(QSize(30, 30));
        sendToolButton->setMaximumSize(QSize(30, 30));
        sendToolButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendToolButton->setIcon(icon4);

        horizontalLayout->addWidget(sendToolButton);

        saveToolButton = new QToolButton(layoutWidget);
        saveToolButton->setObjectName(QStringLiteral("saveToolButton"));
        saveToolButton->setMinimumSize(QSize(30, 30));
        saveToolButton->setMaximumSize(QSize(30, 30));
        saveToolButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveToolButton->setIcon(icon5);

        horizontalLayout->addWidget(saveToolButton);

        clearToolButton = new QToolButton(layoutWidget);
        clearToolButton->setObjectName(QStringLiteral("clearToolButton"));
        clearToolButton->setMinimumSize(QSize(30, 30));
        clearToolButton->setMaximumSize(QSize(30, 30));
        clearToolButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearToolButton->setIcon(icon6);

        horizontalLayout->addWidget(clearToolButton);

        line_3 = new QFrame(page);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(10, 80, 480, 2));
        line_3->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 125);"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        toolButton_8 = new QToolButton(page);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        toolButton_8->setGeometry(QRect(10, 8, 40, 40));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(40);
        sizePolicy2.setVerticalStretch(40);
        sizePolicy2.setHeightForWidth(toolButton_8->sizePolicy().hasHeightForWidth());
        toolButton_8->setSizePolicy(sizePolicy2);
        toolButton_8->setMinimumSize(QSize(40, 40));
        toolButton_8->setStyleSheet(QStringLiteral("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/head.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_8->setIcon(icon7);
        toolButton_8->setIconSize(QSize(40, 40));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 30, 221, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(8);
        label->setFont(font1);
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(62, 5, 100, 25));
        label_2->setMinimumSize(QSize(100, 25));
        label_2->setBaseSize(QSize(100, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        label_2->setFont(font2);
        layoutWidget1 = new QWidget(page);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 48, 254, 32));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton = new QToolButton(layoutWidget1);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(30, 30));
        toolButton->setMaximumSize(QSize(30, 30));
        toolButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/mcallphone.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon8);
        toolButton->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(toolButton);

        toolButton_2 = new QToolButton(layoutWidget1);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(30, 30));
        toolButton_2->setMaximumSize(QSize(30, 30));
        toolButton_2->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/video.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon9);
        toolButton_2->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(layoutWidget1);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(30, 30));
        toolButton_3->setMaximumSize(QSize(30, 30));
        toolButton_3->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/control.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon10);
        toolButton_3->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(layoutWidget1);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(30, 30));
        toolButton_4->setMaximumSize(QSize(30, 30));
        toolButton_4->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon11);
        toolButton_4->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(layoutWidget1);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setMinimumSize(QSize(30, 30));
        toolButton_5->setMaximumSize(QSize(30, 30));
        toolButton_5->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/images/table.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon12);
        toolButton_5->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(toolButton_5);

        createGroup = new QToolButton(layoutWidget1);
        createGroup->setObjectName(QStringLiteral("createGroup"));
        createGroup->setMinimumSize(QSize(30, 30));
        createGroup->setMaximumSize(QSize(30, 30));
        createGroup->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/images/people.png"), QSize(), QIcon::Normal, QIcon::Off);
        createGroup->setIcon(icon13);
        createGroup->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(createGroup);

        toolButton_7 = new QToolButton(layoutWidget1);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setMinimumSize(QSize(30, 30));
        toolButton_7->setMaximumSize(QSize(30, 30));
        toolButton_7->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/images/software.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon14);
        toolButton_7->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(toolButton_7);

        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(59, 30, 16, 16));
        pushButton->setMinimumSize(QSize(16, 16));
        pushButton->setMaximumSize(QSize(16, 16));
        pushButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QPushButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/images/star.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon15);
        userNumLabel = new QLabel(page);
        userNumLabel->setObjectName(QStringLiteral("userNumLabel"));
        userNumLabel->setGeometry(QRect(480, 460, 135, 30));
        userNumLabel->setMinimumSize(QSize(135, 30));
        userNumLabel->setMaximumSize(QSize(157, 41));
        QFont font3;
        font3.setPointSize(9);
        userNumLabel->setFont(font3);
        userNumLabel->setStyleSheet(QStringLiteral(""));
        userNumLabel->setAlignment(Qt::AlignCenter);
        layoutWidget2 = new QWidget(page);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(602, -1, 143, 32));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        menuButton = new MenuButton(layoutWidget2);
        menuButton->setObjectName(QStringLiteral("menuButton"));
        menuButton->setMinimumSize(QSize(30, 30));
        menuButton->setMaximumSize(QSize(30, 30));
        menuButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QPushButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/images/menu.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuButton->setIcon(icon16);

        horizontalLayout_3->addWidget(menuButton);

        minButton = new QToolButton(layoutWidget2);
        minButton->setObjectName(QStringLiteral("minButton"));
        minButton->setMinimumSize(QSize(30, 30));
        minButton->setMaximumSize(QSize(30, 30));
        minButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/images/min.png"), QSize(), QIcon::Normal, QIcon::Off);
        minButton->setIcon(icon17);

        horizontalLayout_3->addWidget(minButton);

        maxButton = new QToolButton(layoutWidget2);
        maxButton->setObjectName(QStringLiteral("maxButton"));
        maxButton->setMinimumSize(QSize(30, 30));
        maxButton->setMaximumSize(QSize(30, 30));
        maxButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/images/max.png"), QSize(), QIcon::Normal, QIcon::Off);
        maxButton->setIcon(icon18);

        horizontalLayout_3->addWidget(maxButton);

        closeButton = new QToolButton(layoutWidget2);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setMinimumSize(QSize(30, 30));
        closeButton->setMaximumSize(QSize(30, 30));
        closeButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(50, 50, 50,255);}"));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon19);

        horizontalLayout_3->addWidget(closeButton);

        userTableWidget = new QTableWidget(page);
        if (userTableWidget->columnCount() < 3)
            userTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setBackground(QColor(0, 0, 0));
        userTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        userTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        userTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        userTableWidget->setObjectName(QStringLiteral("userTableWidget"));
        userTableWidget->setGeometry(QRect(496, 85, 255, 380));
        userTableWidget->setMinimumSize(QSize(255, 380));
        userTableWidget->setMaximumSize(QSize(255, 380));
        QFont font4;
        font4.setPointSize(8);
        userTableWidget->setFont(font4);
        userTableWidget->setStyleSheet(QStringLiteral("QTableWidget { background-color: rgb(255, 132, 139,0); border-radius: 3px; color: rgb(0,0,0); }"));
        userTableWidget->setAlternatingRowColors(false);
        userTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        userTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        userTableWidget->setShowGrid(false);
        userTableWidget->setGridStyle(Qt::SolidLine);
        userTableWidget->horizontalHeader()->setVisible(false);
        userTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        userTableWidget->horizontalHeader()->setDefaultSectionSize(83);
        userTableWidget->horizontalHeader()->setHighlightSections(false);
        userTableWidget->horizontalHeader()->setMinimumSectionSize(83);
        userTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        userTableWidget->horizontalHeader()->setStretchLastSection(false);
        userTableWidget->verticalHeader()->setVisible(false);
        userTableWidget->verticalHeader()->setHighlightSections(false);
        userTableWidget->verticalHeader()->setMinimumSectionSize(30);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        retranslateUi(ClientWin);

        sizeComboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(ClientWin);
    } // setupUi

    void retranslateUi(QWidget *ClientWin)
    {
        ClientWin->setWindowTitle(QApplication::translate("ClientWin", "QQ", 0));
        sendButton->setText(QApplication::translate("ClientWin", "\345\217\221\351\200\201", 0));
        exitButton->setText(QApplication::translate("ClientWin", "\345\205\263\351\227\255", 0));
        sizeComboBox->clear();
        sizeComboBox->insertItems(0, QStringList()
         << QApplication::translate("ClientWin", "9", 0)
         << QApplication::translate("ClientWin", "10", 0)
         << QApplication::translate("ClientWin", "11", 0)
         << QApplication::translate("ClientWin", "12", 0)
         << QApplication::translate("ClientWin", "13", 0)
         << QApplication::translate("ClientWin", "14", 0)
         << QApplication::translate("ClientWin", "15", 0)
         << QApplication::translate("ClientWin", "16", 0)
         << QApplication::translate("ClientWin", "17", 0)
         << QApplication::translate("ClientWin", "18", 0)
         << QApplication::translate("ClientWin", "19", 0)
         << QApplication::translate("ClientWin", "20", 0)
         << QApplication::translate("ClientWin", "21", 0)
         << QApplication::translate("ClientWin", "22", 0)
        );
#ifndef QT_NO_TOOLTIP
        boldToolButton->setToolTip(QApplication::translate("ClientWin", "\345\212\240\347\262\227", 0));
#endif // QT_NO_TOOLTIP
        boldToolButton->setText(QApplication::translate("ClientWin", "...", 0));
#ifndef QT_NO_TOOLTIP
        italicToolButton->setToolTip(QApplication::translate("ClientWin", "\345\200\276\346\226\234", 0));
#endif // QT_NO_TOOLTIP
        italicToolButton->setText(QApplication::translate("ClientWin", "...", 0));
#ifndef QT_NO_TOOLTIP
        underlineToolButton->setToolTip(QApplication::translate("ClientWin", "\344\270\213\345\210\222\347\272\277", 0));
#endif // QT_NO_TOOLTIP
        underlineToolButton->setText(QApplication::translate("ClientWin", "...", 0));
#ifndef QT_NO_TOOLTIP
        colorToolButton->setToolTip(QApplication::translate("ClientWin", "\346\233\264\346\224\271\345\255\227\344\275\223\351\242\234\350\211\262", 0));
#endif // QT_NO_TOOLTIP
        colorToolButton->setText(QApplication::translate("ClientWin", "...", 0));
#ifndef QT_NO_TOOLTIP
        sendToolButton->setToolTip(QApplication::translate("ClientWin", "\344\274\240\350\276\223\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        sendToolButton->setText(QApplication::translate("ClientWin", "...", 0));
#ifndef QT_NO_TOOLTIP
        saveToolButton->setToolTip(QApplication::translate("ClientWin", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", 0));
#endif // QT_NO_TOOLTIP
        saveToolButton->setText(QApplication::translate("ClientWin", "...", 0));
#ifndef QT_NO_TOOLTIP
        clearToolButton->setToolTip(QApplication::translate("ClientWin", "\346\270\205\351\231\244\350\201\212\345\244\251\350\256\260\345\275\225", 0));
#endif // QT_NO_TOOLTIP
        clearToolButton->setText(QApplication::translate("ClientWin", "...", 0));
        toolButton_8->setText(QApplication::translate("ClientWin", "...", 0));
        label->setText(QApplication::translate("ClientWin", "Nobody knows qq better than me!", 0));
        label_2->setText(QApplication::translate("ClientWin", "NULL", 0));
#ifndef QT_NO_TOOLTIP
        toolButton->setToolTip(QApplication::translate("ClientWin", "\345\217\221\350\265\267\350\257\255\351\237\263\351\200\232\350\257\235", 0));
#endif // QT_NO_TOOLTIP
        toolButton->setText(QApplication::translate("ClientWin", "...", 0));
#ifndef QT_NO_TOOLTIP
        toolButton_2->setToolTip(QApplication::translate("ClientWin", "\345\217\221\350\265\267\350\247\206\351\242\221\351\200\232\350\257\235", 0));
#endif // QT_NO_TOOLTIP
        toolButton_2->setText(QApplication::translate("ClientWin", "...", 0));
#ifndef QT_NO_TOOLTIP
        toolButton_3->setToolTip(QApplication::translate("ClientWin", "\350\277\234\347\250\213\346\274\224\347\244\272", 0));
#endif // QT_NO_TOOLTIP
        toolButton_3->setText(QApplication::translate("ClientWin", "...", 0));
#ifndef QT_NO_TOOLTIP
        toolButton_4->setToolTip(QApplication::translate("ClientWin", "\344\274\240\351\200\201\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        toolButton_4->setText(QApplication::translate("ClientWin", "...", 0));
#ifndef QT_NO_TOOLTIP
        toolButton_5->setToolTip(QApplication::translate("ClientWin", "\350\277\234\347\250\213\346\241\214\351\235\242", 0));
#endif // QT_NO_TOOLTIP
        toolButton_5->setText(QApplication::translate("ClientWin", "...", 0));
#ifndef QT_NO_TOOLTIP
        createGroup->setToolTip(QApplication::translate("ClientWin", "\345\217\221\350\265\267\345\244\232\344\272\272\350\201\212\345\244\251", 0));
#endif // QT_NO_TOOLTIP
        createGroup->setText(QApplication::translate("ClientWin", "...", 0));
#ifndef QT_NO_TOOLTIP
        toolButton_7->setToolTip(QApplication::translate("ClientWin", "\345\272\224\347\224\250", 0));
#endif // QT_NO_TOOLTIP
        toolButton_7->setText(QApplication::translate("ClientWin", "...", 0));
        pushButton->setText(QString());
        userNumLabel->setText(QApplication::translate("ClientWin", "\345\234\250\347\272\277\347\224\250\346\210\267\357\274\2320\344\272\272", 0));
#ifndef QT_NO_TOOLTIP
        menuButton->setToolTip(QApplication::translate("ClientWin", "\347\232\256\350\202\244", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        menuButton->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        menuButton->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        menuButton->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        menuButton->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        menuButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        minButton->setToolTip(QApplication::translate("ClientWin", "\346\234\200\345\260\217\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        minButton->setText(QApplication::translate("ClientWin", "...", 0));
#ifndef QT_NO_TOOLTIP
        maxButton->setToolTip(QApplication::translate("ClientWin", "\346\234\200\345\244\247\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        maxButton->setText(QApplication::translate("ClientWin", "...", 0));
#ifndef QT_NO_TOOLTIP
        closeButton->setToolTip(QApplication::translate("ClientWin", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        closeButton->setText(QApplication::translate("ClientWin", "...", 0));
        QTableWidgetItem *___qtablewidgetitem = userTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ClientWin", "\347\224\250\346\210\267\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem1 = userTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ClientWin", "\344\270\273\346\234\272\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem2 = userTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ClientWin", "IP\345\234\260\345\235\200", 0));
    } // retranslateUi

};

namespace Ui {
    class ClientWin: public Ui_ClientWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIN_H
