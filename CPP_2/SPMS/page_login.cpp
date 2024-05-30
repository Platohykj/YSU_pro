#include "page_login.h"
#include "ui_page_login.h"
#include "QString"
#include "QFile"
#include "QMessageBox"
#include "page_manage.h"
#include "sha256.h"
#include "page_stu.h"
#include "info.h"

QString username;
QString password;
bool isteacher;

class User {
public:
    QString username;
    QString password;
    bool isTeacher;

    User(QString username, QString password, bool isTeacher) : username(username), password(password), isTeacher(isTeacher){}
};


page_login::page_login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::page_login)
{
    ui->setupUi(this);
}

page_login::~page_login()
{
    delete ui;
}


void page_login::on_username_textEdited(const QString &arg1)
{
    username = arg1;
}


void page_login::on_password_textEdited(const QString &arg1)
{
    password = arg1;
}


void page_login::on_checkBox_stateChanged(int arg1)
{
    isteacher = arg1;
}


void page_login::on_login_clicked()
{
    // 创建用户对象，用于存储登录信息
    User user(username,password,isteacher);

    // 对密码进行SHA-256加密
    password = QString::fromStdString(Ly::Sha256::getInstance().getHexMessageDigest(password.toStdString()));

    // 比较文件中存储的用户名和密码与用户输入的用户名和密码是否匹配
    if(compareFileContents(USERFILE,username,password,isteacher)){
        // 登录成功
        QMessageBox::information(nullptr, "Success", "登录成功！");
        // 如果是老师用户，则显示管理页面，否则显示学生页面
        if(isteacher){
            this->hide();
            page_manage.show();
        }else{
            this->hide();
            page_stu.show();
        }
        // 清空用户名和密码
        username.clear();
        password.clear();
    }else{
        // 登录失败，显示警告信息
        QMessageBox::warning(nullptr, "登录失败", "用户名或密码不正确！");
        // 清空用户名和密码
        username.clear();
        password.clear();
    }
}



void page_login::on_Register_clicked()
{
    // 创建用户对象，用于存储注册信息
    User user(username,password,isteacher);

    // 检查用户名是否已存在
    if(!isUsernameExists(USERFILE,username)){
        // 打开用户文件以追加方式写入新用户信息
        QFile file(USERFILE);
        if (!file.open(QIODevice::Append | QIODevice::Text)) {
            // 打开文件失败，输出错误信息并返回
            qDebug() << "Failed to open file for appending:" << file.errorString();
            return;
        }

        // 使用 QTextStream 写入新用户信息到文件中
        QTextStream out(&file);
        out << username << ' ' << QString::fromStdString(Ly::Sha256::getInstance().getHexMessageDigest(password.toStdString())) << ' ' << isteacher << Qt::endl;

        // 关闭文件
        file.close();

        // 注册成功，显示成功信息提示框，并根据用户类型显示相应的页面
        QMessageBox::information(nullptr, "Success", "注册成功！");
        if(isteacher){
            this->hide();
            page_manage.show();
        }else{
            this->hide();
            page_stu.show();
        }

        // 清空用户名和密码
        username.clear();
        password.clear();
    }else{
        // 用户名已存在，显示注册失败的警告信息
        QMessageBox::warning(nullptr, "注册失败", "用户名已经存在！");

        // 清空用户名和密码
        username.clear();
        password.clear();
    }
}


void page_login::on_exit_clicked()
{
    exit(0);
}
