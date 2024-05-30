#ifndef VIEW_H
#define VIEW_H

#include <QWidget>

namespace Ui {
class view;
}

class view : public QWidget
{
    Q_OBJECT

public:
    explicit view(QWidget *parent = nullptr);
    ~view();

private slots:
    void on_name_v_textEdited(const QString &arg1);

    void on_search_v_released();

    void on_view_t_released();

private:
    Ui::view *ui;
};

#endif // VIEW_H
