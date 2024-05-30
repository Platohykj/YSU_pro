/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_view
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *name_v;
    QPushButton *search_v;
    QPushButton *view_t;
    QTableWidget *tableWidget;

    void setupUi(QWidget *view)
    {
        if (view->objectName().isEmpty())
            view->setObjectName("view");
        view->resize(900, 600);
        gridLayout = new QGridLayout(view);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(view);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        name_v = new QLineEdit(view);
        name_v->setObjectName("name_v");

        horizontalLayout->addWidget(name_v);


        horizontalLayout_2->addLayout(horizontalLayout);

        search_v = new QPushButton(view);
        search_v->setObjectName("search_v");

        horizontalLayout_2->addWidget(search_v);

        view_t = new QPushButton(view);
        view_t->setObjectName("view_t");

        horizontalLayout_2->addWidget(view_t);


        verticalLayout->addLayout(horizontalLayout_2);

        tableWidget = new QTableWidget(view);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(view);

        QMetaObject::connectSlotsByName(view);
    } // setupUi

    void retranslateUi(QWidget *view)
    {
        view->setWindowTitle(QCoreApplication::translate("view", "Form", nullptr));
        label->setText(QCoreApplication::translate("view", "\345\247\223\345\220\215", nullptr));
        search_v->setText(QCoreApplication::translate("view", "\346\220\234\347\264\242", nullptr));
        view_t->setText(QCoreApplication::translate("view", "\345\205\250\350\247\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class view: public Ui_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
