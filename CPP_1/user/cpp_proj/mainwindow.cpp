#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QStringList>
#include <QAbstractButton>

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "SHA-256.h"
#include "json/json.h"
#include "curl/curl.h"
#include "list.h"
#include "student.h"


using namespace std;

QString loginname;
QString loginpassword;
QString signinname;
QString signinpassword1;
QString signinpassword2;

int isteacher = -1;

teacher t;
student s;
List<teacher> teacher_list;
List<student> student_list;
int del_id;

Temp temp;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadData("..\\output.txt");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadData(const QString &name) {
    QFile file(name);
    if (!file.open(QIODevice::ReadOnly)) {
        qInfo() << "Could not open file";
        return;
    }

    QTextStream stream(&file);
    names = stream.readLine().split("\t");
    qInfo() << names;
    //读取数据
    while (!stream.atEnd()) {
        QStringList line = stream.readLine().split("\t");
        qInfo() << line;
        auto student = new Student;
        student->id = line[0].toInt();
        student->name = line[1];
        student->age = line[2].toInt();
        student->height = line[3].toInt();
        student->weight = line[4].toInt();
        student->gender = line[5].toInt();
        student->class_num = line[6].toInt();
        student->grade = line[7].toInt();
        student->score = line[8].toInt();
        student->rank = line[9].toInt();
        student->salary = line[10].toInt();
        m_students.push_back(student);
    }

}



void MainWindow::on_pushButton_released()
{
    //切换到登录页面
    ui->stackedWidget->setCurrentWidget(ui->login);

}


void MainWindow::on_pushButton_2_released()
{
    ui->stackedWidget->setCurrentWidget(ui->signin);
}


void MainWindow::on_pushButton_4_released()
{
    ui->stackedWidget->setCurrentWidget(ui->firstmenu);
}


void MainWindow::on_pushButton_6_released()
{
    ui->stackedWidget->setCurrentWidget(ui->firstmenu);
}


void MainWindow::on_loginname_textEdited(const QString &arg1)
{
    loginname = arg1;
}


void MainWindow::on_loginpassword_textEdited(const QString &arg1)
{
    //QString转换string
    std::string str = arg1.toStdString();
    //SHA-256加密
    std::string message = str; // 待加密的信息
    std::string message_digest = Ly::Sha256::getInstance().getHexMessageDigest(message); // 加密
    loginpassword = QString::fromStdString(message_digest);
    printf("loginpassword: %s\n", loginpassword.toStdString().c_str());
}


void MainWindow::on_signinname_textEdited(const QString &arg1)
{
    signinname = arg1;
}


void MainWindow::on_signinpassword1_textEdited(const QString &arg1)
{
    printf("arg1: %s\n", arg1.toStdString().c_str());
    //QString转换string
    std::string str = arg1.toStdString();
    //SHA-256加密
    std::string message = str; // 待加密的信息
    std::string message_digest = Ly::Sha256::getInstance().getHexMessageDigest(message); // 加密
    signinpassword1 = QString::fromStdString(message_digest);
    printf("signinpassword1: %s\n", signinpassword1.toStdString().c_str());
}


void MainWindow::on_signinpassword2_textEdited(const QString &arg1)
{
    printf("arg1: %s\n", arg1.toStdString().c_str());
    //QString转换string
    std::string str = arg1.toStdString();
    //SHA-256加密
    std::string message = str; // 待加密的信息
    std::string message_digest = Ly::Sha256::getInstance().getHexMessageDigest(message); // 加密
    signinpassword2 = QString::fromStdString(message_digest);
    printf("signinpassword2: %s\n", signinpassword2.toStdString().c_str());
}


void MainWindow::on_signinbutton_released()
{
    //判断两次密码是否一致
    if(signinpassword1 != signinpassword2){
        QMessageBox::warning(this, "Warning", "两次密码不一致");
        return;
    }
    //将用户名和密码的哈希值打包成json
    Json::Value root;
    root[signinname.toStdString()] = signinpassword1.toStdString();
    Json::StreamWriterBuilder writer;
    std::string json_str = Json::writeString(writer, root);
    printf("json_str: %s\n", json_str.c_str());
    //初始化libcurl
    curl_global_init(CURL_GLOBAL_ALL);
    //创建libcurl句柄
    CURL *curl = curl_easy_init();
    if(curl) {
        //设置请求URL
        curl_easy_setopt(curl, CURLOPT_URL, "127.0.0.1:5000/signin");
        //设置POST请求
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        //设置请求主体数据
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str.c_str());
        //设置请求头
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        //执行HTTP请求
        CURLcode res = curl_easy_perform(curl);
        //检查是否发生错误
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        //检查状态码
        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

        if(response_code == 200){
            QMessageBox::information(this, "Success", "注册成功");
            ui->stackedWidget->setCurrentWidget(ui->menu);
        }else{
            QMessageBox::warning(this, "Warning", "用户已存在");
        }
        //清理libcurl资源
        curl_easy_cleanup(curl);
        //清理请求头资源
        curl_slist_free_all(headers);
    }
    //清理libcurl全局资源
    curl_global_cleanup();

}


