#ifndef SERVER_H
#define SERVER_H

#include <mutex>
#include <thread>
#include <netinet/in.h>
#include <unistd.h>
#include <atomic>
#include <map>
#include "logger.h"

class Server
{
public:
    explicit Server(int port);
    ~Server();

    void start();
    void stop();

    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;

private:

    int listener,
        port;

    std::mutex mtx;
    std::thread main_thread;

    std::map<int, std::thread> fds_thr;

    std::atomic<bool> is_running = false;

    void run();

    void handleConnection(int client_socket);

};

#endif // SERVER_H
