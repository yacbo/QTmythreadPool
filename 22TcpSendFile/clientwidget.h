#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QFile>
#include <QTimer>
namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = 0);
    ~ClientWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ClientWidget *ui;
    QTimer *timer;
    QTcpSocket *tcpSocket;

    QFile file;  //文件对象
    QString fileName; //文件名称
    qint64 fileSize;  //文件大小
    qint64 recvSize;  //已经接受文件的大小

    bool isStart;
};

#endif // CLIENTWIDGET_H
