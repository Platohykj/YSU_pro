/********************************************************************************
** Form generated from reading UI file 'statistics.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICS_H
#define UI_STATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_statistics
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *from;
    QLabel *label_2;
    QDateEdit *to;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget;

    void setupUi(QWidget *statistics)
    {
        if (statistics->objectName().isEmpty())
            statistics->setObjectName("statistics");
        statistics->resize(900, 600);
        verticalLayout_2 = new QVBoxLayout(statistics);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(statistics);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        from = new QDateEdit(statistics);
        from->setObjectName("from");

        horizontalLayout->addWidget(from);

        label_2 = new QLabel(statistics);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        to = new QDateEdit(statistics);
        to->setObjectName("to");

        horizontalLayout->addWidget(to);

        pushButton = new QPushButton(statistics);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(statistics);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(statistics);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(statistics);

        QMetaObject::connectSlotsByName(statistics);
    } // setupUi

    void retranslateUi(QWidget *statistics)
    {
        statistics->setWindowTitle(QCoreApplication::translate("statistics", "Form", nullptr));
        label->setText(QCoreApplication::translate("statistics", "\344\273\216", nullptr));
        label_2->setText(QCoreApplication::translate("statistics", "\345\210\260", nullptr));
        pushButton->setText(QCoreApplication::translate("statistics", "\347\273\237\350\256\241\345\255\246\347\224\237", nullptr));
        pushButton_2->setText(QCoreApplication::translate("statistics", "\347\273\237\350\256\241\350\257\276\347\250\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class statistics: public Ui_statistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICS_H
