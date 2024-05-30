#ifndef INFO_H
#define INFO_H
#include "QString"
#include "QDebug"
#include "QFile"
#include "QTableWidget"
#include "QDate"



class info
{
public:
    int id;
    QString date;
    int ClassNum;
    QString ClassName;
    QString StuName;
    QString Method;
    info(int id, QString date, int ClassNum, QString ClassName, QString StuName, QString Method): id(id), date(date), ClassNum(ClassNum), ClassName(ClassName), StuName(StuName), Method(Method){}
    info(){};

    void tofile(const QString &filepath);



    ~info()
    {
        qDebug() << "Destructor called" << Qt::endl;
    }
};

bool compareFileContents(const QString &filePath, const QString &username, const QString &password, bool isteacher);
bool isUsernameExists(const QString &filePath, const QString &username);
int lastid(const QString &filepath);
void fillTableFromTextFile(QTableWidget *tableWidget, const QString &filename);
void deleteRowAndRecomputeId(const QString &filename, int idToDelete);
bool confirmOperation(QWidget *parent);
void modifyInfoData(const QString &filename, const info &infoObj, int idToModify);
info getInfoById(const QString &filename, int idToFind);
void loadTableData(const QString &filePath, const QString &name, QTableWidget *tableWidget);
void countNamesInTXT(QTableWidget *tableWidget, const QString &filePath, QDate &from, QDate &to);
void displayCourseStatistics(QTableWidget* tableWidget, const QString& filePath, QDate &from, QDate &to);

#endif // INFO_H
