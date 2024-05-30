#include "info.h"
#include "QFile"
#include "QDebug"
#include "QMessageBox"
#include <QMap>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QTableWidget>
#include <QStringList>
#include <QDebug>
#include <QMap>



/**
 * @brief 比较文件内容与提供的用户名、密码以及用户类型是否匹配。
 *
 * @param filePath 要比较的文件路径。
 * @param username 要检查的用户名。
 * @param password 要检查的密码。
 * @param isteacher 表示用户是否为教师的布尔值。
 * @return 如果找到匹配项则返回true，否则返回false。
 */
bool compareFileContents(const QString &filePath, const QString &username, const QString &password, bool isteacher) {
    QFile file(filePath); // 创建一个 QFile 对象，用于操作文件
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) { // 打开文件进行只读文本模式的读取
        qDebug() << "无法打开文件进行读取：" << file.errorString(); // 如果文件打开失败，输出错误信息
        return false; // 返回失败
    }

    QTextStream in(&file); // 创建 QTextStream 对象，用于读取文件内容
    while (!in.atEnd()) { // 循环读取文件直到结束
        QString line = in.readLine(); // 读取文件中的一行内容
        QStringList parts = line.split(' '); // 以空格分割一行内容为多个部分
        if (parts.size() != 3) { // 如果分割后的部分数量不等于3
            qDebug() << "文件中的行格式无效：" << line; // 输出无效行的信息
            continue; // 继续下一次循环
        }

        QString fileUsername = parts[0]; // 获取分割后的第一个部分，即用户名
        QString filePassword = parts[1]; // 获取分割后的第二个部分，即密码
        bool fileIsTeacher = parts[2].toInt(); // 获取分割后的第三个部分，将其转换为布尔型

        if (fileUsername == username && filePassword == password && fileIsTeacher == isteacher) { // 如果用户名、密码和教师状态都匹配
            qDebug() << "文件中找到匹配项！"; // 输出匹配项信息
            return true; // 返回成功
        }
    }

    qDebug() << "文件中未找到匹配项。"; // 输出未找到匹配项的信息
    return false; // 返回失败

}


/**
 * @brief 检查给定用户名是否存在于文件中。
 *
 * @param filePath 要检查的文件路径。
 * @param username 要检查的用户名。
 * @return 如果用户名存在于文件中则返回true，否则返回false。
 */
bool isUsernameExists(const QString &filePath, const QString &username) {
    QFile file(filePath); // 创建一个 QFile 对象，用于操作文件
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) { // 打开文件进行只读文本模式的读取
        qDebug() << "无法打开文件进行读取：" << file.errorString(); // 如果文件打开失败，输出错误信息
        return false; // 返回失败
    }

    QTextStream in(&file); // 创建 QTextStream 对象，用于读取文件内容
    while (!in.atEnd()) { // 循环读取文件直到结束
        QString line = in.readLine(); // 读取文件中的一行内容
        QStringList parts = line.split(' '); // 以空格分割一行内容为多个部分
        if (parts.size() != 3) { // 如果分割后的部分数量不等于3
            qDebug() << "文件中的行格式无效：" << line; // 输出无效行的信息
            continue; // 继续下一次循环
        }

        QString fileUsername = parts[0]; // 获取分割后的第一个部分，即用户名
        if (fileUsername == username) { // 如果文件中的用户名与传入的用户名相同
            qDebug() << "用户名存在于文件中！"; // 输出用户名存在的信息
            file.close(); // 关闭文件
            return true; // 返回成功
        }
    }

    qDebug() << "用户名不存在于文件中。"; // 输出用户名不存在的信息
    file.close(); // 关闭文件
    return false; // 返回失败

}



/**
 * @brief 将信息写入文件
 *
 * 将信息写入指定文件中。信息格式为：id date ClassNum ClassName StuName Method。
 *
 * @param filepath 文件路径
 */
