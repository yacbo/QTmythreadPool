#ifndef WIDGET_H
#define WIDGET_H

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

private:
    Ui::Widget *ui;

protected:
    void timerEvent(QTimerEvent *event);
public:
    int m_time_int;
    int m_value;

public:
    void SetValue(int value);
    int GetValue();
};

#endif // WIDGET_H
