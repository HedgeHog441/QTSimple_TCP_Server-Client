#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>

class logger : public QObject
{
    Q_OBJECT
public:

    enum LogLevel {INFO, OK, WARNING, ERROR};
    enum LogTarget {SERVER, CLIENT, NONE};

    static logger& instance(); // Синглтон

    //static void log(const QString &msg, logger::LogLevel level, logger::LogTarget);

    static void logServer(const QString &msg);
    static void logServer(const QString &msg, logger::LogLevel level);

    static void logClient(const QString &msg);
    static void logClient(const QString &msg, logger::LogLevel level);

    logger(const logger&) = delete;
    logger& operator=(const logger&) = delete; // Запираем нафиг синглтон

signals:

    void newLog(const QString &msg, LogLevel level = INFO, LogTarget target = NONE); // Сигнал о том, что выводится новый лог


private:

    explicit logger(QObject *parent = nullptr);

};

#endif // LOGGER_H
