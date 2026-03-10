#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "logger.h"
#include "server.h"
#include "client.h"
#include "serverudp.h"
#include "server_plex.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_server_start_button_clicked();

    void on_client_send_button_clicked();

    void on_pushButton_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_clicked();

private:
    Ui::Widget *ui;

    Server* mainServer = nullptr;
    Server_plex* mainServerPlex = nullptr;
    ServerUDP* mainServerUDP = nullptr;
    Client* mainClient = nullptr;

    void handleLog(const QString &msg, logger::LogLevel level, logger::LogTarget target);
};
#endif // WIDGET_H
