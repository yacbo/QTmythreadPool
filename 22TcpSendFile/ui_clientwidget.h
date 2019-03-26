/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QPushButton *pushButton;
    QProgressBar *progressBar;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *labelIP;
    QLineEdit *lineEditIP;
    QLabel *labelPort;
    QLineEdit *lineEditPort;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QStringLiteral("ClientWidget"));
        ClientWidget->resize(400, 300);
        pushButton = new QPushButton(ClientWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(263, 33, 75, 23));
        progressBar = new QProgressBar(ClientWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(40, 80, 211, 23));
        progressBar->setValue(24);
        widget = new QWidget(ClientWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(44, 21, 213, 48));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelIP = new QLabel(widget);
        labelIP->setObjectName(QStringLiteral("labelIP"));

        gridLayout->addWidget(labelIP, 0, 0, 1, 1);

        lineEditIP = new QLineEdit(widget);
        lineEditIP->setObjectName(QStringLiteral("lineEditIP"));

        gridLayout->addWidget(lineEditIP, 0, 1, 1, 1);

        labelPort = new QLabel(widget);
        labelPort->setObjectName(QStringLiteral("labelPort"));

        gridLayout->addWidget(labelPort, 1, 0, 1, 1);

        lineEditPort = new QLineEdit(widget);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 1, 1, 1, 1);


        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QApplication::translate("ClientWidget", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ClientWidget", "connect", Q_NULLPTR));
        labelIP->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250IP\357\274\232", Q_NULLPTR));
        lineEditIP->setText(QApplication::translate("ClientWidget", "127.0.0.1", Q_NULLPTR));
        labelPort->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250PORT\357\274\232", Q_NULLPTR));
        lineEditPort->setText(QApplication::translate("ClientWidget", "8888", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