void info::tofile(const QString &filepath){
    // 打开文件
    QFile file(filepath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Failed to open file for appending:" << file.errorString();
        return;
    }

    // 创建文本流
    QTextStream out(&file);

    // 将信息写入文件
    out << this->id << ' ' << this->date << ' ' << this->ClassNum << ' ' << this->ClassName << ' ' << this->StuName << ' ' << this->Method << Qt::endl;

    // 关闭文件
    file.close();
}



/**
 * @brief 从文件中读取最后一个ID
 *
 * 从指定的文件中读取最后一个ID。
 *
 * @param filepath 文件路径
 * @return 文件中最后一个ID的整数值
 */
int lastid(const QString &filepath){
    // 创建一个 QFile 对象，使用提供的文件路径。
    QFile file(filepath);
    // 将 lastId 初始化为一个 QString，其值为 "0"。
    QString lastId = 0;
    // 检查文件是否可以以文本模式打开进行读取。
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // 创建一个与文件关联的 QTextStream 对象。
        QTextStream in(&file);
        // 循环直到到达文件结尾。
        while (!in.atEnd()) {
            // 从文件中读取一行并将其存储在 'line' 变量中。
            QString line = in.readLine();
            // 使用空格作为分隔符将该行分割成部分，并将它们存储在 'parts' 列表中。
            QStringList parts = line.split(" ");
            // 检查 'parts' 列表是否非空。
            if (!parts.isEmpty()) {
                // 从 'parts' 列表中获取第一个部分（假定为一个ID）。
                QString id = parts.first();
                // 使用当前ID更新 'lastId'。
                lastId = id;
            }
        }
    }
    // 关闭文件。
    file.close();
    // 将 'lastId' QString 转换为整数并返回。
    return lastId.toInt();
}



/**
 * @brief 从文本文件中填充表格
 *
 * 从指定的文本文件中读取数据，并将数据填充到给定的表格中。
 * 每行数据应包含6个字段：ID、日期、课时、课程名称、姓名、缺课类型。
 *
 * @param tableWidget 要填充数据的 QTableWidget 指针
 * @param filename 要读取数据的文本文件路径
 */
void fillTableFromTextFile(QTableWidget *tableWidget, const QString &filename) {
    // 创建一个 QFile 对象，使用提供的文件路径。
    QFile file(filename);
    // 如果文件无法以只读文本模式打开，则直接返回。
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    // 清空表格内容，设置行数为0，列数为6。
    tableWidget->clear();
    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(6);

    // 设置表格的水平表头标签。
    QStringList headers;
    headers << "ID" << "日期" << "课时" << "课程名称" << "姓名" << "缺课类型";
    tableWidget->setHorizontalHeaderLabels(headers);

    // 创建一个与文件关联的 QTextStream 对象。
    QTextStream in(&file);
    int row = 0;
    // 循环直到到达文件结尾。
    while (!in.atEnd()) {
        // 从文件中读取一行并将其存储在 'line' 变量中。
        QString line = in.readLine();
        // 使用空格作为分隔符将该行分割成字段，并将它们存储在 'fields' 列表中。
        QStringList fields = line.split(' ');
        // 如果字段数大于等于6，则将该行数据插入到表格中。
        if (fields.size() >= 6) {
            tableWidget->insertRow(row);
            for (int column = 0; column < 6; ++column) {
                // 创建一个新的 QTableWidgetItem 对象，将字段值设置为该项的文本。
                QTableWidgetItem *item = new QTableWidgetItem(fields[column]);
                // 将该项添加到表格的指定行和列。
                tableWidget->setItem(row, column, item);
            }
            ++row;
        }
    }

    // 关闭文件。
    file.close();
}


/**
 * @brief 删除指定ID的行并重新计算ID
 *
 * 从指定的文件中删除具有指定ID的行，并重新计算剩余行的ID。
 *
 * @param filename 要操作的文件路径
 * @param idToDelete 要删除的行的ID
 */
