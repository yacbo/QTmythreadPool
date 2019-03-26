#include "widget.h"
#include "ui_widget.h"
#include  <QFileDialog>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("服务器端口为:8888");

    ui->buttonFile->setEnabled(true);
    ui->buttonSend->setEnabled(false);
    //监听套接字
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,8888);

    connect(tcpServer,&QTcpServer::newConnection,[=]()
    {
        //取出建立好连接的套接字
        tcpSocket = tcpServer->nextPendingConnection();
        //获取对方的ip和端口
        QString ip = tcpSocket->peerAddress().toString();
        quint16 port = tcpSocket->peerPort();

        QString str = QString("[%1:%2]").arg(ip).arg(port);
        ui->textEdit->setText(str);   //显示到编辑区

        ui->buttonFile->setEnabled(true);
        ui->buttonSend->setEnabled(false);
    });

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,[=]()
    {
        timer->stop();  //关定时器
        sendData();//发送文件
    });
}

Widget::~Widget()
{
    delete ui;
}

//选择文件的按钮
void Widget::on_buttonFile_clicked()
{
  QString filePath = QFileDialog::getOpenFileName(this,"open","../");
  if(filePath.isEmpty() == false)   //如果文件路径有效
  {
      fileName.clear();
      fileSize = 0;

      //获取文件信息
      QFileInfo info(filePath);
      fileName = info.fileName();  //获取文件名字
      fileSize = info.size();  //获取文件大小

      sendSize = 0;  //发送文件的大小
      //只读方式打开文件
      //指定文件的名字
      file.setFileName(filePath);

      //打开文件
      bool isOk = file.open(QIODevice::ReadOnly);
      if(false == isOk)
      {
          qDebug() << "只读方式打开文件失败";
      }
      //提示打开文件的路径
      ui->textEdit->append(filePath);

      ui->buttonFile->setEnabled(false);
      ui->buttonSend->setEnabled(true);
  }
  else
  {
      qDebug()<<"选择文件路径出错";
  }
}


void Widget::on_buttonSend_clicked()
{
    //光发送文件头信息 文件名##文件大小
    QString head = QString("%1##%2").arg(fileName).arg(fileSize);
    qint64 len = tcpSocket->write(head.toUtf8());
    if(len > 0)   //头部信息发送成功
    {
        //发送真正的文件信息
        //防止TCP黏包文件
        //需要通过定时器延时20ms
        timer->start(20);
    }
    else
    {
        qDebug() << "头部信息发送失败";
        file.close();
        ui->buttonFile->setEnabled(true);
        ui->buttonSend->setEnabled(false);
    }
}

void Widget::sendData()
{
    qint64 len = 0;
    do
    {
        //每次发送数据的大小
        char buf[4*1024] = {0};
        len = 0;
        //往文件中读数据
        len = file.read(buf,sizeof(buf));
        //发送数据,读多少，发多少
        len = tcpSocket->write(buf,len);
        //发送的数据需要累加
        sendSize += len;

    }while(len > 0);

    if(sendSize == fileSize)
    {
        ui->textEdit->append("文件发送完毕");
        file.close();

        //客户端端口
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
    }
}
