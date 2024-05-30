/********************************************************************************
** Form generated from reading UI file 'page_manage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_MANAGE_H
#define UI_PAGE_MANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_page_manage
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *input;
    QPushButton *change;
    QPushButton *statistics;
    QPushButton *view;

    void setupUi(QWidget *page_manage)
    {
        if (page_manage->objectName().isEmpty())
            page_manage->setObjectName("page_manage");
        page_manage->resize(365, 293);
        page_manage->setMinimumSize(QSize(0, 0));
        page_manage->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(page_manage);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setHorizontalSpacing(50);
        gridLayout->setVerticalSpacing(35);
        gridLayout->setContentsMargins(50, 12, 50, 69);
        label = new QLabel(page_manage);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        input = new QPushButton(page_manage);
        input->setObjectName("input");

        gridLayout->addWidget(input, 1, 0, 1, 1);

        change = new QPushButton(page_manage);
        change->setObjectName("change");

        gridLayout->addWidget(change, 1, 1, 1, 1);

        statistics = new QPushButton(page_manage);
        statistics->setObjectName("statistics");

        gridLayout->addWidget(statistics, 2, 1, 1, 1);

        view = new QPushButton(page_manage);
        view->setObjectName("view");

        gridLayout->addWidget(view, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(page_manage);

        QMetaObject::connectSlotsByName(page_manage);
    } // setupUi

    void retranslateUi(QWidget *page_manage)
    {
        page_manage->setWindowTitle(QCoreApplication::translate("page_manage", "Form", nullptr));
        label->setText(QCoreApplication::translate("page_manage", "\345\255\246\347\224\237\350\200\203\345\213\244\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        input->setText(QCoreApplication::translate("page_manage", "\345\275\225\345\205\245\350\200\203\345\213\244\344\277\241\346\201\257", nullptr));
        change->setText(QCoreApplication::translate("page_manage", "\344\277\256\346\224\271\350\200\203\345\213\244\344\277\241\346\201\257", nullptr));
        statistics->setText(QCoreApplication::translate("page_manage", "\347\273\237\350\256\241\350\200\203\345\213\244\344\277\241\346\201\257", nullptr));
        view->setText(QCoreApplication::translate("page_manage", "\346\237\245\350\257\242\350\200\203\345\213\244\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page_manage: public Ui_page_manage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_MANAGE_H
