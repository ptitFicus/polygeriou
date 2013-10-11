#include "mainwindow.h"
//#include "newgamedialog.h"
#include "dictionnarymanagerdialog.h"
#include "mainwindowcontroller.h"
#include <iostream>
#include <QApplication>
#include <QTranslator>
#include <QLocale>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    cout << "coucou";
    QApplication a(argc, argv);

    QTranslator translator(0);
    QString locale = QLocale::system().name();
    QChar lang[3];
    lang[0] = locale[0].toLower();
    lang[1] = locale[1].toLower();
    lang[2] = '\0';
    QString langstr(lang);
    bool result = translator.load("polygeriou_"+ langstr);


    bool result2 =a.installTranslator(&translator);

    if(result && result2) {

        MainWindow w;
    MainWindowController ctrl(&w);
    w.show();
    return a.exec();
    }
    else
        return -1;


}
