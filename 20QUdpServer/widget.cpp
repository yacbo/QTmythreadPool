#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //分配空间，指定父对象
    udpSocket = new QUdpSocket(this);
    //绑定
    //udpSocket->bind(9999);
    udpSocket->bind(QHostAddress::AnyIPv4,9999);

    //加入某个组播  D类地址
    udpSocket->joinMulticastGroup(QHostAddress("192.168.1.100"));

    setWindowTitle(QString("服务器端口:9999"));

    //对方成功发送数据过来
    connect(udpSocket,&QUdpSocket::readyRead,this,&Widget::dealMsg);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::dealMsg()
{
    char buf[1024] = {0};
    QHostAddress cliAddr;
    quint16 port;

    qint64 len = udpSocket->readDatagram(buf,sizeof(buf),&cliAddr,&port);
    if(len > 0)
    {
        QString str = QString("[%1:%2] %3")
                .arg(cliAddr.toString())
                .arg(port)
                .arg(buf);
        ui->textEdit->setText(str);
    }
}

//发送按钮
void Widget::on_buttonSend_clicked()
{
    //获取对方的ip和端口
    QString ip = ui->lineEditIP->text();
    qint16 port = ui->lineEditPort->text().toInt();

    //获取编辑区内容
    QString str = ui->textEdit->toPlainText();

    udpSocket->writeDatagram(str.toUtf8(),QHostAddress(ip),port);
}

void Widget::on_buttonClose_clicked()
{

}