void deleteRowAndRecomputeId(const QString &filename, int idToDelete) {
    // 创建一个 QFile 对象，使用提供的文件路径。
    QFile file(filename);
    // 如果文件无法以读写文本模式打开，则直接返回。
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    // 创建一个字符串列表，用于存储文件中的每一行数据。
    QStringList lines;
    // 创建一个与文件关联的 QTextStream 对象。
    QTextStream in(&file);
    // 循环直到到达文件结尾。
    while (!in.atEnd()) {
        // 从文件中读取一行并将其存储在 'line' 变量中，然后添加到 'lines' 列表中。
        QString line = in.readLine();
        lines.append(line);
    }
    // 清空文件内容。
    file.resize(0);
    // 初始化当前ID为1。
    int currentId = 1;
    // 创建一个与文件关联的 QTextStream 对象，用于写入新的行数据。
    QTextStream out(&file);
    // 遍历 'lines' 列表中的每一行。
    for (const QString &line : lines) {
        // 使用空格作为分隔符将该行分割成字段，并将它们存储在 'fields' 列表中。
        QStringList fields = line.split(' ');
        // 如果字段列表为空，则继续到下一行。
        if (fields.isEmpty())
            continue;
        // 将该行的第一个字段（ID）转换为整数类型。
        int id = fields[0].toInt();
        // 如果该行的ID不等于要删除的ID，则将其添加到文件中，并更新其ID为当前ID值。
        if (id != idToDelete) {
            fields[0] = QString::number(currentId++);
            out << fields.join(' ') << '\n';
        }
    }
    // 关闭文件。
    file.close();
}



/**
 * @brief 确认操作
 *
 * 显示一个询问对话框，让用户确认是否执行操作。
 *
 * @param parent 父窗口部件指针，用于指定对话框的父对象
 * @return 如果用户选择“是”，则返回 true，否则返回 false
 */
bool confirmOperation(QWidget *parent) {
    // 创建一个标准按钮对象，并显示一个包含指定文本和按钮选项的询问对话框。
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(parent, "注意", "你确定要删除吗",
                                  QMessageBox::Yes | QMessageBox::No);
    // 如果用户选择“是”，则返回 true，否则返回 false。
    return reply == QMessageBox::Yes;
}



/**
 * @brief 修改信息数据
 *
 * 在指定的文件中修改具有指定ID的行的信息数据。
 *
 * @param filename 要操作的文件路径
 * @param infoObj 包含要更新的信息的 info 对象
 * @param idToModify 要修改的行的ID
 */
void modifyInfoData(const QString &filename, const info &infoObj, int idToModify) {
    // 创建一个 QFile 对象，使用提供的文件路径。
    QFile file(filename);
    // 如果文件无法以读写文本模式打开，则直接返回。
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    // 创建一个字符串列表，用于存储文件中的每一行数据。
    QStringList lines;
    // 创建一个与文件关联的 QTextStream 对象。
    QTextStream in(&file);
    // 循环直到到达文件结尾。
    while (!in.atEnd()) {
        // 从文件中读取一行并将其存储在 'line' 变量中，然后添加到 'lines' 列表中。
        QString line = in.readLine();
        lines.append(line);
    }
    // 清空文件内容。
    file.resize(0);
    // 创建一个与文件关联的 QTextStream 对象，用于写入新的行数据。
    QTextStream out(&file);
    // 遍历 'lines' 列表中的每一行。
    for (const QString &line : lines) {
        // 使用空格作为分隔符将该行分割成字段，并将它们存储在 'fields' 列表中。
        QStringList fields = line.split(' ');
        // 如果字段列表为空，则继续到下一行。
        if (fields.isEmpty())
            continue;
        // 将该行的第一个字段（ID）转换为整数类型。
        int id = fields[0].toInt();
        // 如果该行的ID等于要修改的ID，则将新的信息数据写入文件。
        if (id == idToModify) {
            out << infoObj.id << ' ' << infoObj.date << ' ' << infoObj.ClassNum << ' ' << infoObj.ClassName << ' ' << infoObj.StuName << ' ' << infoObj.Method << '\n';
        } else {
            // 否则将原始行写入文件。
            out << line << '\n';
        }
    }
    // 关闭文件。
    file.close();
}



