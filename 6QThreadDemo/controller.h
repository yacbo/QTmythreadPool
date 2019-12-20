#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QThread>
#include <QDebug>

//controller用于启动线程和处理线程执行结果
class Controller:public QObject
{
    Q_OBJECT
    QThread thread;
public:
    Controller(QObject *parent = nullptr);
    ~Controller();

public slots:
    void handleResults(const int rslt)//处理线程执行的结果
    {
        qDebug()<<"receive the resultReady signal----";
        qDebug()<<"current thread ID:"<<QThread::currentThreadId()<<'\n';
        qDebug()<<"the last result is:"<<rslt;
    }
signals:
    void operate(const int);//发送信号触发线程
};

#endif // CONTROLLER_H
