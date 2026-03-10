#ifndef SERVERUDP_H
#define SERVERUDP_H


#include <thread>
#include <netinet/in.h>
#include <unistd.h>
#include <atomic>
#include <map>
#include <arpa/inet.h>
#include "logger.h"

class ServerUDP
{
public:
    ServerUDP(int p);
    ~ServerUDP();

    void start();
    void stop();

private:

    void run();

    int listener,
        port;

    std::atomic<bool> is_running  = false;
    std::thread main_thread;
};

#endif // SERVERUDP_H
