#include "logger.h"

logger& logger::instance(){
    qRegisterMetaType<logger::LogLevel>("LogLevel");
    qRegisterMetaType<logger::LogLevel>("LogTarget");
    static logger s_instance;
    return s_instance;
}

logger::logger(QObject *parent)
    : QObject{parent}
{}

void logger::logServer(const QString &msg){
    emit logger::instance().newLog(msg, logger::INFO, logger::SERVER);
}

void logger::logServer(const QString &msg, const LogLevel level){
    emit logger::instance().newLog(msg, level, logger::SERVER);
}


void logger::logClient(const QString &msg){
    emit logger::instance().newLog(msg, logger::INFO, logger::CLIENT);
}

void logger::logClient(const QString &msg, const LogLevel level){
    emit logger::instance().newLog(msg, level, logger::CLIENT);
}
