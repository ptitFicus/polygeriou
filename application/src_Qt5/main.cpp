#include "mainwindow.h"
//#include "newgamedialog.h"
#include "dictionnarymanagerdialog.h"
#include "mainwindowcontroller.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    MainWindow w;

    MainWindowController ctrl(&w);
    w.show();
    return a.exec();
}
