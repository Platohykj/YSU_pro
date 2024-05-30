#include <QApplication>
#include "page_login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    page_login p;
    p.show();
    return a.exec();
}