void MainWindow::on_loginbutton_released()
{
    //将用户名和密码的哈希值打包成json
    Json::Value root;
    root[loginname.toStdString()] = loginpassword.toStdString();
    Json::StreamWriterBuilder writer;
    std::string json_str = Json::writeString(writer, root);
    printf("json_str: %s\n", json_str.c_str());
    //初始化libcurl
    curl_global_init(CURL_GLOBAL_ALL);
    //创建libcurl句柄
    CURL *curl = curl_easy_init();
    if(curl) {
        //设置请求URL
        curl_easy_setopt(curl, CURLOPT_URL, "127.0.0.1:5000/login");
        //设置POST请求
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        //设置请求主体数据
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str.c_str());
        //设置请求头
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        //执行HTTP请求
        CURLcode res = curl_easy_perform(curl);
        //检查是否发生错误
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        //检查状态码
        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

        if(response_code == 200){
            QMessageBox::information(this, "Success", "登录成功");
            ui->stackedWidget->setCurrentWidget(ui->menu);
        }else{
            QMessageBox::warning(this, "Warning", "登录失败");
        }
        //清理libcurl资源
        curl_easy_cleanup(curl);
        //清理请求头资源
        curl_slist_free_all(headers);
    }
    //清理libcurl全局资源
    curl_global_cleanup();
}

void MainWindow::on_addbutt_released()
{
    ui->stackedWidget->setCurrentWidget(ui->add);

}

void MainWindow::on_isteacher_stateChanged(int arg1)
{
    if(arg1 == 0){
        isteacher = 0;
    }else{
        isteacher = 1;
    }
}

void MainWindow::on_name_textEdited(const QString &arg1)
{
    if(isteacher == 0){
        s.name = arg1;
    }if (isteacher == -1){
        QMessageBox::warning(this, "Warning", "请先选择是否为老师");
        ui->name->clear();
    }else{
        t.name = arg1;
    }
}


void MainWindow::on_age_textEdited(const QString &arg1)
{
    if(isteacher == 0){
        s.age = arg1.toInt();
    }if (isteacher == -1){
        QMessageBox::warning(this, "Warning", "请先选择是否为老师");
        ui->age->clear();
    }else{
        t.age = arg1.toInt();
    }
}


void MainWindow::on_height_textEdited(const QString &arg1)
{
    if(isteacher == 0){
        s.height = arg1.toInt();
    }if (isteacher == -1){
        QMessageBox::warning(this, "Warning", "请先选择是否为老师");
        ui->height->clear();
    }else{
        t.height = arg1.toInt();
    }
}


void MainWindow::on_weight_textEdited(const QString &arg1)
{
    if(isteacher == 0){
        s.weight = arg1.toInt();
    }if (isteacher == -1){
        QMessageBox::warning(this, "Warning", "请先选择是否为老师");
        ui->weight->clear();
    }else{
        t.weight = arg1.toInt();
    }
}


void MainWindow::on_id_textEdited(const QString &arg1)
{
    if(isteacher == 0){
        s.id = arg1.toInt();
    }if (isteacher == -1){
        QMessageBox::warning(this, "Warning", "请先选择是否为老师");
        ui->id->clear();
    }else{
        t.id = arg1.toInt();
    }
}


void MainWindow::on_gender_textEdited(const QString &arg1)
{
    if(isteacher == 0){
        s.gender = arg1.toInt();
    } if (isteacher == -1){
        QMessageBox::warning(this, "Warning", "请先选择是否为老师");
        ui->gender->clear();
    }else {
        t.gender = arg1.toInt();
    }
}


