/********************************************************************************
** Form generated from reading UI file 'page_stu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_STU_H
#define UI_PAGE_STU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_page_stu
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget;

    void setupUi(QWidget *page_stu)
    {
        if (page_stu->objectName().isEmpty())
            page_stu->setObjectName("page_stu");
        page_stu->resize(900, 600);
        verticalLayout_2 = new QVBoxLayout(page_stu);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(page_stu);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(page_stu);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(page_stu);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(page_stu);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(page_stu);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(page_stu);

        QMetaObject::connectSlotsByName(page_stu);
    } // setupUi

    void retranslateUi(QWidget *page_stu)
    {
        page_stu->setWindowTitle(QCoreApplication::translate("page_stu", "Form", nullptr));
        label->setText(QCoreApplication::translate("page_stu", "\345\247\223\345\220\215", nullptr));
        pushButton->setText(QCoreApplication::translate("page_stu", "\346\220\234\347\264\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("page_stu", "\345\205\250\350\247\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page_stu: public Ui_page_stu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_STU_H
