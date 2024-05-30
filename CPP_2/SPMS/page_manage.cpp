#include "page_manage.h"
#include "ui_page_manage.h"

page_manage::page_manage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::page_manage)
{
    ui->setupUi(this);
}

page_manage::~page_manage()
{
    delete ui;
}

void page_manage::on_input_released()
{
    input.show();
}


void page_manage::on_change_released()
{
    change.show();
}


void page_manage::on_view_released()
{
    view.show();
}


void page_manage::on_statistics_released()
{
    statistics.show();
}

