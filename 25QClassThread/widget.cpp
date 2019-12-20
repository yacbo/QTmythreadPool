#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <functional>
using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    pWrapper = new Wrapper();
    pWrapper->m_f = std::bind(&Widget::callback_hand,this,std::placeholders::_1);  //绑定widget中的回调

    pWeBack = new WeBack();
//    pWrapper->m_f = std::bind(&WeBack::callback_hand,pWeBack,std::placeholders::_1); //绑定WeBack中的回调
}

Widget::~Widget()
{
    delete pWrapper;
    delete pWeBack;
    delete ui;
}

void Widget::on_pushButton_clicked()
{
   std::thread th = pWrapper->member1_thread();
   th.detach();
}

void Widget::on_pushButton_2_clicked()
{
    std::thread th = pWrapper->member2_thread("hello method2.");
    th.detach();
}

void Widget::callback_hand(int num)
{
    ui->label->setText(QString::fromStdString(std::to_string(num)));
}
