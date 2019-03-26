#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_Timer = new QTimer(this);
    connect(m_Timer,&QTimer::timeout,
                [=]()
                {
                    static int ii = 0;
                    ii++;
                    ui->lcdNumber->display(ii);
                }
            );


     m_time_int = this->startTimer(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonStart_clicked()
{
    //启动定时器
    //时间间隔为100
    //每隔100ms,定时器myTimer自动触发 timeout()
    if(m_Timer->isActive() == false)
    {
        m_Timer->start(100);
    }
}

void Widget::on_buttonStop_clicked()
{
    if(m_Timer->isActive() == true)
    {
        m_Timer->stop();
    }
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_time_int)
    {
        static int i = 0;
        i++;
        ui->lcdNumber->display(i);
    }
}