void MainWindow::on_grade_textEdited(const QString &arg1)
{
    if(isteacher == 0){
        s.grade = arg1.toInt();
    } if (isteacher == -1){
        QMessageBox::warning(this, "Warning", "请先选择是否为老师");
        ui->grade->clear();
    }else {
        t.grade = arg1.toInt();
    }
}


void MainWindow::on_classnum_textEdited(const QString &arg1)
{
    if (isteacher == 0) {
        s.class_num = arg1.toInt();
    } if (isteacher == -1){
        QMessageBox::warning(this, "Warning", "请先选择是否为老师");
        ui->classnum->clear();
    }else {
        t.class_num = arg1.toInt();
    }
}


void MainWindow::on_score_textEdited(const QString &arg1)
{
    if(isteacher == 0){
        s.score = arg1.toInt();
    }if (isteacher == -1){
        QMessageBox::warning(this, "Warning", "请先选择是否为老师");
        ui->score->clear();
    }
}


void MainWindow::on_rank_textEdited(const QString &arg1)
{
    if(isteacher == 0){
        s.rank = arg1.toInt();
    }
    if (isteacher == -1){
        QMessageBox::warning(this, "Warning", "请先选择是否为老师");
        ui->rank->clear();
    }
}


void MainWindow::on_salary_textEdited(const QString &arg1)
{
    if(isteacher == 1){
        t.salary = arg1.toInt();
    }
    if (isteacher == -1){
        QMessageBox::warning(this, "Warning", "请先选择是否为老师");
        ui->salary->clear();
    }
}


void MainWindow::on_nextbutt_released()
{

    if (ui->name->text().isEmpty()) {
        QMessageBox::warning(this, "Warning", "姓名不能为空");
        return;
    }
    if(isteacher == 0){
        student_list.insert(s);
        isteacher = -1;
    }else{
        teacher_list.insert(t);
        isteacher = -1;
    }
    //清空输入框
    ui->name->clear();
    ui->age->clear();
    ui->height->clear();
    ui->weight->clear();
    ui->id->clear();
    ui->gender->clear();
    ui->grade->clear();
    ui->classnum->clear();
    ui->score->clear();
    ui->rank->clear();
    ui->salary->clear();
    //还原s和t
    s = student();
    t = teacher();
    //切换到添加页面
    ui->stackedWidget->setCurrentWidget(ui->add);
}


