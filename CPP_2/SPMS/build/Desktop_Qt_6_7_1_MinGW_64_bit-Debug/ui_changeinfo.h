/********************************************************************************
** Form generated from reading UI file 'changeinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEINFO_H
#define UI_CHANGEINFO_H

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

class Ui_changeInfo
{
public:
    QLabel *label;
    QSpinBox *classnum_c;
    QLabel *label_2;
    QLabel *label_3;
    QDateEdit *date_c;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *stuname_c;
    QLabel *label_6;
    QComboBox *method_c;
    QLineEdit *classname_c;
    QPushButton *right;
    QPushButton *wrong;
    QLabel *label_7;
    QSpinBox *id_c;
    QPushButton *load;

    void setupUi(QWidget *changeInfo)
    {
        if (changeInfo->objectName().isEmpty())
            changeInfo->setObjectName("changeInfo");
        changeInfo->resize(400, 313);
        changeInfo->setMinimumSize(QSize(400, 313));
        changeInfo->setMaximumSize(QSize(400, 313));
        label = new QLabel(changeInfo);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 70, 70, 24));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        classnum_c = new QSpinBox(changeInfo);
        classnum_c->setObjectName("classnum_c");
        classnum_c->setGeometry(QRect(260, 70, 55, 24));
        label_2 = new QLabel(changeInfo);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 70, 37, 24));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(changeInfo);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(320, 70, 37, 24));
        label_3->setFont(font);
        date_c = new QDateEdit(changeInfo);
        date_c->setObjectName("date_c");
        date_c->setGeometry(QRect(110, 70, 121, 24));
        label_4 = new QLabel(changeInfo);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 110, 70, 24));
        label_4->setFont(font);
        label_5 = new QLabel(changeInfo);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 150, 70, 24));
        label_5->setFont(font);
        stuname_c = new QLineEdit(changeInfo);
        stuname_c->setObjectName("stuname_c");
        stuname_c->setGeometry(QRect(110, 150, 231, 24));
        label_6 = new QLabel(changeInfo);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 190, 70, 24));
        label_6->setFont(font);
        method_c = new QComboBox(changeInfo);
        method_c->addItem(QString());
        method_c->addItem(QString());
        method_c->addItem(QString());
        method_c->addItem(QString());
        method_c->addItem(QString());
        method_c->setObjectName("method_c");
        method_c->setGeometry(QRect(110, 190, 55, 24));
        classname_c = new QLineEdit(changeInfo);
        classname_c->setObjectName("classname_c");
        classname_c->setGeometry(QRect(110, 110, 231, 24));
        right = new QPushButton(changeInfo);
        right->setObjectName("right");
        right->setGeometry(QRect(70, 250, 80, 18));
        wrong = new QPushButton(changeInfo);
        wrong->setObjectName("wrong");
        wrong->setGeometry(QRect(230, 250, 80, 18));
        label_7 = new QLabel(changeInfo);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 30, 70, 24));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        id_c = new QSpinBox(changeInfo);
        id_c->setObjectName("id_c");
        id_c->setGeometry(QRect(110, 30, 55, 24));
        load = new QPushButton(changeInfo);
        load->setObjectName("load");
        load->setGeometry(QRect(220, 30, 80, 24));

        retranslateUi(changeInfo);

        QMetaObject::connectSlotsByName(changeInfo);
    } // setupUi

    void retranslateUi(QWidget *changeInfo)
    {
        changeInfo->setWindowTitle(QCoreApplication::translate("changeInfo", "Form", nullptr));
        label->setText(QCoreApplication::translate("changeInfo", "\347\274\272\350\257\276\346\227\245\346\234\237", nullptr));
        label_2->setText(QCoreApplication::translate("changeInfo", "\347\254\254", nullptr));
        label_3->setText(QCoreApplication::translate("changeInfo", "\350\212\202\350\257\276", nullptr));
        label_4->setText(QCoreApplication::translate("changeInfo", "\350\257\276\347\250\213\345\220\215\347\247\260", nullptr));
        label_5->setText(QCoreApplication::translate("changeInfo", "\345\255\246\347\224\237\345\247\223\345\220\215", nullptr));
        stuname_c->setPlaceholderText(QCoreApplication::translate("changeInfo", "\350\257\267\350\276\223\345\205\245\345\255\246\347\224\237\345\247\223\345\220\215", nullptr));
        label_6->setText(QCoreApplication::translate("changeInfo", "\347\274\272\350\257\276\347\261\273\345\236\213", nullptr));
        method_c->setItemText(0, QString());
        method_c->setItemText(1, QCoreApplication::translate("changeInfo", "\350\277\237\345\210\260", nullptr));
        method_c->setItemText(2, QCoreApplication::translate("changeInfo", "\346\227\267\350\257\276", nullptr));
        method_c->setItemText(3, QCoreApplication::translate("changeInfo", "\346\227\251\351\200\200", nullptr));
        method_c->setItemText(4, QCoreApplication::translate("changeInfo", "\350\257\267\345\201\207", nullptr));

        classname_c->setPlaceholderText(QCoreApplication::translate("changeInfo", "\350\257\267\350\276\223\345\205\245\350\257\276\347\250\213\345\220\215\347\247\260", nullptr));
        right->setText(QCoreApplication::translate("changeInfo", "\347\241\256\345\256\232", nullptr));
        wrong->setText(QCoreApplication::translate("changeInfo", "\345\217\226\346\266\210", nullptr));
        label_7->setText(QCoreApplication::translate("changeInfo", "ID      ", nullptr));
        load->setText(QCoreApplication::translate("changeInfo", "\345\212\240\350\275\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeInfo: public Ui_changeInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEINFO_H
