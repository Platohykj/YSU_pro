#ifndef PAGE_MANAGE_H
#define PAGE_MANAGE_H

#include <QWidget>
#include "input.h"
#include "change.h"
#include "view.h"
#include "statistics.h"

namespace Ui {
class page_manage;
}

class page_manage : public QWidget
{
    Q_OBJECT

public:
    explicit page_manage(QWidget *parent = nullptr);
    ~page_manage();

private slots:
    void on_input_released();

    void on_change_released();

    void on_view_released();

    void on_statistics_released();

private:
    Ui::page_manage *ui;
    input input;
    change change;
    view view;
    statistics statistics;
};

#endif // PAGE_MANAGE_H
