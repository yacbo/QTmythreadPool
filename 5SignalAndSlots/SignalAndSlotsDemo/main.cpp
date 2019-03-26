#include <QCoreApplication>
#include "a.h"
#include "b.h"
#include <QThread>

class T:public QThread
{
    public:
        void run(){
            PA->emitSignalA();
        }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //A aa;
    //B bb;
    QObject::connect(PA, &A::signalA, PB, &B::B_slot);
    //QObject::disconnect(PA,SIGNAL(signalA()),PB,SLOT(B_slot()));
    //PA->emitSignalA();
    T t;
    t.start();

    return a.exec();
}
