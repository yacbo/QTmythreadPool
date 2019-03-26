#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlTableModel>
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
    void on_addBtn_clicked();

    void on_ackDelBtn_clicked();

    void on_cancelDelBtn_clicked();

    void on_delBtn_clicked();

    void on_selectBtn_clicked();

private:
    Ui::Widget *ui;

    QSqlTableModel *model;
};

#endif // WIDGET_H
