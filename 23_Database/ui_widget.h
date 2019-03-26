/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QPushButton *addBtn;
    QPushButton *delBtn;
    QPushButton *ackDelBtn;
    QPushButton *cancelDelBtn;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *selectBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(408, 438);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(Widget);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 4);

        addBtn = new QPushButton(Widget);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        gridLayout->addWidget(addBtn, 1, 0, 1, 1);

        delBtn = new QPushButton(Widget);
        delBtn->setObjectName(QStringLiteral("delBtn"));

        gridLayout->addWidget(delBtn, 1, 1, 1, 1);

        ackDelBtn = new QPushButton(Widget);
        ackDelBtn->setObjectName(QStringLiteral("ackDelBtn"));

        gridLayout->addWidget(ackDelBtn, 1, 2, 1, 1);

        cancelDelBtn = new QPushButton(Widget);
        cancelDelBtn->setObjectName(QStringLiteral("cancelDelBtn"));

        gridLayout->addWidget(cancelDelBtn, 1, 3, 1, 1);

        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 2, 1, 1, 2);

        selectBtn = new QPushButton(Widget);
        selectBtn->setObjectName(QStringLiteral("selectBtn"));

        gridLayout->addWidget(selectBtn, 2, 3, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        addBtn->setText(QApplication::translate("Widget", "\345\242\236\345\212\240", Q_NULLPTR));
        delBtn->setText(QApplication::translate("Widget", "\345\210\240\351\231\244", Q_NULLPTR));
        ackDelBtn->setText(QApplication::translate("Widget", "\347\241\256\350\256\244", Q_NULLPTR));
        cancelDelBtn->setText(QApplication::translate("Widget", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\350\246\201\346\237\245\346\211\276\347\232\204\344\272\272\357\274\232", Q_NULLPTR));
        selectBtn->setText(QApplication::translate("Widget", "\346\237\245\346\211\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
