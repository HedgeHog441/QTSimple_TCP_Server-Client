#include "server_plex.h"

Server_plex::Server_plex(int p) : port(p), listener(-1) {}

Server_plex::~Server_plex(){
    stop();
    //qDebug() << "КЛАССУ Plex ПИЗДА!";

    if(main_thread.joinable()){
        main_thread.join();
    }

    logger::logServer("Сервер Plex остановлен", logger::OK);
}

void Server_plex::start(){

    if(is_running){
        logger::logServer("Server Plex is already started", logger::WARNING);
        return;
    }

    is_running = true;

    main_thread = std::thread(&Server_plex::run, this);
    //main_thread.detach();
}

void Server_plex::stop(){

    is_running = false;

    for(const auto& i : fds){
        if(i.fd != -1){
             close(i.fd);
        }
    }

    fds.clear();
    listener = -1;
}

bool Server_plex::init_listener(){

    listener = socket(AF_INET, SOCK_STREAM, 0); // Слушающий порт
    if(listener < 0){
        logger::logServer("Socket failed", logger::ERROR);
        return false;
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
        return false;
    }


    if((listen(listener, 10)) < 0){
        logger::logServer("Listen failed", logger::ERROR);
        return false;
    }

    return true;
}

void Server_plex::run(){
    if(!init_listener()){
        return;
    }

    pollfd listener_fd;
    listener_fd.fd = listener;
    listener_fd.events = POLLIN;
    fds.push_back(listener_fd);

    logger::logServer(QString("Сервер Plex доступен и слушает порт: %1").arg(port), logger::OK);

    while(is_running){

        int poll_count = poll(fds.data(), fds.size(), 1000);

        if(poll_count < 0){
            if(errno == EINTR) continue;
            break;
        }

        if(poll_count == 0){
            continue;
        }

        for(size_t i = 0; i < fds.size(); i++){
            if(fds[i].revents & POLLIN){

                if(fds[i].fd == listener){ // Событие на серверном (слушающем) сокете

                    int client_socket = accept(listener, nullptr, nullptr);

                    if(client_socket >= 0){

                        fcntl(client_socket, F_SETFL, O_NONBLOCK);

                        pollfd client_fd;
                        client_fd.fd = client_socket;
                        client_fd.events = POLLIN;
                        fds.push_back(client_fd);

                        logger::logServer(QString("Новый клиент. Сокет: %1").arg(client_socket), logger::OK);
                    }
                }
                else{

                    char buf[1024];
                    int bytes_received = recv(fds[i].fd, buf, 1024, 0);

                    if(bytes_received <= 0 or buf[0] == '\0'){

                        close_client(i);
                        i--;
                        break;
                    }

                    buf[bytes_received] = '\0';

                    QString res = QString::fromStdString(buf);
                    QString res_ = QString("Клиент %1 : ").arg(fds[i].fd);
                    res_ = res_ + res;

                    send(fds[i].fd, buf, bytes_received, 0);

                    logger::logServer(res_, logger::INFO); // Инфа
                }
            }
        }

    }
}

void Server_plex::close_client(size_t i){

    int fd = fds[i].fd;

    close(fd);

    fds.erase(fds.begin() + i);

    logger::logServer(QString("Отключение клиента. Сокет: %1").arg(fd), logger::OK);
}
