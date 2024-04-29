/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *firstpage;
    QStackedWidget *stackedWidget;
    QWidget *firstmenu;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QWidget *login;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *loginbutton;
    QPushButton *pushButton_4;
    QLineEdit *loginname;
    QLineEdit *loginpassword;
    QWidget *signin;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *signinname;
    QLineEdit *signinpassword1;
    QLineEdit *signinpassword2;
    QPushButton *signinbutton;
    QPushButton *pushButton_6;
    QWidget *del;
    QLineEdit *del_line;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QWidget *display;
    QTableWidget *table;
    QPushButton *back;
    QWidget *search;
    QLineEdit *ages;
    QLineEdit *names;
    QLineEdit *heights;
    QLineEdit *genders;
    QLineEdit *ranks;
    QLineEdit *grades;
    QLineEdit *class_s;
    QLineEdit *scores;
    QLineEdit *salarys;
    QLineEdit *ids;
    QLineEdit *weights;
    QLabel *labels;
    QCheckBox *isteachers;
    QPushButton *searchbutts;
    QPushButton *quitbutts;
    QLabel *label_9;
    QWidget *add;
    QCheckBox *isteacher;
    QLineEdit *name;
    QLineEdit *age;
    QLineEdit *height;
    QLineEdit *weight;
    QLineEdit *id;
    QLineEdit *gender;
    QLineEdit *grade;
    QLineEdit *classnum;
    QLineEdit *score;
    QLineEdit *rank;
    QLineEdit *salary;
    QPushButton *nextbutt;
    QPushButton *finishbut;
    QLabel *label_8;
    QLabel *label_10;
    QWidget *menu;
    QLabel *label_7;
    QPushButton *searchbutt;
    QPushButton *delbutt;
    QPushButton *addbutt;
    QPushButton *statbutt;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1288, 516);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(9999999, 9999999));
        firstpage = new QWidget(MainWindow);
        firstpage->setObjectName("firstpage");
        stackedWidget = new QStackedWidget(firstpage);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1281, 801));
        firstmenu = new QWidget();
        firstmenu->setObjectName("firstmenu");
        firstmenu->setMinimumSize(QSize(0, 0));
        firstmenu->setMaximumSize(QSize(16777215, 16777215));
        pushButton = new QPushButton(firstmenu);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(360, 240, 151, 81));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(firstmenu);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(650, 240, 151, 81));
        pushButton_2->setFont(font);
        label = new QLabel(firstmenu);
        label->setObjectName("label");
        label->setGeometry(QRect(400, 50, 341, 81));
        QFont font1;
        font1.setPointSize(16);
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(firstmenu);
        login = new QWidget();
        login->setObjectName("login");
        login->setMinimumSize(QSize(0, 0));
        login->setMaximumSize(QSize(16777215, 16777215));
        label_2 = new QLabel(login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(410, 160, 113, 20));
        label_2->setFont(font);
        label_3 = new QLabel(login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(410, 230, 113, 20));
        label_3->setFont(font);
        loginbutton = new QPushButton(login);
        loginbutton->setObjectName("loginbutton");
        loginbutton->setGeometry(QRect(410, 340, 80, 18));
        pushButton_4 = new QPushButton(login);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(600, 340, 80, 18));
        loginname = new QLineEdit(login);
        loginname->setObjectName("loginname");
        loginname->setGeometry(QRect(570, 160, 113, 20));
        loginpassword = new QLineEdit(login);
        loginpassword->setObjectName("loginpassword");
        loginpassword->setGeometry(QRect(570, 230, 113, 20));
        loginpassword->setEchoMode(QLineEdit::EchoMode::Password);
        stackedWidget->addWidget(login);
        signin = new QWidget();
        signin->setObjectName("signin");
        signin->setMinimumSize(QSize(0, 0));
        signin->setMaximumSize(QSize(16777215, 16777215));
        label_4 = new QLabel(signin);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(410, 130, 113, 20));
        label_4->setFont(font);
        label_5 = new QLabel(signin);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(410, 210, 113, 20));
        label_5->setFont(font);
        label_6 = new QLabel(signin);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(390, 290, 113, 20));
        label_6->setFont(font);
        signinname = new QLineEdit(signin);
        signinname->setObjectName("signinname");
        signinname->setGeometry(QRect(600, 130, 113, 20));
        signinpassword1 = new QLineEdit(signin);
        signinpassword1->setObjectName("signinpassword1");
        signinpassword1->setGeometry(QRect(600, 210, 113, 20));
        signinpassword1->setEchoMode(QLineEdit::EchoMode::Password);
        signinpassword2 = new QLineEdit(signin);
        signinpassword2->setObjectName("signinpassword2");
        signinpassword2->setGeometry(QRect(600, 290, 113, 20));
        signinpassword2->setEchoMode(QLineEdit::EchoMode::Password);
        signinbutton = new QPushButton(signin);
        signinbutton->setObjectName("signinbutton");
        signinbutton->setGeometry(QRect(430, 380, 80, 18));
        pushButton_6 = new QPushButton(signin);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(580, 380, 80, 18));
        stackedWidget->addWidget(signin);
        del = new QWidget();
        del->setObjectName("del");
        del->setMinimumSize(QSize(0, 0));
        del->setMaximumSize(QSize(16777215, 16777215));
        del_line = new QLineEdit(del);
        del_line->setObjectName("del_line");
        del_line->setGeometry(QRect(370, 180, 291, 31));
        pushButton_3 = new QPushButton(del);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(380, 320, 80, 18));
        pushButton_5 = new QPushButton(del);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(560, 320, 80, 18));
        stackedWidget->addWidget(del);
        display = new QWidget();
        display->setObjectName("display");
        display->setMinimumSize(QSize(0, 0));
        display->setMaximumSize(QSize(16777215, 16777215));
        table = new QTableWidget(display);
        table->setObjectName("table");
        table->setGeometry(QRect(0, 10, 1281, 381));
        back = new QPushButton(display);
        back->setObjectName("back");
        back->setGeometry(QRect(540, 430, 80, 18));
        stackedWidget->addWidget(display);
        search = new QWidget();
        search->setObjectName("search");
        search->setMinimumSize(QSize(0, 0));
        search->setMaximumSize(QSize(16777215, 16777215));
        ages = new QLineEdit(search);
        ages->setObjectName("ages");
        ages->setGeometry(QRect(410, 140, 113, 20));
        names = new QLineEdit(search);
        names->setObjectName("names");
        names->setGeometry(QRect(410, 100, 113, 20));
        heights = new QLineEdit(search);
        heights->setObjectName("heights");
        heights->setGeometry(QRect(410, 180, 113, 20));
        genders = new QLineEdit(search);
        genders->setObjectName("genders");
        genders->setGeometry(QRect(410, 300, 113, 20));
        ranks = new QLineEdit(search);
        ranks->setObjectName("ranks");
        ranks->setGeometry(QRect(570, 220, 113, 20));
        grades = new QLineEdit(search);
        grades->setObjectName("grades");
        grades->setGeometry(QRect(570, 100, 113, 20));
        class_s = new QLineEdit(search);
        class_s->setObjectName("class_s");
        class_s->setGeometry(QRect(570, 140, 113, 20));
        scores = new QLineEdit(search);
        scores->setObjectName("scores");
        scores->setGeometry(QRect(570, 180, 113, 20));
        salarys = new QLineEdit(search);
        salarys->setObjectName("salarys");
        salarys->setGeometry(QRect(570, 260, 113, 20));
        ids = new QLineEdit(search);
        ids->setObjectName("ids");
        ids->setGeometry(QRect(410, 260, 113, 20));
        weights = new QLineEdit(search);
        weights->setObjectName("weights");
        weights->setGeometry(QRect(410, 220, 113, 20));
        labels = new QLabel(search);
        labels->setObjectName("labels");
        labels->setGeometry(QRect(500, 40, 111, 21));
        labels->setFont(font1);
        labels->setAlignment(Qt::AlignmentFlag::AlignCenter);
        isteachers = new QCheckBox(search);
        isteachers->setObjectName("isteachers");
        isteachers->setGeometry(QRect(570, 300, 113, 20));
        searchbutts = new QPushButton(search);
        searchbutts->setObjectName("searchbutts");
        searchbutts->setGeometry(QRect(580, 380, 80, 18));
        quitbutts = new QPushButton(search);
        quitbutts->setObjectName("quitbutts");
        quitbutts->setGeometry(QRect(430, 380, 80, 18));
        label_9 = new QLabel(search);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(410, 340, 281, 21));
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(search);
        add = new QWidget();
        add->setObjectName("add");
        add->setMinimumSize(QSize(0, 0));
        add->setMaximumSize(QSize(16777215, 9999999));
        isteacher = new QCheckBox(add);
        isteacher->setObjectName("isteacher");
        isteacher->setGeometry(QRect(570, 300, 113, 20));
        name = new QLineEdit(add);
        name->setObjectName("name");
        name->setGeometry(QRect(410, 100, 113, 20));
        age = new QLineEdit(add);
        age->setObjectName("age");
        age->setGeometry(QRect(410, 140, 113, 20));
        height = new QLineEdit(add);
        height->setObjectName("height");
        height->setGeometry(QRect(410, 180, 113, 20));
        weight = new QLineEdit(add);
        weight->setObjectName("weight");
        weight->setGeometry(QRect(410, 220, 113, 20));
        id = new QLineEdit(add);
        id->setObjectName("id");
        id->setGeometry(QRect(410, 260, 113, 20));
        gender = new QLineEdit(add);
        gender->setObjectName("gender");
        gender->setGeometry(QRect(410, 300, 113, 20));
        grade = new QLineEdit(add);
        grade->setObjectName("grade");
        grade->setGeometry(QRect(570, 100, 113, 20));
        classnum = new QLineEdit(add);
        classnum->setObjectName("classnum");
        classnum->setGeometry(QRect(570, 140, 113, 20));
        score = new QLineEdit(add);
        score->setObjectName("score");
        score->setGeometry(QRect(570, 180, 113, 20));
        rank = new QLineEdit(add);
        rank->setObjectName("rank");
        rank->setGeometry(QRect(570, 220, 113, 20));
        salary = new QLineEdit(add);
        salary->setObjectName("salary");
        salary->setGeometry(QRect(570, 260, 113, 20));
        nextbutt = new QPushButton(add);
        nextbutt->setObjectName("nextbutt");
        nextbutt->setGeometry(QRect(430, 380, 80, 18));
        finishbut = new QPushButton(add);
        finishbut->setObjectName("finishbut");
        finishbut->setGeometry(QRect(580, 380, 80, 18));
        label_8 = new QLabel(add);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(500, 40, 91, 31));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_10 = new QLabel(add);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(410, 340, 281, 21));
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(add);
        menu = new QWidget();
        menu->setObjectName("menu");
        menu->setMinimumSize(QSize(0, 0));
        menu->setMaximumSize(QSize(16777215, 16777215));
        label_7 = new QLabel(menu);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(490, 70, 211, 61));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        searchbutt = new QPushButton(menu);
        searchbutt->setObjectName("searchbutt");
        searchbutt->setGeometry(QRect(660, 200, 71, 41));
        searchbutt->setFont(font);
        delbutt = new QPushButton(menu);
        delbutt->setObjectName("delbutt");
        delbutt->setGeometry(QRect(660, 290, 71, 41));
        delbutt->setFont(font);
        addbutt = new QPushButton(menu);
        addbutt->setObjectName("addbutt");
        addbutt->setGeometry(QRect(470, 290, 71, 41));
        addbutt->setFont(font);
        statbutt = new QPushButton(menu);
        statbutt->setObjectName("statbutt");
        statbutt->setGeometry(QRect(470, 200, 71, 41));
        statbutt->setFont(font);
        stackedWidget->addWidget(menu);
        MainWindow->setCentralWidget(firstpage);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1288, 38));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "login", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "signup", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Manage system", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        loginbutton->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        loginpassword->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Confirm password", nullptr));
        signinpassword1->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245", nullptr));
        signinpassword2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245", nullptr));
        signinbutton->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        del_line->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245id", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "quit", nullptr));
        back->setText(QCoreApplication::translate("MainWindow", "back", nullptr));
        ages->setPlaceholderText(QCoreApplication::translate("MainWindow", "age", nullptr));
        names->setPlaceholderText(QCoreApplication::translate("MainWindow", "name", nullptr));
        heights->setPlaceholderText(QCoreApplication::translate("MainWindow", "height", nullptr));
        genders->setPlaceholderText(QCoreApplication::translate("MainWindow", "gender", nullptr));
        ranks->setPlaceholderText(QCoreApplication::translate("MainWindow", "rank", nullptr));
        grades->setPlaceholderText(QCoreApplication::translate("MainWindow", "grade", nullptr));
        class_s->setPlaceholderText(QCoreApplication::translate("MainWindow", "class_num", nullptr));
        scores->setPlaceholderText(QCoreApplication::translate("MainWindow", "score", nullptr));
        salarys->setPlaceholderText(QCoreApplication::translate("MainWindow", "salary", nullptr));
        ids->setPlaceholderText(QCoreApplication::translate("MainWindow", "id", nullptr));
        weights->setPlaceholderText(QCoreApplication::translate("MainWindow", "weight", nullptr));
        labels->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        isteachers->setText(QCoreApplication::translate("MainWindow", "\346\230\257\345\220\246\346\230\257\346\225\231\345\270\210", nullptr));
        searchbutts->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        quitbutts->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Tag\357\274\232for gender\357\274\2320 for famale\357\274\2141 for male", nullptr));
        isteacher->setText(QCoreApplication::translate("MainWindow", "\346\230\257\345\220\246\346\230\257\346\225\231\345\270\210", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("MainWindow", "name", nullptr));
        age->setPlaceholderText(QCoreApplication::translate("MainWindow", "age", nullptr));
        height->setPlaceholderText(QCoreApplication::translate("MainWindow", "height", nullptr));
        weight->setPlaceholderText(QCoreApplication::translate("MainWindow", "weight", nullptr));
        id->setPlaceholderText(QCoreApplication::translate("MainWindow", "id", nullptr));
        gender->setPlaceholderText(QCoreApplication::translate("MainWindow", "gender", nullptr));
        grade->setPlaceholderText(QCoreApplication::translate("MainWindow", "grade", nullptr));
        classnum->setPlaceholderText(QCoreApplication::translate("MainWindow", "class_num", nullptr));
        score->setPlaceholderText(QCoreApplication::translate("MainWindow", "score", nullptr));
        rank->setPlaceholderText(QCoreApplication::translate("MainWindow", "rank", nullptr));
        salary->setPlaceholderText(QCoreApplication::translate("MainWindow", "salary", nullptr));
        nextbutt->setText(QCoreApplication::translate("MainWindow", "next", nullptr));
        finishbut->setText(QCoreApplication::translate("MainWindow", "finish", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Tag\357\274\232for gender\357\274\2320 for famale\357\274\2141 for male", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Manage menu", nullptr));
        searchbutt->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        delbutt->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        addbutt->setText(QCoreApplication::translate("MainWindow", "\345\275\225\345\205\245", nullptr));
        statbutt->setText(QCoreApplication::translate("MainWindow", "\347\273\237\350\256\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
