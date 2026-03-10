/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTabWidget *tabWidget;
    QWidget *GuideTab;
    QTextBrowser *GUI;
    QWidget *ServerTab;
    QPlainTextEdit *ServerLog;
    QPushButton *server_start_button;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QSpinBox *port_spinBox;
    QCheckBox *checkBox_2;
    QWidget *ClientTab;
    QPlainTextEdit *ClientLog;
    QLineEdit *client_send_line;
    QPushButton *client_send_button;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(450, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setMinimumSize(QSize(450, 500));
        Widget->setMaximumSize(QSize(450, 500));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 431, 481));
        GuideTab = new QWidget();
        GuideTab->setObjectName(QString::fromUtf8("GuideTab"));
        GUI = new QTextBrowser(GuideTab);
        GUI->setObjectName(QString::fromUtf8("GUI"));
        GUI->setGeometry(QRect(20, 10, 391, 421));
        tabWidget->addTab(GuideTab, QString());
        ServerTab = new QWidget();
        ServerTab->setObjectName(QString::fromUtf8("ServerTab"));
        ServerLog = new QPlainTextEdit(ServerTab);
        ServerLog->setObjectName(QString::fromUtf8("ServerLog"));
        ServerLog->setGeometry(QRect(10, 10, 411, 401));
        ServerLog->setReadOnly(true);
        server_start_button = new QPushButton(ServerTab);
        server_start_button->setObjectName(QString::fromUtf8("server_start_button"));
        server_start_button->setGeometry(QRect(10, 420, 87, 21));
        checkBox = new QCheckBox(ServerTab);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(200, 417, 61, 24));
        pushButton = new QPushButton(ServerTab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 420, 87, 21));
        port_spinBox = new QSpinBox(ServerTab);
        port_spinBox->setObjectName(QString::fromUtf8("port_spinBox"));
        port_spinBox->setGeometry(QRect(350, 417, 71, 27));
        port_spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        port_spinBox->setMaximum(99999);
        port_spinBox->setValue(8080);
        checkBox_2 = new QCheckBox(ServerTab);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(270, 417, 92, 24));
        tabWidget->addTab(ServerTab, QString());
        ClientTab = new QWidget();
        ClientTab->setObjectName(QString::fromUtf8("ClientTab"));
        ClientLog = new QPlainTextEdit(ClientTab);
        ClientLog->setObjectName(QString::fromUtf8("ClientLog"));
        ClientLog->setGeometry(QRect(10, 10, 411, 391));
        ClientLog->setReadOnly(true);
        client_send_line = new QLineEdit(ClientTab);
        client_send_line->setObjectName(QString::fromUtf8("client_send_line"));
        client_send_line->setGeometry(QRect(10, 410, 311, 26));
        client_send_button = new QPushButton(ClientTab);
        client_send_button->setObjectName(QString::fromUtf8("client_send_button"));
        client_send_button->setGeometry(QRect(330, 410, 87, 26));
        tabWidget->addTab(ClientTab, QString());

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        GUI->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\236\321\202\320\272\321\200\320\276\320\271\321\202\320\265 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\321\203 <span style=\" font-weight:700;\">&quot;\320\241\320\265\321\200\320\262\320\265\321\200&quot;</span>, \320\265\321\201\320\273\320\270 \321\201\320\276\320\261\320\270\321\200\320\260\320\265\321\202\320\265\321\201\321\214 \320\267\320\260\320\277\321\203\321\201\321\202"
                        "\320\270\321\202\321\214 \321\201\320\265\321\200\320\262\320\265\321\200.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\236\321\202\320\272\321\200\320\276\320\271\321\202\320\265 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\321\203 <span style=\" font-weight:700;\">&quot;\320\232\320\273\320\270\320\265\320\275\321\202&quot;</span>, \320\265\321\201\320\273\320\270 \321\201\320\276\320\261\320\270\321\200\320\260\320\265\321\202\320\265\321\201\321\214 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217 \320\272 \321\201\321\203\321\211\320\265\321\201\321\202\320\262\321\203\321\216\321\211\320\265\320\274\321\203 \321\201\320\265\321\200\320\262\320\265\321\200\321\203.</p>\n"
