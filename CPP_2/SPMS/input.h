#ifndef INPUT_H
#define INPUT_H

#define INFOPATH ".\\info.txt"
#include <QWidget>

namespace Ui {
class input;
}

class input : public QWidget
{
    Q_OBJECT

public:
    explicit input(QWidget *parent = nullptr);
    ~input();

private slots:
    void on_date_userDateChanged(const QDate &date);

    void on_ClassNum_valueChanged(int arg1);

    void on_ClassName_textEdited(const QString &arg1);

    void on_StuName_textEdited(const QString &arg1);

    void on_Method_currentTextChanged(const QString &arg1);

    void on_next_released();

    void on_finish_released();

    void on_save_released();

private:
    Ui::input *ui;
};

#endif // INPUT_H