void MainWindow::on_finishbut_released()
{
    on_nextbutt_released();
    if (!(ui->name->text().isEmpty())) {
        if(isteacher == 0){
            student_list.insert(s);
            isteacher = -1;
        }else{
            teacher_list.insert(t);
            isteacher = -1;
        }
    }

    //遍历链表生成json
    Json::Value root;
    Node<student> *current = student_list.head;
    while (current != nullptr) {
        Json::Value student;
        student["name"] = current->data.name.toStdString();
        student["age"] = current->data.age;
        student["height"] = current->data.height;
        student["weight"] = current->data.weight;
        student["id"] = current->data.id;
        student["gender"] = current->data.gender;
        student["grade"] = current->data.grade;
        student["class_num"] = current->data.class_num;
        student["score"] = current->data.score;
        student["rank"] = current->data.rank;
        root.append(student);
        current = current->next;
    }
    //打印json
    Json::StreamWriterBuilder writer;
    std::string json_str = Json::writeString(writer, root);
    printf("json_str: %s\n", json_str.c_str());
    //初始化libcurl
    curl_global_init(CURL_GLOBAL_ALL);
    //创建libcurl句柄
    CURL *curl = curl_easy_init();
    if(curl) {
        //设置请求URL
        curl_easy_setopt(curl, CURLOPT_URL, "127.0.0.1:5000/student");
        //设置POST请求
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        //设置请求主体数据
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str.c_str());
        //设置请求头
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        //执行HTTP请求
        CURLcode res = curl_easy_perform(curl);
        //检查是否发生错误
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        //检查状态码
        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

        if(response_code == 200){
            QMessageBox::information(this, "Success", "学生录入成功");
            ui->stackedWidget->setCurrentWidget(ui->menu);
        }else{
            QMessageBox::warning(this, "Warning", "学生录入失败，请检查是否已经录入学生信息");
        }
        //清理libcurl资源
        curl_easy_cleanup(curl);
        //清理请求头资源
        curl_slist_free_all(headers);
        //清理libcurl全局资源
        curl_global_cleanup();

        //释放链表
        student_list.~List();

        Json::Value teacher_root;
        Node<teacher> *current = teacher_list.head;
        while (current != nullptr) {
            Json::Value teacher;
            teacher["name"] = current->data.name.toStdString();
            teacher["age"] = current->data.age;
            teacher["height"] = current->data.height;
            teacher["weight"] = current->data.weight;
            teacher["id"] = current->data.id;
            teacher["gender"] = current->data.gender;
            teacher["grade"] = current->data.grade;
            teacher["class_num"] = current->data.class_num;
            teacher["salary"] = current->data.salary;
            teacher_root.append(teacher);
            //打印json
            Json::StreamWriterBuilder writer;
            std::string json_str = Json::writeString(writer, teacher_root);
            printf("json_str: %s\n", json_str.c_str());
            current = current->next;
        }
        //打印json
        Json::StreamWriterBuilder writer;
        std::string json_strs = Json::writeString(writer, teacher_root);
        printf("json_str: %s\n", json_strs.c_str());
        //初始化libcurl
        curl_global_init(CURL_GLOBAL_ALL);
        //创建libcurl句柄
        CURL *curl = curl_easy_init();
        if(curl) {
            //设置请求URL
            curl_easy_setopt(curl, CURLOPT_URL, "127.0.0.1:5000/teacher");
            //设置POST请求
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
            //设置请求主体数据
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_strs.c_str());
            //设置请求头
            struct curl_slist *headers = NULL;
            headers = curl_slist_append(headers, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            //执行HTTP请求
            CURLcode res = curl_easy_perform(curl);
            //检查是否发生错误
            if (res != CURLE_OK) {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            }
            //检查状态码
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

            if(response_code == 200){
                QMessageBox::information(this, "Success", "教师录入成功");
                ui->stackedWidget->setCurrentWidget(ui->menu);
            }else{
                QMessageBox::warning(this, "Warning", "教师录入失败,请检查是否已经录入教师信息");
            }
            //清理libcurl资源
            curl_easy_cleanup(curl);
            //清理请求头资源
            curl_slist_free_all(headers);
            //清理libcurl全局资源
            curl_global_cleanup();
            //释放链表
            teacher_list.~List();
            //清空输入框
            ui->name->clear();
            ui->age->clear();
            ui->height->clear();
            ui->weight->clear();
            ui->id->clear();
            ui->gender->clear();
            ui->grade->clear();
            ui->classnum->clear();
            ui->score->clear();
            ui->rank->clear();
            ui->salary->clear();
            ui->stackedWidget->setCurrentWidget(ui->menu);
        }
    }
    isteacher = -1;
}

void MainWindow::on_names_textEdited(const QString &arg1)
{
    temp.name = arg1;
}


void MainWindow::on_ages_textEdited(const QString &arg1)
{
    temp.age = arg1.toInt();
}


void MainWindow::on_heights_textEdited(const QString &arg1)
{
    temp.height = arg1.toInt();
}


void MainWindow::on_weights_textEdited(const QString &arg1)
{
    temp.weight = arg1.toInt();
}


void MainWindow::on_ids_textEdited(const QString &arg1)
{
    temp.id = arg1.toInt();
}


void MainWindow::on_genders_textEdited(const QString &arg1)
{
    temp.gender = arg1.toInt();
}


void MainWindow::on_grades_textEdited(const QString &arg1)
{
    temp.grade = arg1.toInt();
}


void MainWindow::on_class_s_textEdited(const QString &arg1)
{
    temp.class_num = arg1.toInt();
}


void MainWindow::on_scores_textEdited(const QString &arg1)
{
    temp.score = arg1.toInt();
}


void MainWindow::on_ranks_textEdited(const QString &arg1)
{
    temp.rank = arg1.toInt();
}


void MainWindow::on_salarys_textEdited(const QString &arg1)
{
    temp.salary = arg1.toInt();
}


void MainWindow::on_isteachers_stateChanged(int arg1)
{
    if(arg1 == 0){
        temp.isteacher = 0;
    }else{
        temp.isteacher = 1;
    }
}
size_t write_callback(char *ptr, size_t size, size_t nmemb, std::string *stream) {
    size_t total_size = size * nmemb;
    stream->append(ptr, total_size);
    return total_size;
}

