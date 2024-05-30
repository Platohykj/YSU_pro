/********************************************************************************
** Form generated from reading UI file 'input.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_H
#define UI_INPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_input
{
public:
    QDateEdit *date;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *ClassNum;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *ClassName;
    QLineEdit *StuName;
    QLabel *label_5;
    QComboBox *Method;
    QLabel *label_6;
    QPushButton *next;
    QPushButton *finish;
    QPushButton *save;

    void setupUi(QWidget *input)
    {
        if (input->objectName().isEmpty())
            input->setObjectName("input");
        input->resize(400, 313);
        input->setMinimumSize(QSize(400, 313));
        input->setMaximumSize(QSize(400, 313));
        date = new QDateEdit(input);
        date->setObjectName("date");
        date->setGeometry(QRect(110, 50, 121, 24));
        label = new QLabel(input);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 50, 70, 24));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        label_2 = new QLabel(input);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 50, 37, 24));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ClassNum = new QSpinBox(input);
        ClassNum->setObjectName("ClassNum");
        ClassNum->setGeometry(QRect(260, 50, 55, 24));
        label_3 = new QLabel(input);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(320, 50, 37, 24));
        label_3->setFont(font);
        label_4 = new QLabel(input);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 90, 70, 24));
        label_4->setFont(font);
        ClassName = new QLineEdit(input);
        ClassName->setObjectName("ClassName");
        ClassName->setGeometry(QRect(110, 90, 231, 24));
        StuName = new QLineEdit(input);
        StuName->setObjectName("StuName");
        StuName->setGeometry(QRect(110, 130, 231, 24));
        label_5 = new QLabel(input);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 130, 70, 24));
        label_5->setFont(font);
        Method = new QComboBox(input);
        Method->addItem(QString());
        Method->addItem(QString());
        Method->addItem(QString());
        Method->addItem(QString());
        Method->addItem(QString());
        Method->setObjectName("Method");
        Method->setGeometry(QRect(110, 170, 55, 24));
        label_6 = new QLabel(input);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 170, 70, 24));
        label_6->setFont(font);
        next = new QPushButton(input);
        next->setObjectName("next");
        next->setGeometry(QRect(150, 240, 80, 18));
        finish = new QPushButton(input);
        finish->setObjectName("finish");
        finish->setGeometry(QRect(270, 240, 80, 18));
        save = new QPushButton(input);
        save->setObjectName("save");
        save->setGeometry(QRect(30, 240, 80, 18));

        retranslateUi(input);

        QMetaObject::connectSlotsByName(input);
    } // setupUi

    void retranslateUi(QWidget *input)
    {
        input->setWindowTitle(QCoreApplication::translate("input", "Form", nullptr));
        label->setText(QCoreApplication::translate("input", "\347\274\272\350\257\276\346\227\245\346\234\237", nullptr));
        label_2->setText(QCoreApplication::translate("input", "\347\254\254", nullptr));
        label_3->setText(QCoreApplication::translate("input", "\350\212\202\350\257\276", nullptr));
        label_4->setText(QCoreApplication::translate("input", "\350\257\276\347\250\213\345\220\215\347\247\260", nullptr));
        ClassName->setPlaceholderText(QCoreApplication::translate("input", "\350\257\267\350\276\223\345\205\245\350\257\276\347\250\213\345\220\215\347\247\260", nullptr));
        StuName->setPlaceholderText(QCoreApplication::translate("input", "\350\257\267\350\276\223\345\205\245\345\255\246\347\224\237\345\247\223\345\220\215", nullptr));
        label_5->setText(QCoreApplication::translate("input", "\345\255\246\347\224\237\345\247\223\345\220\215", nullptr));
        Method->setItemText(0, QString());
        Method->setItemText(1, QCoreApplication::translate("input", "\350\277\237\345\210\260", nullptr));
        Method->setItemText(2, QCoreApplication::translate("input", "\346\227\267\350\257\276", nullptr));
        Method->setItemText(3, QCoreApplication::translate("input", "\346\227\251\351\200\200", nullptr));
        Method->setItemText(4, QCoreApplication::translate("input", "\350\257\267\345\201\207", nullptr));

        label_6->setText(QCoreApplication::translate("input", "\347\274\272\350\257\276\347\261\273\345\236\213", nullptr));
        next->setText(QCoreApplication::translate("input", "\344\270\213\344\270\200\344\270\252", nullptr));
        finish->setText(QCoreApplication::translate("input", "\347\273\223\346\235\237", nullptr));
        save->setText(QCoreApplication::translate("input", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class input: public Ui_input {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_H
