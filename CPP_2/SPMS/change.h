#ifndef CHANGE_H
#define CHANGE_H

#include <QWidget>
#include "changeinfo.h"

namespace Ui {
class change;
}

class change : public QWidget
{
    Q_OBJECT

public:
    explicit change(QWidget *parent = nullptr);
    ~change();


private slots:

    void on_id_valueChanged(int arg1);

    void on_changeInfo_released();

    void on_delet_clicked();

    void on_pushButton_released();

private:
    Ui::change *ui;
    changeInfo changeInfo;
};

#endif // CHANGE_H
