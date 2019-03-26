#include "mywidget.h"
#include "ui_mywidget.h"
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>
#include <QVector>
QVector<int> intVec;
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    static int n = 0;
    QRegExp rx("[0-9\.]+$");
    QRegExpValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit->setValidator(validator);

    connect(ui->lineEdit,&QLineEdit::editingFinished,
        [=]()   //=:把外部所有局部变量、类中所有成员以值传递方式;this:类中所有成员以值传递;&:把外部所有局部变量，引用符号
        {
            if(ui->lineEdit->text() != "0000")
            {
                QMessageBox::warning(NULL,"warning","请检查lineEdit的输入值.");

                //
                intVec.push_back(n++);
                for(int temp :intVec)
                {
                    ui->lineEdit->setText(QString::number(temp));
                }
            }
        });
}

MyWidget::~MyWidget()
{
    delete ui;
}
