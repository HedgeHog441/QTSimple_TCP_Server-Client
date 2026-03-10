#include "client.h"

Client::Client(std::string ip__, int port__) : ip(ip__), port(port__) {}


Client::Client() : ip("\0\0"), port(-1){}


Client::~Client()
{
    disconnect();
}

bool isValidIP(const std::string& ip){
    sockaddr_in sa;

    return inet_pton(AF_INET, ip.c_str(), &(sa.sin_addr) ) == 1;
}

void Client::start(QString input__){
    if(is_connected){
        logger::logClient("Client already connected", logger::WARNING);
        return;
    }

    QStringList ip_port = input__.split(':');

    if(ip_port.size() != 2){
        logger::logClient("Invalid IP/PORT input", logger::WARNING);
        return;
    }

    if(!isValidIP(ip_port[0].toStdString())){
        logger::logClient("Invalid IP input", logger::WARNING);
        return;
    }

    ip = ip_port[0].toStdString();
    port = ip_port[1].toInt();

    connect__();
}

void Client::connect__(){
    if(is_connected){
        logger::logClient("Client already connected", logger::WARNING);
        return;
    }
    //is_connected = true;

    main_thread = std::thread(&Client::run, this);
    main_thread.detach();
}

void Client::disconnect(){

    sendMessage(QString('\0'));
    is_connected = false;

}

void Client::run(){
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0){
        logger::logClient("Socket failed", logger::ERROR);
        return;
    }

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);


    if(inet_pton(AF_INET, ip.c_str(), &server_addr.sin_addr ) <= 0){
        close(sock_fd);
        sock_fd = -1;
        logger::logClient("IP failed", logger::ERROR);
        return;
    }


    if(connect(sock_fd, (struct sockaddr*)&server_addr,sizeof(server_addr)) < 0){
        close(sock_fd);
        sock_fd = -1;
        logger::logClient("Connect failed", logger::ERROR);
        return;
    }

    is_connected = true;

    logger::logClient("Подключение к серверу успешно!", logger::OK);

    char buf[1024];

    while(true){

        //send(sock_fd, buf, 1024, 0);

        int bytes_read = recv(sock_fd, buf, 1024, 0);

        if(buf[0] == '\0' or !is_connected){
            logger::logClient("Отключение от сервера", logger::OK);
            break;
        }

        buf[bytes_read] = '\0';

        QString res = QString::fromStdString(buf);
        QString res_ = QString("Ответ : ");
        res_ = res_ + res;

        logger::logClient(res_, logger::INFO); // Инфа
    }
}

int Client::sendMessage(const QString& msg){

    if(!is_connected || sock_fd < 0){
        logger::logClient("Server error", logger::ERROR);
        return -1;
    }

    int bytes_send = send(sock_fd, msg.toStdString().c_str(), msg.size(), MSG_NOSIGNAL);

    if(bytes_send < 0){
        is_connected = false;
        logger::logClient("Send error", logger::ERROR);
    }

    //msg = ("Сообщение: " + msg);
    //logger::logClient("Сообщение: ", logger::ERROR);
    return bytes_send;
}

void Client::sendUDPMessage(const QString& msg){
    if(port_udp == -1){
        logger::logClient("Invalid address", logger::WARNING);
        return;
    }

    struct sockaddr_in addr_ = {AF_INET, htons(port_udp), inet_addr(ip_udp.c_str())};

    sendto(sock_udp, msg.toStdString().c_str(), msg.size(), 0,(sockaddr*)&addr_, sizeof(addr_));

    QString res_ = QString::fromStdString(ip_udp);
    res_ = "Отправлено к " + res_ + ':' + QString::number(port_udp) + " : " + msg;

    logger::logClient(res_, logger::INFO); // Инфа
}

void Client::bindUDP(const QString& input__){

    QStringList ip_port = input__.split(':');

    if(ip_port.size() != 2){
        logger::logClient("Invalid IP/PORT input", logger::WARNING);
        return;
    }

    if(!isValidIP(ip_port[0].toStdString())){
        logger::logClient("Invalid IP input", logger::WARNING);
        return;
    }

    ip_udp = ip_port[0].toStdString();
    port_udp = ip_port[1].toInt();

    sock_udp = socket(AF_INET, SOCK_DGRAM, 0);

    QString res_ = ip_port[0];
    res_ = "Адрес посылок UDP задан - " + res_ + ':' + ip_port[1];

    logger::logClient(res_, logger::OK); // Инфа
    //struct sockaddr_in addr_ = {AF_INET, htons(port_udp), inet_addr(ip_udp)};

}
