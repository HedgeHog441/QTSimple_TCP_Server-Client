#include "serverudp.h"

ServerUDP::ServerUDP(int p) : port(p), listener(-1) {}

ServerUDP::~ServerUDP(){
    stop();

    if(main_thread.joinable()){
        main_thread.join();
    }

    logger::logServer("Сервер UDP остановлен", logger::OK);
}

void ServerUDP::stop(){
    is_running = false;
    if(listener != -1) {
        shutdown(listener, SHUT_RDWR);
        close(listener);
        listener = -1;
    }
}

void ServerUDP::start(){

    if(is_running){
        logger::logServer("Server is already started", logger::WARNING);
        return;
    }

    is_running = true;

    main_thread = std::thread(&ServerUDP::run, this);
    //main_thread.detach();
}

void ServerUDP::run(){

    listener = socket(AF_INET, SOCK_DGRAM, 0); // Слушающий порт
    if(listener < 0){
        logger::logServer("Socket failed", logger::ERROR);
        return;
    }


    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if((bind(listener, (struct sockaddr*)&addr, sizeof(addr)))< 0){
        logger::logServer("Bind failed", logger::ERROR);
        return;
    }

    is_running = true;

    logger::logServer(QString("Сервер UDP доступен и слушает порт: %1").arg(port), logger::OK);

    char buf[1024];
    sockaddr_in client_addr{};
    socklen_t client_len = sizeof(client_addr);

    while(is_running){

        int N = recvfrom(listener, buf, 1024, 0, (struct sockaddr*)&client_addr, &client_len);

        if(!is_running) break;

        if(N < 0){
            if(errno == EINTR) continue;

            logger::logServer("UDP recvfrom failed", logger::ERROR);
            continue;
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);

        sendto(listener, buf, N, 0, (struct sockaddr*)&client_addr, client_len);

        QString res = QString::fromStdString(buf);
        QString res_ = " : ";
        res_ = client_ip + res_ + res;

        logger::logServer(res_, logger::INFO); // Инфа

    }
}
