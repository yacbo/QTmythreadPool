#include "clientwidget.h"
#include "ui_clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    tcpSocket = NULL;
    //分配空间指定父对象
    tcpSocket = new QTcpSocket(this);
}

ClientWidget::~ClientWidget()
{
    delete ui;
}
