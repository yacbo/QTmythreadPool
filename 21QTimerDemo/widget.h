#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

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
    void on_buttonStart_clicked();

    void on_buttonStop_clicked();

private:
    Ui::Widget *ui;

    QTimer *m_Timer;    //定时器对象

protected:
    void timerEvent(QTimerEvent *event);
private:
    int m_time_int;
};

#endif // WIDGET_H
