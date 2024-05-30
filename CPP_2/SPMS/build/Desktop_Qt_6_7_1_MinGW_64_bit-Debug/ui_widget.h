/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTableView *tableView;
    QPushButton *searchIdButton;
    QPushButton *searchNameButton;
    QPushButton *searchAgeButton;
    QPushButton *searchGenderButton;
    QPushButton *searchNationalityButton;
    QPushButton *searchProvinceButton;
    QPushButton *searchScoreButton;
    QLineEdit *idLineEdit;
    QLineEdit *nameLineEdit;
    QLineEdit *ageLineEdit;
    QLineEdit *genderLineEdit;
    QLineEdit *nationalityLineEdit;
    QLineEdit *provinceLineEdit;
    QLineEdit *scoreLineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        tableView = new QTableView(Widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(150, 60, 421, 291));
        searchIdButton = new QPushButton(Widget);
        searchIdButton->setObjectName("searchIdButton");
        searchIdButton->setGeometry(QRect(20, 100, 131, 20));
        searchNameButton = new QPushButton(Widget);
        searchNameButton->setObjectName("searchNameButton");
        searchNameButton->setGeometry(QRect(20, 160, 131, 20));
        searchAgeButton = new QPushButton(Widget);
        searchAgeButton->setObjectName("searchAgeButton");
        searchAgeButton->setGeometry(QRect(20, 220, 131, 20));
        searchGenderButton = new QPushButton(Widget);
        searchGenderButton->setObjectName("searchGenderButton");
        searchGenderButton->setGeometry(QRect(20, 280, 131, 20));
        searchNationalityButton = new QPushButton(Widget);
        searchNationalityButton->setObjectName("searchNationalityButton");
        searchNationalityButton->setGeometry(QRect(570, 100, 141, 20));
        searchProvinceButton = new QPushButton(Widget);
        searchProvinceButton->setObjectName("searchProvinceButton");
        searchProvinceButton->setGeometry(QRect(570, 160, 141, 20));
        searchScoreButton = new QPushButton(Widget);
        searchScoreButton->setObjectName("searchScoreButton");
        searchScoreButton->setGeometry(QRect(570, 220, 141, 20));
        idLineEdit = new QLineEdit(Widget);
        idLineEdit->setObjectName("idLineEdit");
        idLineEdit->setGeometry(QRect(20, 60, 131, 41));
        nameLineEdit = new QLineEdit(Widget);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setGeometry(QRect(20, 120, 131, 41));
        ageLineEdit = new QLineEdit(Widget);
        ageLineEdit->setObjectName("ageLineEdit");
        ageLineEdit->setGeometry(QRect(20, 180, 131, 41));
        genderLineEdit = new QLineEdit(Widget);
        genderLineEdit->setObjectName("genderLineEdit");
        genderLineEdit->setGeometry(QRect(20, 240, 131, 41));
        nationalityLineEdit = new QLineEdit(Widget);
        nationalityLineEdit->setObjectName("nationalityLineEdit");
        nationalityLineEdit->setGeometry(QRect(570, 60, 141, 41));
        provinceLineEdit = new QLineEdit(Widget);
        provinceLineEdit->setObjectName("provinceLineEdit");
        provinceLineEdit->setGeometry(QRect(570, 120, 141, 41));
        scoreLineEdit = new QLineEdit(Widget);
        scoreLineEdit->setObjectName("scoreLineEdit");
        scoreLineEdit->setGeometry(QRect(570, 180, 141, 41));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(570, 280, 141, 20));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        searchIdButton->setText(QCoreApplication::translate("Widget", "\345\255\246\345\217\267\346\237\245\350\257\242", nullptr));
        searchNameButton->setText(QCoreApplication::translate("Widget", "\345\247\223\345\220\215\346\237\245\350\257\242", nullptr));
        searchAgeButton->setText(QCoreApplication::translate("Widget", "\345\271\264\351\276\204\346\237\245\350\257\242", nullptr));
        searchGenderButton->setText(QCoreApplication::translate("Widget", "\346\200\247\345\210\253\346\237\245\350\257\242", nullptr));
        searchNationalityButton->setText(QCoreApplication::translate("Widget", "\345\233\275\347\261\215\346\237\245\350\257\242", nullptr));
        searchProvinceButton->setText(QCoreApplication::translate("Widget", "\347\234\201\344\273\275\346\237\245\350\257\242", nullptr));
        searchScoreButton->setText(QCoreApplication::translate("Widget", "\345\210\206\346\225\260\346\237\245\350\257\242", nullptr));
        idLineEdit->setText(QString());
        idLineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\255\246\345\217\267", nullptr));
        nameLineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215", nullptr));
        ageLineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\271\264\351\276\204", nullptr));
        genderLineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\346\200\247\345\210\253", nullptr));
        nationalityLineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\233\275\347\261\215", nullptr));
        provinceLineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\347\234\201\344\273\275", nullptr));
        scoreLineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\210\206\346\225\260", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
