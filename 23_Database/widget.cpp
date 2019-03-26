#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug()<<QSqlDatabase::drivers();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //连接数据库
    db.setHostName("172.29.1.219");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("test");  //使用哪个数据库
    //打开数据库
    if(!db.open())  //数据库打开失败
    {
        qDebug()<<"数据库打开失败";
        QMessageBox::warning(this,"错误",db.lastError().text());
        return ;
    }
    //设置模型
    model = new QSqlTableModel(this);
    model->setTable("student");
    //把model放在view
    ui->tableView->setModel(model);
    //显示model里的数据
    model->select();

    model->setHeaderData(0,Qt::Horizontal,"学号");
    //手动提交修改
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
   //view中的数据库不允许修改
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //QSqlQuery query;
    //query.exec("create table student(id int primary key auto_increment,name varchar(255),age int,score int)");
    //query.exec("insert into student(id,name,age,score) values(1,'mike',15,99)");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_addBtn_clicked()
{
    QSqlRecord record = model->record(); //获取空记录.

    int row = model->rowCount();
    model->insertRecord(row,record);
}

void Widget::on_ackDelBtn_clicked()
{
    model->submitAll();//提交所有
}

void Widget::on_cancelDelBtn_clicked()
{
    model->revertAll();
    model->submitAll();
}

void Widget::on_delBtn_clicked()
{
    QItemSelectionModel * sModel = ui->tableView->selectionModel();
    QModelIndexList list = sModel->selectedRows();
    for(auto item :list)
    {
        model->removeRow(item.row());
    }
}

void Widget::on_selectBtn_clicked()
{
    QString name = ui->lineEdit->text();
    if(!name.isEmpty())
    {
        QString str = QString("name = '%1'").arg(name);
        model->setFilter(str);
        model->select();
    }else
    {
        model->setTable("student");
        model->select();
    }
}
