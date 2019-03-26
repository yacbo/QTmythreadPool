#ifndef MYTIMER_H
#define MYTIMER_H

#include <QObject>
#include "threadsafe_queue.h"
#include<QTimer>

extern MyQueueNameSpace::threadsafe_queue<std::string> qe;
//class QTimer;
class MyTimer : public QObject
{
    Q_OBJECT

public:
    explicit MyTimer(QObject* parent = NULL);
    ~MyTimer();
public slots:
    void handle_timeout();  //超时处理函数
private:
    QTimer *m_pTimer;
};

#endif // MYTIMER_H
