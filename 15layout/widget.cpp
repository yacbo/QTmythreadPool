#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QMovie>
#include <QImage>
#include <QStandardItemModel>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // _timerEventId = this->startTimer(1000);

    connect(ui->pushButton,&QPushButton::released,
            [=]()
    {
        this->killTimer(_timerEventId);

        ui->progressBar->setEnabled(false);
        //ui->progressBar->setStyleSheet("QProgressBar {border: 2px solid grey;border-radius: 5px;background-color: #FFFFFF;} QProgressBar::chunk {background-color: #CFCFD0;width: 20px;}");
    }
    );

    connect(ui->pushButton_2,&QPushButton::released,
            [=]()
    {
        _timerEventId = this->startTimer(1000);
    }
    );

    ui->progressBar->setRange(0,100); //设置进度条最小值和最大值(取值范围)
    ui->widget_3->setStyleSheet("QWidget{background:rgb(64,66,68);}");
    ui->label_2->setStyleSheet("QLabel{color:rgb(255,255,255);}");




    ui->label->setGeometry(10,10,300,150);
    ui->label->setStyleSheet("QLabel:hover{border-width: 2px;border-style: solid;border-radius:21px;border-color:rgb(0, 177, 252);}");

    ui->label->setPixmap(QPixmap("://pic/22.jpg"));

    QPushButton *btn = new QPushButton();
    btn->setParent(ui->label);
    btn->setText("I'm a button");
    btn->setGeometry(80,10,90,40);

    connect(btn,&QPushButton::clicked,
            [=]{
        QMovie *mov = new QMovie("://pic/111.gif");
        ui->label->setMovie(mov);
        //mov->stop();
        ui->label->setScaledContents(true);
        mov->start();
    }
    );
    setTableView();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == _timerEventId)
    {
        static int sec = 0;
        ui->label->setText(
                    QString("<center><h1>time out: %1</h1></center>").arg(sec++)
                    );
        //ui->progressBar->setValue(sec);  //设置当前的运行值
        double dProgress = sec;
        ui->progressBar->setFormat(tr("Current progress : %1%").arg(QString::number(dProgress, 'f', 1)));
        ui->progressBar->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);  // 对齐方式
    }
}


void Widget::setTableView()
{
    QStandardItemModel  *model = new QStandardItemModel();
    model->setColumnCount(2);
    model->setHeaderData(0,Qt::Horizontal,QString("卡号"));
    model->setHeaderData(1,Qt::Horizontal,QString("姓名"));
    ui->tableView->setModel(model);

    //表头信息显示居中
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分列
    //设置列宽不可变
    ui->tableView->setColumnWidth(0,250);
    ui->tableView->setColumnWidth(1,250);

    for(int i = 0; i < 3; i++)
    {
        model->setItem(i,0,new QStandardItem(QString("%1").arg(i)));
        model->item(i,0)->setForeground(QBrush(QColor(255, 0, 0)));//设置字符颜色
        model->item(i,0)->setTextAlignment(Qt::AlignCenter);//设置字符位置

        model->setItem(i,1,new QStandardItem(QString("哈哈")));
        model->item(i,1)->setTextAlignment(Qt::AlignCenter);
    }

    int count = model->rowCount();
    for(int x = 0; x < count; x++)
    {
        model->removeRow(0);
    }

}
