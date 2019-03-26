#ifndef B_H
#define B_H
#include <QDebug>
#include <QObject>

class B:public QObject
{
    Q_OBJECT
public :
    static B* instance()
    {
        static B b;
        return &b;
    }
public slots:
    void B_slot()
    {
        qDebug()<<"B_slot is called."<<"\n";
    }
};

#define PB (B::instance())
#endif // B_H
