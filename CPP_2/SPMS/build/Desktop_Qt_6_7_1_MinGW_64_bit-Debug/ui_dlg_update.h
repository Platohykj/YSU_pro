/********************************************************************************
** Form generated from reading UI file 'dlg_update.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_UPDATE_H
#define UI_DLG_UPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dlg_Update
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *student_id;
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
    QWidget *widget;
    QLineEdit *subject_english;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_6;
    QLineEdit *subject_math;
    QLineEdit *subject_chinese;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_10;

    void setupUi(QDialog *Dlg_Update)
    {
        if (Dlg_Update->objectName().isEmpty())
            Dlg_Update->setObjectName("Dlg_Update");
        Dlg_Update->resize(325, 258);
        gridLayout = new QGridLayout(Dlg_Update);
        gridLayout->setObjectName("gridLayout");
        label_3 = new QLabel(Dlg_Update);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        student_id = new QLineEdit(Dlg_Update);
        student_id->setObjectName("student_id");

        gridLayout->addWidget(student_id, 1, 1, 1, 1);

        label = new QLabel(Dlg_Update);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 2, 1, 1);

        name = new QLineEdit(Dlg_Update);
        name->setObjectName("name");

        gridLayout->addWidget(name, 1, 3, 1, 1);

        label_4 = new QLabel(Dlg_Update);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        gender = new QLineEdit(Dlg_Update);
        gender->setObjectName("gender");
        gender->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(gender, 2, 1, 1, 1);

        label_2 = new QLabel(Dlg_Update);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 2, 2, 1, 1);

        age = new QLineEdit(Dlg_Update);
        age->setObjectName("age");

        gridLayout->addWidget(age, 2, 3, 1, 1);

        label_9 = new QLabel(Dlg_Update);
        label_9->setObjectName("label_9");
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 3, 0, 1, 1);

        nationality = new QLineEdit(Dlg_Update);
        nationality->setObjectName("nationality");

        gridLayout->addWidget(nationality, 3, 1, 1, 1);

        label_5 = new QLabel(Dlg_Update);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 3, 2, 1, 1);

        province = new QLineEdit(Dlg_Update);
        province->setObjectName("province");

        gridLayout->addWidget(province, 3, 3, 1, 1);

        widget = new QWidget(Dlg_Update);
        widget->setObjectName("widget");
        subject_english = new QLineEdit(widget);
        subject_english->setObjectName("subject_english");
        subject_english->setGeometry(QRect(230, 10, 78, 22));
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(105, 10, 18, 22));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(1, 10, 18, 22));
        label_8->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(208, 10, 18, 22));
        label_6->setAlignment(Qt::AlignCenter);
        subject_math = new QLineEdit(widget);
        subject_math->setObjectName("subject_math");
        subject_math->setGeometry(QRect(127, 10, 77, 22));
        subject_chinese = new QLineEdit(widget);
        subject_chinese->setObjectName("subject_chinese");
        subject_chinese->setGeometry(QRect(23, 10, 78, 22));

        gridLayout->addWidget(widget, 4, 0, 1, 4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        pushButton = new QPushButton(Dlg_Update);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 25));

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(Dlg_Update);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 25));

        gridLayout_2->addWidget(pushButton_2, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 5, 0, 1, 4);

        label_10 = new QLabel(Dlg_Update);
        label_10->setObjectName("label_10");
        QFont font;
        font.setPointSize(12);
        label_10->setFont(font);
        label_10->setLayoutDirection(Qt::LeftToRight);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 0, 0, 1, 4);


        retranslateUi(Dlg_Update);

        QMetaObject::connectSlotsByName(Dlg_Update);
    } // setupUi

    void retranslateUi(QDialog *Dlg_Update)
    {
        Dlg_Update->setWindowTitle(QCoreApplication::translate("Dlg_Update", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("Dlg_Update", "\345\255\246\345\217\267", nullptr));
        label->setText(QCoreApplication::translate("Dlg_Update", "\345\247\223\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("Dlg_Update", "\346\200\247\345\210\253", nullptr));
        label_2->setText(QCoreApplication::translate("Dlg_Update", "\345\271\264\351\276\204", nullptr));
        label_9->setText(QCoreApplication::translate("Dlg_Update", "\346\260\221\346\227\217", nullptr));
        label_5->setText(QCoreApplication::translate("Dlg_Update", "\347\234\201\344\273\275", nullptr));
        label_7->setText(QCoreApplication::translate("Dlg_Update", "\346\225\260\345\255\246", nullptr));
        label_8->setText(QCoreApplication::translate("Dlg_Update", "\350\257\255\346\226\207", nullptr));
        label_6->setText(QCoreApplication::translate("Dlg_Update", "\350\213\261\350\257\255", nullptr));
        pushButton->setText(QCoreApplication::translate("Dlg_Update", "\344\277\256\346\224\271", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dlg_Update", "\345\217\226\346\266\210", nullptr));
        label_10->setText(QCoreApplication::translate("Dlg_Update", "\344\277\256\346\224\271\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dlg_Update: public Ui_Dlg_Update {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_UPDATE_H
