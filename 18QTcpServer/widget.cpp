#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    tcpServer = NULL;
    tcpSocket = NULL;
    ui->setupUi(this);
    this->setWindowTitle("TcpServer Port:8888");
    //监听套接字，指定父对象自动回收空间
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,8888);

    connect(tcpServer,&QTcpServer::newConnection,[=]()
    {
        //取出建立好链接的套接字
        tcpSocket = tcpServer->nextPendingConnection();
        //获取对方ip
        QString ip = tcpSocket->peerAddress().toString();
        qint16 port = tcpSocket->peerPort();
        QString temp = QString("[%1:%2]:成功连接").arg(ip).arg(port);
        ui->textEditRead->setText(temp);

        connect(tcpSocket,&QTcpSocket::readyRead,[=]()
        {
            //从通信套接字中取出内容
            QByteArray array = tcpSocket->readAll();
            ui->textEditRead->append(array);
        });
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonsend_clicked()
{
    if(tcpSocket == NULL)return;

    QString str = ui->textEditWrite->toPlainText();

    tcpSocket->write(str.toUtf8().data());

}

void Widget::on_close_clicked()
{
    if(tcpSocket == NULL)return;
    //主动和客户端端口连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket = NULL;
}
