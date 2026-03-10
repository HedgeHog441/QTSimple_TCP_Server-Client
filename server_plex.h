#ifndef SERVER_PLEX_H
#define SERVER_PLEX_H

#include <mutex>
#include <thread>
#include <netinet/in.h>
#include <unistd.h>
#include <atomic>
#include <poll.h>
#include <vector>
#include <fcntl.h>
#include <QDebug>
#include "logger.h"

class Server_plex
{
public:
    explicit Server_plex(int port);
    ~Server_plex();

    void start();
    void stop();

    Server_plex(const Server_plex&) = delete;
    Server_plex& operator=(const Server_plex&) = delete;

private:
    int listener,
        port;

    std::vector<pollfd> fds; // Сокеты для мониторинга

    std::mutex mtx;
    std::thread main_thread;

    std::atomic<bool> is_running = false;

    void run();

    bool init_listener();

    void close_client(size_t index);

};

#endif // SERVER_PLEX_H
