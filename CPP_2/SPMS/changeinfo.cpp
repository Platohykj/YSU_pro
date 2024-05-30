#include "changeinfo.h"
#include "info.h"
#include "input.h"
#include "ui_changeinfo.h"
#include "QDate"
#include <QString>
#include "qdebug.h"


info info;
int id_i;

changeInfo::changeInfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::changeInfo)
{
    ui->setupUi(this);

}

changeInfo::~changeInfo()
{
    delete ui;
}

void changeInfo::on_id_c_valueChanged(int arg1)
{
    id_i = arg1;
}


void changeInfo::on_load_released()
{
    qDebug()<< id_i << Qt::endl;
    info = getInfoById(QString(INFOPATH), id_i);
    qDebug()<< info.date << Qt::endl;
    qDebug()<< QDate::fromString(info.date,"dd/MM/yyyy") << Qt::endl;
    ui->date_c->setDate(QDate::fromString(info.date,"dd/MM/yyyy"));
    ui->classnum_c->setValue(info.ClassNum);
    ui->classname_c->setText(info.ClassName);
    ui->stuname_c->setText(info.StuName);
    ui->method_c->setCurrentText(info.Method);
}


void changeInfo::on_date_c_userDateChanged(const QDate &date)
{
    info.date = date.toString("dd/MM/yyyy");
}


void changeInfo::on_classnum_c_valueChanged(int arg1)
{
    info.ClassNum = arg1;
}


void changeInfo::on_classname_c_textEdited(const QString &arg1)
{
    info.ClassName = arg1;
}


void changeInfo::on_stuname_c_textEdited(const QString &arg1)
{
    info.StuName = arg1;
}


void changeInfo::on_method_c_currentTextChanged(const QString &arg1)
{
    info.Method = arg1;
}


void changeInfo::on_right_released()
{
    QDate initDate(2000, 1, 1);
    modifyInfoData(QString(INFOPATH), info, id_i);
    ui->classname_c->clear();
    ui->classnum_c->clear();
    ui->stuname_c->clear();
    ui->method_c->setCurrentIndex(0);
    ui->date_c->setDate(initDate);
    this->hide();
}


void changeInfo::on_wrong_released()
{
    QDate initDate(2000, 1, 1);
    ui->classname_c->clear();
    ui->classnum_c->clear();
    ui->stuname_c->clear();
    ui->method_c->setCurrentIndex(0);
    ui->date_c->setDate(initDate);
    this->hide();
}

