#include "view.h"
#include "input.h"
#include "ui_view.h"
#include "qstring.h"
#include "info.h"
#include "qdebug.h"

view::view(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::view)
{
    ui->setupUi(this);

}

view::~view()
{
    delete ui;
}


QString name_v;
void view::on_name_v_textEdited(const QString &arg1)
{
    name_v = arg1;
}


void view::on_search_v_released()
{
    qDebug()<< name_v << Qt::endl;
    loadTableData(QString(INFOPATH), name_v, ui->tableWidget);
}


void view::on_view_t_released()
{
    fillTableFromTextFile(ui->tableWidget,QString(INFOPATH));
}

