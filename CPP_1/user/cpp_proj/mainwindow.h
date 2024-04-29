#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QList>
#include "student.h"




QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void loadData(const QString& name);

private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

    void on_pushButton_4_released();

    void on_pushButton_6_released();

    void on_signinbutton_released();

    void on_loginbutton_released();

    void on_loginname_textEdited(const QString &arg1);

    void on_loginpassword_textEdited(const QString &arg1);

    void on_signinname_textEdited(const QString &arg1);

    void on_signinpassword1_textEdited(const QString &arg1);

    void on_signinpassword2_textEdited(const QString &arg1);

    void on_isteacher_stateChanged(int arg1);

    void on_addbutt_released();

    void on_name_textEdited(const QString &arg1);

    void on_age_textEdited(const QString &arg1);

    void on_height_textEdited(const QString &arg1);

    void on_weight_textEdited(const QString &arg1);

    void on_id_textEdited(const QString &arg1);

    void on_gender_textEdited(const QString &arg1);

    void on_grade_textEdited(const QString &arg1);

    void on_score_textEdited(const QString &arg1);

    void on_rank_textEdited(const QString &arg1);

    void on_salary_textEdited(const QString &arg1);

    void on_nextbutt_released();

    void on_finishbut_released();

    void on_classnum_textEdited(const QString &arg1);

    void on_searchbutt_released();


    void on_names_textEdited(const QString &arg1);

    void on_ages_textEdited(const QString &arg1);

    void on_heights_textEdited(const QString &arg1);

    void on_weights_textEdited(const QString &arg1);

    void on_ids_textEdited(const QString &arg1);

    void on_genders_textEdited(const QString &arg1);

    void on_grades_textEdited(const QString &arg1);

    void on_class_s_textEdited(const QString &arg1);

    void on_scores_textEdited(const QString &arg1);

    void on_ranks_textEdited(const QString &arg1);

    void on_salarys_textEdited(const QString &arg1);

    void on_isteachers_stateChanged(int arg1);

    void on_searchbutts_released();

    void on_quitbutts_released();

    void on_back_released();

    void on_statbutt_released();



    void on_del_line_textEdited(const QString &arg1);

    void on_pushButton_3_released();

    void on_pushButton_5_released();

    void on_delbutt_released();

    void on_delbutt_2_released();

private:
    Ui::MainWindow *ui;

    QStringList names;
    QList<Student*> m_students;


};
#endif // MAINWINDOW_H
