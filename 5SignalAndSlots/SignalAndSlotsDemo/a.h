#ifndef A_H
#define A_H
#include <QObject>

class A :public QObject
{
    Q_OBJECT
public :
    static A* instance()
    {
        static A a;
        return &a;
    }
public:
    void emitSignalA(){
       emit signalA();
    }
signals:
    void signalA();
};

#define PA (A::instance())
#endif // A_H
