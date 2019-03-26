#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer> //监听套接字
#include <QTcpSocket> //通信套接字
#include <QFile>
#include <QFileInfo>
#include <QTimer>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void sendData();  //发送文件信息

private slots:
    void on_buttonFile_clicked();
    void on_buttonSend_clicked();

private:
    Ui::Widget *ui;

    QTcpServer *tcpServer;  //监听套接字
    QTcpSocket *tcpSocket;  //通信套接字

    QFile file;  //文件对象
    QString fileName; //文件名称
    qint64 fileSize;  //文件大小
    qint64 sendSize;  //已经发送文件的大小
    QTimer *timer;  //定时器

};

#endif // WIDGET_H
