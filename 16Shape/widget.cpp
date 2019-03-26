#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>
int length = 0;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::WindowStaysOnTopHint);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    setAttribute(Qt::WA_TranslucentBackground);


    this->setFixedSize(70,60);
    this->startTimer(15);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(0,0,QPixmap(":/Image/2.png"));
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        close();
    }else if(event->button() == Qt::LeftButton)
    {
        //求坐标差值
        p = event->globalPos() - this->frameGeometry().topLeft();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - p);
        QPoint pTemp= event->globalPos() - p;
        length = pTemp.x();
    }
}

void Widget::timerEvent(QTimerEvent *event)
{

    int totalWidth = QApplication::desktop()->width();
    if(length >= totalWidth)
    {
        length = -this->width();
    }
    move(QPoint(length++,this->frameGeometry().topLeft().y()));
}