void MainWindow::on_searchbutts_released()
{
    //将temp中的数据打包成json
    Json::Value root;
    root["name"] = temp.name.toStdString();
    root["age"] = temp.age;
    root["height"] = temp.height;
    root["weight"] = temp.weight;
    root["id"] = temp.id;
    root["gender"] = temp.gender;
    root["grade"] = temp.grade;
    root["class_num"] = temp.class_num;
    root["score"] = temp.score;
    root["rank"] = temp.rank;
    root["salary"] = temp.salary;
    root["isteacher"] = temp.isteacher;
    Json::StreamWriterBuilder writer;
    std::string json_str = Json::writeString(writer, root);
    //初始化libcurl
    curl_global_init(CURL_GLOBAL_ALL);
    //创建libcurl句柄
    CURL *curl = curl_easy_init();
    if(curl) {
        //设置请求URL
        curl_easy_setopt(curl, CURLOPT_URL, "127.0.0.1:5000/search");
        //设置POST请求
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        //设置请求主体数据
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str.c_str());
        //设置请求头
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        // 设置写回调函数
        std::string response_text;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_text);
        //执行HTTP请求
        CURLcode res = curl_easy_perform(curl);
        //检查是否发生错误
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }else {
            std::cout << "Response text:" << std::endl;
            std::cout << response_text << std::endl;
        }
        //将response_text存入output.txt
        FILE* fp = fopen("..\\output.txt", "wb");
        fwrite(response_text.c_str(), 1, response_text.size(), fp);
        fclose(fp);
        //检查状态码
        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("response_code: %ld\n", response_code);

        if(response_code == 200){
            QMessageBox::information(this, "Success", "查询成功");
            //清理libcurl资源
            curl_easy_cleanup(curl);
            //清理请求头资源
            curl_slist_free_all(headers);
            //清理libcurl全局资源
            curl_global_cleanup();
        }
    }
    m_students.clear();
    loadData("..\\output.txt");
    //清空输入框
    ui->name->clear();
    ui->age->clear();
    ui->height->clear();
    ui->weight->clear();
    ui->id->clear();
    ui->gender->clear();
    ui->grade->clear();
    ui->classnum->clear();
    ui->score->clear();
    ui->rank->clear();
    ui->salary->clear();
    ui->stackedWidget->setCurrentWidget(ui->menu);
    ui->stackedWidget->setCurrentWidget(ui->display);
    //清空表格
    ui->table->clear();
    // 删除所有行
    ui->table->setRowCount(0);
    ui->table->setColumnCount(names.size());
    ui->table->setHorizontalHeaderLabels(names);
    for (auto student : m_students) {
        int row = ui->table->rowCount();
        ui->table->insertRow(ui->table->rowCount());
        ui->table->setItem(row, 0, new QTableWidgetItem(QString::number(student->id)));
        ui->table->setItem(row, 1, new QTableWidgetItem(student->name));
        ui->table->setItem(row, 2, new QTableWidgetItem(QString::number(student->age)));
        ui->table->setItem(row, 3, new QTableWidgetItem(QString::number(student->height)));
        ui->table->setItem(row, 4, new QTableWidgetItem(QString::number(student->weight)));
        ui->table->setItem(row, 5, new QTableWidgetItem(QString::number(student->gender)));
        ui->table->setItem(row, 6, new QTableWidgetItem(QString::number(student->class_num)));
        ui->table->setItem(row, 7, new QTableWidgetItem(QString::number(student->grade)));
        ui->table->setItem(row, 8, new QTableWidgetItem(QString::number(student->score)));
        ui->table->setItem(row, 9, new QTableWidgetItem(QString::number(student->rank)));
        ui->table->setItem(row, 10, new QTableWidgetItem(QString::number(student->salary)));
    }
    isteacher = -1;

}


void MainWindow::on_quitbutts_released()
{
    ui->stackedWidget->setCurrentWidget(ui->menu);
}


void MainWindow::on_searchbutt_released()
{
    ui->stackedWidget->setCurrentWidget(ui->search);
    isteacher = -1;
}
void MainWindow::on_back_released()
{
    ui->stackedWidget->setCurrentWidget(ui->menu);
    //清空表格
    ui->table->clear();
    // 删除所有行
    ui->table->setRowCount(0);
}

