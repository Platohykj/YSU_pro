/********************************************************************************
** Form generated from reading UI file 'isteacher.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ISTEACHER_H
#define UI_ISTEACHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_isteacher
{
public:
    QCheckBox *checkBox;
    QPushButton *pushButton;

    void setupUi(QWidget *isteacher)
    {
        if (isteacher->objectName().isEmpty())
            isteacher->setObjectName("isteacher");
        isteacher->resize(200, 100);
        checkBox = new QCheckBox(isteacher);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(70, 35, 60, 18));
        pushButton = new QPushButton(isteacher);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(60, 70, 80, 18));

        retranslateUi(isteacher);

        QMetaObject::connectSlotsByName(isteacher);
    } // setupUi

    void retranslateUi(QWidget *isteacher)
    {
        isteacher->setWindowTitle(QCoreApplication::translate("isteacher", "Form", nullptr));
        checkBox->setText(QCoreApplication::translate("isteacher", "\346\230\257\345\220\246\344\270\272\350\200\201\345\270\210", nullptr));
        pushButton->setText(QCoreApplication::translate("isteacher", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class isteacher: public Ui_isteacher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ISTEACHER_H
