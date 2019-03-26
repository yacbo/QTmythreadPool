#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QDate>

#if defined (_WIN32)
#include <stdio.h>
#include <windows.h>
#include <TlHelp32.h>
#include <stdlib.h>
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )	//隐藏运行的控制台窗口
#else //linux
    //***
#endif

void readProcessByLine() {
    qDebug()<<"readProcessByLine";
    qDebug()<<"----------------------";
    bool ret;
    QProcess process(0);
    /*
     * cmd /c 的命令执行完后会关闭窗口
     * cmd /k 的命令执行完后不会关闭窗口
     *
     * aa && bb 就是执行aa，成功后再执行bb
     * aa || bb 先执行aa，若执行成功则不再执行bb，若失败则执行bb
     * a  &  b  表示执行a再执行b，而无论a是否成功
     */
    process.start("cmd", QStringList()<<"/k"<<"ping 127.0.0.1"<<"&"<<"exit", QIODevice::ReadWrite);
//    process.setProgram("cmd");
//    process.setArguments(QStringList()<<"/k"<<"ping 127.0.0.1"<<"&"<<"exit");
//    process.start(QIODevice::ReadWrite);
    ret = process.waitForStarted();
    qDebug()<<"waitForStarted"<<ret;
    qint64 maxSize = 512;
    char buffer[maxSize];
    qint64 len;
    while(true) {
        /*
         * 一个waitForReadyRead信号可能输出的是多行
         */
        ret = process.waitForReadyRead();
        qDebug()<<"waitForReadyRead"<<ret;
        if(!ret) {
            break;
        }
        while(true) {
            len = process.readLine(buffer, maxSize);
            qDebug()<<"buffer len"<<len;
            /*
             * 因为每一行至少还有回车换行符，因此读到0，说明waitForReadyRead超时返回false
             */
            if(len <= 0) {
                break;
            }
            QString str = QString::fromLocal8Bit(buffer);
            qDebug()<<"qstring len"<<str.length();
            qDebug()<<str;
            qDebug()<<"";
        }
    }
    process.write("exit\r\n");
    ret = process.waitForFinished();
    qDebug()<<"waitForFinished"<<ret;
    process.close();
    qDebug()<<"";
    qDebug()<<"======================";
}

void readProcessAllOnce(bool processAutoExit) {
    qDebug()<<"readProcessAllOnce, processAutoExit ="<<processAutoExit;
    qDebug()<<"----------------------";
    bool ret;
    QProcess process;
    QString command;
    if(processAutoExit) {
        command = "cmd /c ping 127.0.0.1";
    } else {
        command = "cmd /k ping 127.0.0.1";
    }
    process.start(command);
    /*
     * bool QProcess::waitForStarted(int msecs = 30000)
     */
    ret = process.waitForStarted();
    qDebug()<<"waitForStarted"<<ret;
    qDebug()<<QDateTime::currentDateTime();
    /*
     * 如果打开的不是自动关闭的进程，那么这里最多可能会等待30秒
     * bool QProcess::waitForFinished(int msecs = 30000)
     */
    ret = process.waitForFinished();
    qDebug()<<QDateTime::currentDateTime();
    qDebug()<<"waitForFinished"<<ret;
    QByteArray byteArray = process.readAllStandardOutput();
    QString str = QString::fromLocal8Bit(byteArray);
    qDebug()<<str;
    process.close();
    qDebug()<<"";
    qDebug()<<"======================";
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QString qStr = "notepad.exe";
    QString c = "taskkill /im notepad.exe /f";
    int pInt = QProcess::execute(c);   //关闭后台notepad进程,阻塞式
    qDebug()<<"pInt:"<<pInt;
//    qDebug()<<"......";
//    qDebug()<<"......";
//    qDebug()<<"......";
//    QProcess process;
//    //process.start("Notepad.exe");
//    process.start("cmd",QStringList()<<"/c"<<"ping 127.0.0.1",QIODevice::ReadWrite);
//    readProcessAllOnce(true);
//    readProcessByLine();
    return a.exec();
}

