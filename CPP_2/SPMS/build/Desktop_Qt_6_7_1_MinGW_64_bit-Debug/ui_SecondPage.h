/********************************************************************************
** Form generated from reading UI file 'SecondPage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDPAGE_H
#define UI_SECONDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTableView *tableView;
    QLineEdit *idLineEdit;
    QLineEdit *nameLineEdit;
    QLineEdit *ageLineEdit;
    QLineEdit *genderLineEdit;
    QLineEdit *nationalityLineEdit;
    QLineEdit *provinceLineEdit;
    QLineEdit *scoreLineEdit;
    QPushButton *searchIdButton;
    QPushButton *searchNameButton;
    QPushButton *searchAgeButton;
    QPushButton *searchGenderButton;
    QPushButton *searchNationalityButton;
    QPushButton *searchProvinceButton;
    QPushButton *searchScoreButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(640, 395);
        tableView = new QTableView(Form);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(120, 70, 361, 241));
        idLineEdit = new QLineEdit(Form);
        idLineEdit->setObjectName("idLineEdit");
        idLineEdit->setGeometry(QRect(10, 70, 111, 22));
        nameLineEdit = new QLineEdit(Form);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setGeometry(QRect(10, 110, 113, 22));
        ageLineEdit = new QLineEdit(Form);
        ageLineEdit->setObjectName("ageLineEdit");
        ageLineEdit->setGeometry(QRect(10, 150, 113, 22));
        genderLineEdit = new QLineEdit(Form);
        genderLineEdit->setObjectName("genderLineEdit");
        genderLineEdit->setGeometry(QRect(10, 190, 113, 22));
        nationalityLineEdit = new QLineEdit(Form);
        nationalityLineEdit->setObjectName("nationalityLineEdit");
        nationalityLineEdit->setGeometry(QRect(480, 70, 113, 22));
        provinceLineEdit = new QLineEdit(Form);
        provinceLineEdit->setObjectName("provinceLineEdit");
        provinceLineEdit->setGeometry(QRect(480, 110, 113, 22));
        scoreLineEdit = new QLineEdit(Form);
        scoreLineEdit->setObjectName("scoreLineEdit");
        scoreLineEdit->setGeometry(QRect(480, 150, 113, 22));
        searchIdButton = new QPushButton(Form);
        searchIdButton->setObjectName("searchIdButton");
        searchIdButton->setGeometry(QRect(10, 90, 111, 20));
        searchNameButton = new QPushButton(Form);
        searchNameButton->setObjectName("searchNameButton");
        searchNameButton->setGeometry(QRect(10, 130, 111, 20));
        searchAgeButton = new QPushButton(Form);
        searchAgeButton->setObjectName("searchAgeButton");
        searchAgeButton->setGeometry(QRect(10, 170, 111, 20));
        searchGenderButton = new QPushButton(Form);
        searchGenderButton->setObjectName("searchGenderButton");
        searchGenderButton->setGeometry(QRect(10, 210, 111, 20));
        searchNationalityButton = new QPushButton(Form);
        searchNationalityButton->setObjectName("searchNationalityButton");
        searchNationalityButton->setGeometry(QRect(480, 90, 111, 20));
        searchProvinceButton = new QPushButton(Form);
        searchProvinceButton->setObjectName("searchProvinceButton");
        searchProvinceButton->setGeometry(QRect(480, 130, 111, 20));
        searchScoreButton = new QPushButton(Form);
        searchScoreButton->setObjectName("searchScoreButton");
        searchScoreButton->setGeometry(QRect(480, 170, 111, 20));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        searchIdButton->setText(QCoreApplication::translate("Form", "\345\255\246\345\217\267\346\237\245\350\257\242", nullptr));
        searchNameButton->setText(QCoreApplication::translate("Form", "\345\247\223\345\220\215\346\237\245\350\257\242", nullptr));
        searchAgeButton->setText(QCoreApplication::translate("Form", "\345\271\264\351\276\204\346\237\245\350\257\242", nullptr));
        searchGenderButton->setText(QCoreApplication::translate("Form", "\346\200\247\345\210\253\346\237\245\350\257\242", nullptr));
        searchNationalityButton->setText(QCoreApplication::translate("Form", "\346\260\221\346\227\217\346\237\245\350\257\242", nullptr));
        searchProvinceButton->setText(QCoreApplication::translate("Form", "\347\234\201\344\273\275\346\237\245\350\257\242", nullptr));
        searchScoreButton->setText(QCoreApplication::translate("Form", "\345\210\206\346\225\260\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDPAGE_H