/**
 * @brief 通过ID从文件中获取信息
 *
 * 从指定的文件中查找具有指定ID的信息，并返回对应的 info 对象。
 * 如果找不到对应ID的信息，则返回一个默认构造的 info 对象。
 *
 * @param filename 要搜索的文件路径
 * @param idToFind 要查找的信息的ID
 * @return 包含指定ID信息的 info 对象，如果找不到则返回默认构造的 info 对象
 */
info getInfoById(const QString &filename, int idToFind) {
    // 创建一个 QFile 对象，使用提供的文件路径。
    QFile file(filename);
    // 如果文件无法以只读文本模式打开，则返回默认构造的 info 对象。
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return info(0, "", 0, "", "", "");
    // 创建一个与文件关联的 QTextStream 对象。
    QTextStream in(&file);
    // 循环直到到达文件结尾。
    while (!in.atEnd()) {
        // 从文件中读取一行并将其存储在 'line' 变量中。
        QString line = in.readLine();
        // 使用空格作为分隔符将该行分割成字段，并将它们存储在 'fields' 列表中。
        QStringList fields = line.split(' ');
        // 如果字段列表为空，则继续到下一行。
        if (fields.isEmpty())
            continue;
        // 将该行的第一个字段（ID）转换为整数类型。
        int id = fields[0].toInt();
        // 如果该行的ID等于要查找的ID，则根据字段创建一个 info 对象并返回。
        if (id == idToFind) {
            return info(id,
                        fields[1],
                        fields[2].toInt(),
                        fields[3],
                        fields[4],
                        fields[5]);
        }
    }
    // 如果找不到对应ID的信息，则返回默认构造的 info 对象。
    return info(0, "", 0, "", "", "");
}



/**
 * @brief 加载表格数据
 *
 * 从指定的文件中加载数据到表格中，仅加载指定姓名的行数据。
 *
 * @param filePath 要读取数据的文件路径
 * @param name 要筛选的姓名
 * @param tableWidget 要填充数据的 QTableWidget 指针
 */
void loadTableData(const QString &filePath, const QString &name, QTableWidget *tableWidget) {
    // 创建一个 QFile 对象，使用提供的文件路径。
    QFile file(filePath);
    // 如果文件无法以只读文本模式打开，则打印错误信息并返回。
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for reading";
        return;
    }
    // 设置表格行数为0。
    tableWidget->setRowCount(0);
    // 创建一个与文件关联的 QTextStream 对象。
    QTextStream in(&file);
    int row = 0;
    // 循环直到到达文件结尾。
    while (!in.atEnd()) {
        // 从文件中读取一行并将其存储在 'line' 变量中。
        QString line = in.readLine();
        // 使用空格作为分隔符将该行分割成字段，并将它们存储在 'fields' 列表中。
        QStringList fields = line.split(' ');
        // 如果字段数为6且第5个字段（姓名）等于指定姓名，则将该行数据添加到表格中。
        if (fields.size() == 6 && fields[4] == name) {
            // 插入一行到表格中。
            tableWidget->insertRow(row);
            // 遍历该行的字段并将每个字段添加到表格对应位置。
            for (int col = 0; col < fields.size(); ++col) {
                tableWidget->setItem(row, col, new QTableWidgetItem(fields[col]));
            }
            row++;
        }
    }
    // 关闭文件。
    file.close();
}



