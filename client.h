#ifndef CLIENT_H
#define CLIENT_H

#include <mutex>
#include <thread>
#include <netinet/in.h>
#include <unistd.h>
#include <atomic>
#include <vector>
#include <string>
#include <arpa/inet.h>
#include "logger.h"

class Client
{
public:
    explicit Client(std::string ip__, int port__);
    explicit Client();
    ~Client();


    void start(QString input_);
    void disconnect();

    int sendMessage(const QString& input_);

    void sendUDPMessage(const QString& input_);
    void bindUDP(const QString& input_);

private:
    void connect__();
    void run();

    bool isValipIP(const std::string& ip);

    std::string ip, ip_udp;

    int port,
        port_udp = -1;

    int sock_fd = -1,
        sock_udp = -1;

    std::atomic<bool> is_connected = false;

    std::thread main_thread;
};

#endif // CLIENT_H
