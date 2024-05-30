#ifndef STATISTICS_H
#define STATISTICS_H

#include <QWidget>

namespace Ui {
class statistics;
}

class statistics : public QWidget
{
    Q_OBJECT

public:
    explicit statistics(QWidget *parent = nullptr);
    ~statistics();

private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

    void on_from_userDateChanged(const QDate &date);

    void on_to_userDateChanged(const QDate &date);

private:
    Ui::statistics *ui;
};

#endif // STATISTICS_H
