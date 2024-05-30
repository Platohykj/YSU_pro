#include "statistics.h"
#include "input.h"
#include "ui_statistics.h"
#include "info.h"
#include "QDate"
#include "QMessageBox"


QDate from;
QDate to;
bool fromischange = false;
bool toischange = false;

statistics::statistics(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::statistics)
{
    ui->setupUi(this);
}

statistics::~statistics()
{
    delete ui;
}


void statistics::on_pushButton_released()
{
    if(fromischange && toischange){
        countNamesInTXT(ui->tableWidget, QString(INFOPATH), from, to);
        fromischange = false;
        toischange = false;
    }
    else
        QMessageBox::critical(nullptr, "错误", "请设置起止时间");
}


void statistics::on_pushButton_2_released()
{
    if(fromischange && toischange){
        displayCourseStatistics(ui->tableWidget, QString(INFOPATH), from, to);
        fromischange = false;
        toischange = false;
    }
    else
        QMessageBox::critical(nullptr, "错误", "请设置起止时间");
}


void statistics::on_from_userDateChanged(const QDate &date)
{
    from = date;
    fromischange = true;
}


void statistics::on_to_userDateChanged(const QDate &date)
{
    to = date;
    toischange = true;
}

