#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QObject::connect(&logger::instance(), &logger::newLog, this, &Widget::handleLog);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleLog(const QString &msg, logger::LogLevel level, logger::LogTarget target){

    if(target == logger::NONE){
        return;
    }

    QString color = "gray";
    QString prefix = "[INFO]";

    if(level == logger::OK){
        color = "green";
        prefix = "[ OK ]";
    }
    else if(level == logger::WARNING){
        color = "orange";
        prefix = "[WARN]";
    }else if(level == logger::ERROR){
        color = "red";
        prefix = "[ERR ]";
    }

    QString HTML_msg = QString("<font color = %1>%2</font> <font color = gray>%3</font>")
                           .arg(color, prefix, msg);

    if(target == logger::SERVER){
        //ui->LogText->appendHtml(HTML_msg);
        ui->ServerLog->appendHtml(HTML_msg);
    }
    else if(target == logger::CLIENT){
        ui->ClientLog->appendHtml(HTML_msg);
    }
}

void Widget::on_server_start_button_clicked()
{
    //logger::logServer("Писюны...");
    //logger::logClient("Писюнчики....");

    if(ui->checkBox->isChecked()){
        if(mainServerPlex == nullptr){

            int port_in = ui->port_spinBox->value();

            if (!(1023 < port_in and port_in < 65537)){
                logger::logServer("Incorrect Port", logger::WARNING);
                return;
            }

            mainServerPlex = new Server_plex(port_in);

            mainServerPlex->start();
        }
    }
    else if(ui->checkBox_2->isChecked()){
        if(mainServerUDP == nullptr){

            int port_in = ui->port_spinBox->value();

            if (!(1023 < port_in and port_in < 65537)){
                logger::logServer("Incorrect Port", logger::WARNING);
                return;
            }

            mainServerUDP = new ServerUDP(port_in);

            mainServerUDP->start();
        }
        }
    else{
        if(mainServer == nullptr){

            int port_in = ui->port_spinBox->value();

            if (!(1023 < port_in and port_in < 65537)){
                logger::logServer("Incorrect Port", logger::WARNING);
                return;
            }
            mainServer = new Server(port_in);

            mainServer->start();
        }
    }
}

void Widget::on_client_send_button_clicked()
{

    if(mainClient == nullptr){
        mainClient = new Client();
    }

    QString text = ui->client_send_line->text();

    if(text.left(8) == "connect "){
        mainClient->start(text.remove(0, 8));
    }
    else if (text.left(5) == "send "){
        mainClient->sendMessage(text.remove(0, 5));
    }
    else if(text.left(10) == "disconnect"){
        mainClient->disconnect();
    }
    else if(text.left(5) == "bind "){
        mainClient->bindUDP(text.remove(0, 5));
    }
    else if(text.left(5) == "push "){
        mainClient->sendUDPMessage(text.remove(0, 5));
    }

}


void Widget::on_pushButton_clicked() // СТОП!
{
    if(ui->checkBox->isChecked()){
        if(mainServerPlex != nullptr){

            delete(mainServerPlex);
            mainServerPlex = nullptr;
        }
    }
    else if(ui->checkBox_2->isChecked()){
        if(mainServerUDP != nullptr){

            delete(mainServerUDP);
            mainServerUDP = nullptr;
        }
    }
    else{
        if(mainServer != nullptr){

            delete(mainServer);
            mainServer = nullptr;
        }
    }
}


void Widget::on_checkBox_2_clicked()
{
    ui->checkBox->setChecked(0);
}


void Widget::on_checkBox_clicked()
{
    ui->checkBox_2->setChecked(0);
}

