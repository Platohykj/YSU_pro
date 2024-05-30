#include "input.h"
#include "ui_input.h"
#include "QDate"
#include "QFile"
#include "info.h"

int id_s = lastid(QString(INFOPATH)) + 1;
QString date_s;
int ClassNum_s;
QString ClassName_s;
QString StuName_s;
QString Method_s;

input::input(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::input)
{
    ui->setupUi(this);
    QDate initDate(2000, 1, 1);
    ui->date->setDate(initDate);
}

input::~input()
{
    delete ui;
}

void input::on_date_userDateChanged(const QDate &date)
{
    date_s = date.toString("dd/MM/yyyy");
}


void input::on_ClassNum_valueChanged(int arg1)
{
    ClassNum_s = arg1;
}


void input::on_ClassName_textEdited(const QString &arg1)
{
    ClassName_s = arg1;
}


void input::on_StuName_textEdited(const QString &arg1)
{
    StuName_s = arg1;
}


void input::on_Method_currentTextChanged(const QString &arg1)
{
    Method_s = arg1;
}


void input::on_next_released()
{
    QDate initDate(2000, 1, 1);
    id_s++;
    ui->ClassName->clear();
    ui->ClassNum->clear();
    ui->StuName->clear();
    ui->Method->setCurrentIndex(0);
    ui->date->setDate(initDate);
}


void input::on_finish_released()
{
    QDate initDate(2000, 1, 1);
    ui->ClassName->clear();
    ui->ClassNum->clear();
    ui->StuName->clear();
    ui->Method->setCurrentIndex(0);
    ui->date->setDate(initDate);
    id_s = 0;
    this->hide();

}


void input::on_save_released()
{
    info info(id_s,date_s,ClassNum_s,ClassName_s,StuName_s,Method_s);
    info.tofile(QString(INFOPATH));
}

