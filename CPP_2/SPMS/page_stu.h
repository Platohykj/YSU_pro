#ifndef PAGE_STU_H
#define PAGE_STU_H

#include <QWidget>

namespace Ui {
class page_stu;
}

class page_stu : public QWidget
{
    Q_OBJECT

public:
    explicit page_stu(QWidget *parent = nullptr);
    ~page_stu();

private slots:
    void on_lineEdit_textEdited(const QString &arg1);

    void on_pushButton_released();

    void on_pushButton_2_released();

private:
    Ui::page_stu *ui;
};

#endif // PAGE_STU_H
