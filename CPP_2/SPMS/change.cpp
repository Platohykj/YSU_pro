#include "change.h"
#include "input.h"
#include "ui_change.h"
#include "info.h"
#include "changeinfo.h"

change::change(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::change)
{
    ui->setupUi(this);
    fillTableFromTextFile(ui->tableWidget,QString(INFOPATH));
}

change::~change()
{
    delete ui;
}

int id_c = 0;

void change::on_id_valueChanged(int arg1)
{
    id_c = arg1;
}


void change::on_changeInfo_released()
{
    changeInfo.show();
    qDebug()<< id_c << Qt::endl;
}


void change::on_delet_clicked()
{
    if(confirmOperation(this)){
        deleteRowAndRecomputeId(QString(INFOPATH), id_c);
        fillTableFromTextFile(ui->tableWidget,QString(INFOPATH));
        ui->id->clear();
    }
}


void change::on_pushButton_released()
{
        fillTableFromTextFile(ui->tableWidget,QString(INFOPATH));
}