// 写入数据的回调函数
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* data) {
    data->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void MainWindow::on_statbutt_released()
{
    //将temp中的数据打包成json
    Json::Value root;
    root["name"] = temp.name.toStdString();
    root["age"] = temp.age;
    root["height"] = temp.height;
    root["weight"] = temp.weight;
    root["id"] = temp.id;
    root["gender"] = temp.gender;
    root["grade"] = temp.grade;
    root["class_num"] = temp.class_num;
    root["score"] = temp.score;
    root["rank"] = temp.rank;
    root["salary"] = temp.salary;
    root["isteacher"] = temp.isteacher;
    Json::StreamWriterBuilder writer;
    std::string json_str = Json::writeString(writer, root);
    //初始化libcurl
    curl_global_init(CURL_GLOBAL_ALL);
    //创建libcurl句柄
    CURL *curl = curl_easy_init();
    if(curl) {
        //设置请求URL
        curl_easy_setopt(curl, CURLOPT_URL, "127.0.0.1:5000/stat");
        //设置POST请求
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        //设置请求主体数据
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str.c_str());
        //设置请求头
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        // 设置写回调函数
        std::string response_text;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_text);
        //执行HTTP请求
        CURLcode res = curl_easy_perform(curl);
        //检查是否发生错误
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }else {
            std::cout << "Response text:" << std::endl;
            std::cout << response_text << std::endl;
        }
        //将response_text存入output.txt
        FILE* fp = fopen("..\\stat.txt", "wb");
        fwrite(response_text.c_str(), 1, response_text.size(), fp);
        fclose(fp);
        //检查状态码
        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("response_code: %ld\n", response_code);

        if(response_code == 200){
            QMessageBox::information(this, "Success", "查询成功");
            //清理libcurl资源
            curl_easy_cleanup(curl);
            //清理请求头资源
            curl_slist_free_all(headers);
            //清理libcurl全局资源
            curl_global_cleanup();
        }
    }
    ui->stackedWidget->setCurrentWidget(ui->display);
    //清空表格
    ui->table->clear();
    // 删除所有行
    ui->table->setRowCount(0);
    QStringList stat_names = {"student", "teacher", "total"};
    ui->table->setColumnCount(stat_names.size());
    ui->table->setHorizontalHeaderLabels(stat_names);
    //读取数据
    QFile file("..\\stat.txt");
    if (!file.open(QIODevice::ReadOnly)) {
        qInfo() << "Could not open file";
        return;
    }
    QTextStream stream(&file);
    //读取数据
    QStringList line = stream.readLine().split("\t");
    qInfo() << line;
    int student = line[0].toInt();
    int teacher = line[1].toInt();
    int total = line[2].toInt();
    file.close();
    int row = ui->table->rowCount();
    ui->table->insertRow(ui->table->rowCount());
    ui->table->setItem(row, 0, new QTableWidgetItem(QString::number(student)));
    ui->table->setItem(row, 1, new QTableWidgetItem(QString::number(teacher)));
    ui->table->setItem(row, 2, new QTableWidgetItem(QString::number(total)));
}

void MainWindow::on_delbutt_released()
{
    ui->stackedWidget->setCurrentWidget(ui->del);
}




void MainWindow::on_del_line_textEdited(const QString &arg1)
{
    del_id = arg1.toInt();
}


void MainWindow::on_pushButton_3_released()
{
    //将temp中的数据打包成json
    Json::Value root;
    root["id"] = del_id;

    Json::StreamWriterBuilder writer;
    std::string json_str = Json::writeString(writer, root);
    //初始化libcurl
    curl_global_init(CURL_GLOBAL_ALL);
    //创建libcurl句柄
    CURL *curl = curl_easy_init();
    if(curl) {
        //设置请求URL
        curl_easy_setopt(curl, CURLOPT_URL, "127.0.0.1:5000/delete");
        //设置POST请求
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        //设置请求主体数据
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str.c_str());
        //设置请求头
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);


        //执行HTTP请求
        CURLcode res = curl_easy_perform(curl);
        //检查是否发生错误
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        //检查状态码
        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

        if(response_code == 200){
            QMessageBox::information(this, "Success", "删除成功");
            ui->stackedWidget->setCurrentWidget(ui->menu);
            //清理libcurl资源
            curl_easy_cleanup(curl);
            //清理请求头资源
            curl_slist_free_all(headers);
            //清理libcurl全局资源
            curl_global_cleanup();
        }
    }
}


void MainWindow::on_pushButton_5_released()
{
    ui->stackedWidget->setCurrentWidget(ui->menu);

}






void MainWindow::on_delbutt_2_released()
{

}

