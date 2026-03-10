#include "server.h"

#include <QDebug>

Server::Server(int p) : port(p), listener(-1) {}

Server::~Server(){
    stop();
    //qDebug() << "КЛАССУ ПИЗДА!";
    if(main_thread.joinable()){
        main_thread.join();
    }
    logger::logServer("Сервер остановлен", logger::OK);
}

void Server::handleConnection(int client_socket){
    char buf[1024];
    while(is_running){

        int bytes_received = recv(client_socket, buf, 1024, 0);

        if(bytes_received <= 0 or buf[0] == '\0' or !is_running){

            //std::lock_guard<std::mutex> lock(mtx);
            logger::logServer(QString("Отключение клиента. Сокет: %1").arg(client_socket), logger::OK);
            break;
        }

        buf[bytes_received] = '\0';

        QString res = QString::fromStdString(buf);
        QString res_ = QString("Клиент %1 : ").arg(client_socket);
        res_ = res_ + res;

        send(client_socket, buf, bytes_received, 0);

        std::lock_guard<std::mutex> lock(mtx);
        logger::logServer(res_, logger::INFO); // Инфа

    }

    close(client_socket);
}

void Server::start(){

    if(is_running){
        logger::logServer("Server is already started", logger::WARNING);
        return;
    }

    is_running = true;

    main_thread = std::thread(&Server::run, this);
    //main_thread.detach();
}

void Server::stop(){
    is_running = false;
    if(listener != -1) {

        shutdown(listener, SHUT_RDWR);
        close(listener);

        listener = -1;
    }
}

void Server::run(){

    listener = socket(AF_INET, SOCK_STREAM, 0); // Слушающий порт
    if(listener < 0){
        logger::logServer("Socket failed", logger::ERROR);
        return;
    }

    int opt = 1;
    if((setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) < 0){
        logger::logServer("Socket reuse", logger::WARNING);
    }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);


    if((bind(listener, (struct sockaddr*)&addr, sizeof(addr)))< 0){
        logger::logServer("Bind failed", logger::ERROR);
        return;
    }


    if((listen(listener, 10)) < 0){
        logger::logServer("Listen failed", logger::ERROR);
        return;
    }

    logger::logServer(QString("Сервер доступен и слушает порт: %1").arg(port), logger::OK);

    while(is_running){
        int client_socket = accept(listener, nullptr, nullptr);

        if(client_socket < 0){
            //qDebug() << errno;
            if(is_running){
                logger::logServer("Accept failed", logger::WARNING);
            }
            continue;
        }

        logger::logServer(QString("Новый клиент. Сокет: %1").arg(client_socket), logger::OK);

        std::thread(&Server::handleConnection, this, client_socket).detach();
    }
}
