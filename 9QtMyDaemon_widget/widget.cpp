#include "widget.h"
#include "ui_widget.h"
#include <iostream>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_time_int = this->startTimer(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::SetValue(int value)
{
    m_value = value;
}

int Widget::GetValue()
{
    return m_value;
}


void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_time_int)
    {
        m_value++;
        ui->label->setText(QString::number(m_value));
        std::cout<<std::to_string(m_value*1000)<<std::endl;
    }
}
