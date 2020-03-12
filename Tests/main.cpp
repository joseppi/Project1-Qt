#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setOrganizationName("PiPo");
    QApplication::setOrganizationDomain("www.github.com/joseppi");
    QApplication::setApplicationName("Cute Engine");

    MainWindow w;
    w.show();

    return a.exec();
}
