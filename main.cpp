#include "mainwindow.h"
#include "databaseinit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseInit init;
    MainWindow w;
    w.show();

    return a.exec();
}
