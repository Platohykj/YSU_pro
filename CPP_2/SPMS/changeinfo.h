#ifndef CHANGEINFO_H
#define CHANGEINFO_H

#include <QWidget>

namespace Ui {
class changeInfo;
}

class changeInfo : public QWidget
{
    Q_OBJECT

public:
    explicit changeInfo(QWidget *parent = nullptr);
    ~changeInfo();

private slots:
    void on_id_c_valueChanged(int arg1);

    void on_load_released();

    void on_date_c_userDateChanged(const QDate &date);

    void on_classnum_c_valueChanged(int arg1);

    void on_classname_c_textEdited(const QString &arg1);

    void on_stuname_c_textEdited(const QString &arg1);

    void on_method_c_currentTextChanged(const QString &arg1);

    void on_right_released();

    void on_wrong_released();

private:
    Ui::changeInfo *ui;
};

#endif // CHANGEINFO_H
