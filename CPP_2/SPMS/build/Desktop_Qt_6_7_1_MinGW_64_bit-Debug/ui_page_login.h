/********************************************************************************
** Form generated from reading UI file 'page_login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_LOGIN_H
#define UI_PAGE_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_page_login
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *login;
    QPushButton *Register;
    QPushButton *exit;
    QLabel *label_3;
    QCheckBox *checkBox;

    void setupUi(QWidget *page_login)
    {
        if (page_login->objectName().isEmpty())
            page_login->setObjectName("page_login");
        page_login->resize(365, 293);
        page_login->setMinimumSize(QSize(365, 293));
        page_login->setMaximumSize(QSize(365, 293));
        label = new QLabel(page_login);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 100, 61, 20));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(page_login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 140, 41, 20));
        label_2->setFont(font);
        username = new QLineEdit(page_login);
        username->setObjectName("username");
        username->setGeometry(QRect(140, 100, 181, 20));
        password = new QLineEdit(page_login);
        password->setObjectName("password");
        password->setGeometry(QRect(140, 140, 181, 20));
        password->setEchoMode(QLineEdit::Password);
        login = new QPushButton(page_login);
        login->setObjectName("login");
        login->setGeometry(QRect(60, 210, 80, 23));
        Register = new QPushButton(page_login);
        Register->setObjectName("Register");
        Register->setGeometry(QRect(210, 210, 81, 23));
        exit = new QPushButton(page_login);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(60, 250, 231, 23));
        label_3 = new QLabel(page_login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(52, 30, 240, 41));
        QFont font1;
        font1.setPointSize(20);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        checkBox = new QCheckBox(page_login);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(140, 180, 120, 18));

        retranslateUi(page_login);

        QMetaObject::connectSlotsByName(page_login);
    } // setupUi

    void retranslateUi(QWidget *page_login)
    {
        page_login->setWindowTitle(QCoreApplication::translate("page_login", "Form", nullptr));
        label->setText(QCoreApplication::translate("page_login", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("page_login", "\345\257\206\347\240\201", nullptr));
        username->setPlaceholderText(QCoreApplication::translate("page_login", "\350\257\267\350\276\223\345\205\245", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("page_login", "\350\257\267\350\276\223\345\205\245", nullptr));
        login->setText(QCoreApplication::translate("page_login", "\347\231\273\345\275\225", nullptr));
        Register->setText(QCoreApplication::translate("page_login", "\346\263\250\345\206\214", nullptr));
        exit->setText(QCoreApplication::translate("page_login", "\351\200\200\345\207\272", nullptr));
        label_3->setText(QCoreApplication::translate("page_login", "\345\255\246\347\224\237\350\200\203\345\213\244\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        checkBox->setText(QCoreApplication::translate("page_login", "\346\230\257\345\220\246\344\270\272\350\200\201\345\270\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page_login: public Ui_page_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_LOGIN_H
