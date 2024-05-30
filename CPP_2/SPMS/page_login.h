#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#define USERFILE ".\\user.txt"
#include "page_manage.h"
#include "page_stu.h"
#include "QString"
#include "QFile"
#include <QWidget>

namespace Ui {
class page_login;
}

class page_login : public QWidget
{
    Q_OBJECT

public:
    explicit page_login(QWidget *parent = nullptr);
    ~page_login();

private slots:
    void on_login_clicked();

    void on_Register_clicked();

    void on_exit_clicked();

    void on_username_textEdited(const QString &arg1);

    void on_password_textEdited(const QString &arg1);

    void on_checkBox_stateChanged(int arg1);

private:


    Ui::page_login *ui;
    page_manage page_manage;
    page_stu page_stu;




};




#endif // PAGE_LOGIN_H
