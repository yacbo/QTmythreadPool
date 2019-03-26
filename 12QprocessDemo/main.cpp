#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QTime>
//#include <Winbase.h>
#include <windows.h>

//Qt中的阻塞延时实现方法
void Delay_MSec_Suspend(unsigned int msec)
{

    QTime _Timer = QTime::currentTime();

    QTime _NowTimer;
    do{
        _NowTimer = QTime::currentTime();
    }while ( _Timer.msecsTo( _NowTimer ) <= msec );
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString dirPath = QCoreApplication::applicationDirPath();
    qDebug()<<dirPath;

    QString c = "taskkill /im notepad.exe /f";  //关闭后台中notepad.exe进程
    int pInt = QProcess::execute(c);    //阻塞式运行,成功返回0,失败返回128
    qDebug()<<"pInt:"<<pInt;

    //    QString filePath = QCoreApplication::applicationFilePath();
    //    qDebug()<<filePath;

    qDebug()<<"on the way";

    QProcess *p = new QProcess();
    QString program = "F:/工作目录/C#工作/Z软件/socket_soft/sokit-1.0-win32-chs/sokit.exe";
    //QString program = "E:/QtProject/QTmythreadPool/12QprocessDemo/debug/WcfRelease/wCfTest.exe";

    #if defined (_WIN32)
        WinExec("E:/QtProject/QTmythreadPool/12QprocessDemo/debug/WcfRelease/wCfTest.exe", SW_NORMAL);
    #else //linux
    #endif

    //    bool flag = p->startDetached(program);   //分离式  外部程序启动后,当主程序退出时并不退出,而是继续执行。
    //    if(flag)
    //    {
    //        qDebug()<<"Sucessed";
    //    }
    //    else
    //    {
    //        qDebug()<<"Failed";
    //    }
    p->close();
    p->start(program);   //一体式  外部程序启动后,将随主程序的退出而退出。
    bool ff = p->waitForStarted();   //阻塞，直到外部程序启动产生返回值
    qDebug()<<"ff:"<<ff;
    Delay_MSec_Suspend(8000);  //阻塞式延时
    qDebug()<<"......";
    p->close();
    //QString c = "taskkill /im sokit.exe /f";
    //p->execute(c);
    //p->kill();

    Delay_MSec_Suspend(8000);
    p->start(program);
    Delay_MSec_Suspend(8000);
    //qDebug()<<"......";
    p->close();
    if(p != nullptr)
    {
        delete p;
        p = 0;
    }
    return a.exec();
}
