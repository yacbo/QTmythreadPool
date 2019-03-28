#include <QCoreApplication>
#include <QProcess>
#include<windows.h>
#include <iostream>
#include <thread>

/*控制台应用中打开控制端应用 控制台窗口合并*/


void startProcess()
{
    QString path = QCoreApplication::applicationDirPath();
    QString filepath = path + QString::fromStdString("/9QtMyDaemon_widget.exe");
    QStringList arguments;
    arguments<<"887";

    QProcess process;
    process.startDetached(filepath,arguments);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::thread th1(startProcess);
    th1.detach();

    static int i;
    while(1)
    {
        Sleep(2000);
        std::cout<<std::to_string(i++)<<"..."<<std::endl;
    }

    return a.exec();
}
