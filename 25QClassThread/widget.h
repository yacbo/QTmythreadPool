#ifndef WIDGET_H
#define WIDGET_H
#include "wrapper.h"
#include "weback.h"
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;

private:
    Wrapper *pWrapper;
    WeBack *pWeBack;

public:
    void callback_hand(int num);  //回调，注册到其他对象中

public:
    void handler_thread(int num); //线程处理
};

#endif // WIDGET_H