"<p style=\"-qt-paragraph-typ"
                        "e:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic;\">\320\222\321\213 \320\274\320\276\320\266\320\265\321\202\320\265 \320\276\320\264\320\275\320\276\320\262\321\200\320\265\320\274\320\265\320\275\320\275\320\276 \320\261\321\213\321\202\321\214 \320\270 \321\201\320\265\321\200\320\262\320\265\321\200\320\276\320\274 \320\270 \320\272\320\273\320\270\320\265\320\275\321\202\320\276\320\274.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic;\">\320\242\320\260\320\272\320\266\320\265 \320\262\321\213 \320\274\320\276\320\266\320\265\321\202\320\265 \320\276\320\264\320\275\320\276\320\262\321\200\320\265\320\274\320\265\320\275\320\275\320\276 \320\267\320\260"
                        "\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \320\262\321\201\320\265 3 \321\201\320\265\321\200\320\262\320\265\321\200\320\260. (TCP, TCP-Plex \320\270 UDP)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 <span style=\" font-weight:700;\">\320\241\320\265\321\200\320\262\320\265\321\200\320\260</span>:</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\232\320\275\320\276\320\277\320\272\320\260 &quot;<span style=\" text-decoration: underlin"
                        "e;\">\320\241\321\202\320\260\321\200\321\202</span>&quot; - \320\267\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \321\201\320\265\321\200\320\262\320\265\321\200.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\232\320\275\320\276\320\277\320\272\320\260 &quot;<span style=\" text-decoration: underline;\">\320\241\321\202\320\276\320\277</span>&quot; - \320\276\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \321\201\320\265\321\200\320\262\320\265\321\200.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\223\320\260\320\273\320\276\321\207\320\272\320\260 &quot;<span style=\" text-decoration: underline;\">Plex</span>&quot; - \320\262\320\272\320\273"
                        "\321\216\321\207\320\270\321\202\321\214 \320\274\321\203\320\273\321\214\321\202\320\270\320\277\320\273\320\265\320\272\321\201\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 (\320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260 \320\262\321\201\320\265\321\205 \320\272\320\273\320\270\320\265\320\275\321\202\320\276\320\262 \320\262 \320\276\320\264\320\275\320\276\320\274 \320\277\320\276\321\202\320\276\320\272\320\265. \320\235\320\260\320\264\320\265\320\266\320\275\320\265\320\265)</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\223\320\260\320\273\320\276\321\207\320\272\320\260 &quot;<span style=\" text-decoration: underline;\">UDP</span>&quot; - \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320"
                        "\260\321\202\321\214 \320\277\321\200\320\276\321\202\320\276\320\272\320\276\320\273 UDP \320\262\320\274\320\265\321\201\321\202\320\276 TCP.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\232\320\276\320\274\320\260\320\275\320\264\321\213 <span style=\" font-weight:700;\">\320\232\320\273\320\270\320\265\320\275\321\202\320\260</span>:</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; tex"
                        "t-indent:0px;\">connect [IP:PORT]  </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\272 \321\201\320\265\321\200\320\262\320\265\321\200\321\203 TCP \320\277\320\276 \320\260\320\264\321\200\320\265\321\201\321\203</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic;\">\320\275\320\260\320\277\321\200\320\270\320\274\320\265\321\200 : connect 192.168.0.1:25565</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bot"
                        "tom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">send [msg] </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- \320\276\321\202\320\277\321\200\320\260\320\262\320\272\320\260 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217 \321\201\320\265\321\200\320\262\320\265\321\200\321\203 TCP</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic;\">\320\275\320\260\320\277\321\200\320\270\320\274\320\265\321\200 : send Hello, world!</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" "
                        "margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">disconnect </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- \320\276\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217 \320\276\321\202 \321\201\320\265\321\200\320\262\320\265\321\200\320\260 TCP</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">bind [IP:PORT] - \320\267\320\260\320\264\320\260\321\202\321\214 \320\260\320\264\321\200\320\265\321\201 \320\277\320\276\321\201\321\213\320\273\320\276"
                        "\320\272 \320\264\320\273\321\217 push</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">push [msg] - \320\276\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 UDP \321\201\320\265\321\200\320\262\320\265\321\200\321\203 \320\277\320\276 \320\260\320\264\321\200\320\265\321\201\321\203 *bind*.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic; text-decoration: underline;\">\320\222\320\260\320\266\320\275\320\276!</span><span style=\" font-style:italic;\"> \320\222\321\213 \320\275\320\265 \320\277\320\276\320\273\321\203\321\207\320\270\321\202\320\265 \320\276\321\202\320\262\320"
                        "\265\321\202 \320\275\320\260 \320\262\320\260\321\210\321\203 push \320\277\320\276\321\201\321\213\320\273\320\272\321\203. Push \321\202\320\276\320\273\321\214\320\272\320\276 \320\276\321\202\320\277\321\200\320\260\320\262\320\273\321\217\320\265\321\202 \320\264\320\260\320\275\320\275\321\213\320\265. </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(GuideTab), QCoreApplication::translate("Widget", "\320\230\320\275\321\201\321\202\321\200\321\203\320\272\321\206\320\270\321\217", nullptr));
        server_start_button->setText(QCoreApplication::translate("Widget", "\320\227\320\260\320\277\321\203\321\201\320\272", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "PLEX", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\320\241\321\202\320\276\320\277", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Widget", "UDP", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ServerTab), QCoreApplication::translate("Widget", "\320\241\320\265\321\200\320\262\320\265\321\200", nullptr));
        client_send_button->setText(QCoreApplication::translate("Widget", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ClientTab), QCoreApplication::translate("Widget", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
