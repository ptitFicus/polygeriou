#ifndef NEWGAMEDIALOGCONTROLLER_H
#define NEWGAMEDIALOGCONTROLLER_H

#include <QObject>
#include <QPushButton>
#include <QListWidgetItem>
#include <QErrorMessage>

#include "mainwindowcontroller.h"
#include "newgamedialog.h"
#include "../model/DictionnaryManager.h"

class MainWindowController;
class NewGameDialogController: public QObject
{
    Q_OBJECT
public:
    NewGameDialogController(NewGameDialog* aView, MainWindowController* controller);
private:
    NewGameDialog* view;
    MainWindowController* mainController;
    DictionnaryManager* dm;
public slots:
    void slotCreateNewGrid();
    void slotCancelGridCreation();
    void slotItemChecked(QListWidgetItem* item);
    void slotAddWord(string dictionnary);

};

#endif // NEWGAMEDIALOGCONTROLLER_H