/**
 * @brief 统计文本文件中指定日期范围内学生出勤次数
 *
 * 从指定的文本文件中统计在指定日期范围内每位学生的出勤次数，并将结果填充到表格中显示。
 *
 * @param tableWidget 要填充数据的 QTableWidget 指针
 * @param filePath 要读取的文本文件路径
 * @param from 开始日期范围
 * @param to 结束日期范围
 */
void countNamesInTXT(QTableWidget *tableWidget, const QString &filePath, QDate &from, QDate &to) {
    // 打开文件
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;  // 文件打开失败，直接返回
    }

    // 统计学生名字出现的次数
    QMap<QString, int> studentCountMap;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(' ');
        if (fields.size() >= 6) {
            QString dateStr = fields[1];
            QString stuName = fields[4];
            QDate date = QDate::fromString(dateStr, "dd/MM/yyyy");

            if (date.isValid() && date >= from && date <= to) {
                studentCountMap[stuName]++;
            }
        }
    }
    file.close();

    // 将统计结果转换为可排序的列表
    QList<QPair<QString, int>> studentCountList;
    for (auto it = studentCountMap.begin(); it != studentCountMap.end(); ++it) {
        studentCountList.append(qMakePair(it.key(), it.value()));
    }

    // 按出现次数降序排序
    std::sort(studentCountList.begin(), studentCountList.end(), [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
        return b.second > a.second;
    });

    // 设置表格行数和列数
    tableWidget->setRowCount(studentCountList.size());
    tableWidget->setColumnCount(2);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "缺勤次数");

    // 填充表格数据
    for (int i = 0; i < studentCountList.size(); ++i) {
        QTableWidgetItem* nameItem = new QTableWidgetItem(studentCountList[i].first);
        QTableWidgetItem* countItem = new QTableWidgetItem(QString::number(studentCountList[i].second));
        tableWidget->setItem(i, 0, nameItem);
        tableWidget->setItem(i, 1, countItem);
    }

    // 调整列宽以适应内容
    tableWidget->resizeColumnsToContents();
}


/**
 * @brief 显示课程统计信息
 *
 * 从指定的文件中读取数据，并统计在指定日期范围内每个课程的缺勤人次，
 * 然后将统计结果填充到表格中显示。
 *
 * @param tableWidget 要填充数据的 QTableWidget 指针
 * @param filePath 要读取的文本文件路径
 * @param from 开始日期范围
 * @param to 结束日期范围
 */
void displayCourseStatistics(QTableWidget* tableWidget, const QString& filePath, QDate& from, QDate& to) {
    // 打开文件
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Cannot open file for reading");
        return;
    }

    QTextStream in(&file);
    QMap<QString, int> courseCount;

    // 逐行读取文件并统计课程名字
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(' ');
        if (fields.size() >= 6) {
            QString dateStr = fields[1];
            QDate date = QDate::fromString(dateStr, "dd/MM/yyyy");
            if (date.isValid() && date >= from && date <= to) {
                QString courseName = fields[3];
                courseCount[courseName]++;
            }
        }
    }

    // 关闭文件
    file.close();

    // 将统计结果转为 QVector<QPair<QString, int>> 以便排序
    QVector<QPair<QString, int>> courseList;
    for (auto it = courseCount.begin(); it != courseCount.end(); ++it) {
        courseList.append(qMakePair(it.key(), it.value()));
    }

    // 按出现次数降序排序
    std::sort(courseList.begin(), courseList.end(), [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
        return b.second > a.second;
    });

    // 设置表格行数和列数
    tableWidget->setRowCount(courseList.size());
    tableWidget->setColumnCount(2);

    // 设置表格头部
    QStringList headers;
    headers << "课程名称" << "缺勤人次";
    tableWidget->setHorizontalHeaderLabels(headers);

    // 填充表格数据
    for (int i = 0; i < courseList.size(); ++i) {
        tableWidget->setItem(i, 0, new QTableWidgetItem(courseList[i].first));
        tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(courseList[i].second)));
    }

    // 调整列宽以适应内容
    tableWidget->resizeColumnsToContents();
}
