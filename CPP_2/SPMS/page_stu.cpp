#include "page_stu.h"
#include "input.h"
#include "ui_page_stu.h"
#include "info.h"

page_stu::page_stu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::page_stu)
{
    ui->setupUi(this);
}

page_stu::~page_stu()
{
    delete ui;
}
QString name_t;
void page_stu::on_lineEdit_textEdited(const QString &arg1)
{
    name_t = arg1;
}


void page_stu::on_pushButton_released()
{
    loadTableData(QString(INFOPATH), name_t, ui->tableWidget);
}


void page_stu::on_pushButton_2_released()
{
    fillTableFromTextFile(ui->tableWidget,QString(INFOPATH));
}

