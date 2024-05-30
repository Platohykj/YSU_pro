/********************************************************************************
** Form generated from reading UI file 'dlg_add.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_ADD_H
#define UI_DLG_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dlg_Add
{
public:
    QGridLayout *gridLayout_3;
    QLabel *label_10;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *name;
    QLabel *label_4;
    QLineEdit *gender;
    QLabel *label_2;
    QLineEdit *age;
    QLabel *label_9;
    QLineEdit *nationality;
    QLabel *label_5;
    QLineEdit *province;
    QLabel *label_8;
    QLineEdit *subject_chinese;
    QLabel *label_7;
    QLineEdit *subject_math;
    QLabel *label_6;
    QLineEdit *subject_english;
    QLineEdit *student_id;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dlg_Add)
    {
        if (Dlg_Add->objectName().isEmpty())
            Dlg_Add->setObjectName("Dlg_Add");
        Dlg_Add->resize(325, 258);
        gridLayout_3 = new QGridLayout(Dlg_Add);
        gridLayout_3->setObjectName("gridLayout_3");
        label_10 = new QLabel(Dlg_Add);
        label_10->setObjectName("label_10");
        QFont font;
        font.setPointSize(12);
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_3 = new QLabel(Dlg_Add);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label = new QLabel(Dlg_Add);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 3, 1, 1);

        name = new QLineEdit(Dlg_Add);
        name->setObjectName("name");

        gridLayout->addWidget(name, 0, 4, 1, 2);

        label_4 = new QLabel(Dlg_Add);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        gender = new QLineEdit(Dlg_Add);
        gender->setObjectName("gender");

        gridLayout->addWidget(gender, 1, 1, 1, 1);

        label_2 = new QLabel(Dlg_Add);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 3, 1, 1);

        age = new QLineEdit(Dlg_Add);
        age->setObjectName("age");

        gridLayout->addWidget(age, 1, 4, 1, 2);

        label_9 = new QLabel(Dlg_Add);
        label_9->setObjectName("label_9");
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        nationality = new QLineEdit(Dlg_Add);
        nationality->setObjectName("nationality");

        gridLayout->addWidget(nationality, 2, 1, 1, 1);

        label_5 = new QLabel(Dlg_Add);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 2, 3, 1, 1);

        province = new QLineEdit(Dlg_Add);
        province->setObjectName("province");

        gridLayout->addWidget(province, 2, 4, 1, 2);

        label_8 = new QLabel(Dlg_Add);
        label_8->setObjectName("label_8");
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        subject_chinese = new QLineEdit(Dlg_Add);
        subject_chinese->setObjectName("subject_chinese");

        gridLayout->addWidget(subject_chinese, 3, 1, 1, 1);

        label_7 = new QLabel(Dlg_Add);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 3, 2, 1, 1);

        subject_math = new QLineEdit(Dlg_Add);
        subject_math->setObjectName("subject_math");

        gridLayout->addWidget(subject_math, 3, 3, 1, 1);

        label_6 = new QLabel(Dlg_Add);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 3, 4, 1, 1);

        subject_english = new QLineEdit(Dlg_Add);
        subject_english->setObjectName("subject_english");

        gridLayout->addWidget(subject_english, 3, 5, 1, 1);

        student_id = new QLineEdit(Dlg_Add);
        student_id->setObjectName("student_id");

        gridLayout->addWidget(student_id, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        pushButton = new QPushButton(Dlg_Add);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 25));

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(Dlg_Add);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 25));

        gridLayout_2->addWidget(pushButton_2, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 2, 0, 1, 1);


        retranslateUi(Dlg_Add);

        QMetaObject::connectSlotsByName(Dlg_Add);
    } // setupUi

    void retranslateUi(QDialog *Dlg_Add)
    {
        Dlg_Add->setWindowTitle(QCoreApplication::translate("Dlg_Add", "Dialog", nullptr));
        label_10->setText(QCoreApplication::translate("Dlg_Add", "\346\267\273\345\212\240\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        label_3->setText(QCoreApplication::translate("Dlg_Add", "\345\255\246\345\217\267", nullptr));
        label->setText(QCoreApplication::translate("Dlg_Add", "\345\247\223\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("Dlg_Add", "\346\200\247\345\210\253", nullptr));
        label_2->setText(QCoreApplication::translate("Dlg_Add", "\345\271\264\351\276\204", nullptr));
        label_9->setText(QCoreApplication::translate("Dlg_Add", "\346\260\221\346\227\217", nullptr));
        label_5->setText(QCoreApplication::translate("Dlg_Add", "\347\234\201\344\273\275", nullptr));
        label_8->setText(QCoreApplication::translate("Dlg_Add", "\350\257\255\346\226\207", nullptr));
        label_7->setText(QCoreApplication::translate("Dlg_Add", "\346\225\260\345\255\246", nullptr));
        label_6->setText(QCoreApplication::translate("Dlg_Add", "\350\213\261\350\257\255", nullptr));
        pushButton->setText(QCoreApplication::translate("Dlg_Add", "\346\267\273\345\212\240", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dlg_Add", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dlg_Add: public Ui_Dlg_Add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_ADD_H
