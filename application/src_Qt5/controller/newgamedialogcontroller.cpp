#include "newgamedialogcontroller.h"

NewGameDialogController::NewGameDialogController(NewGameDialog *aView, MainWindowController *controller):
    view(aView), mainController(controller)
{
    QListWidget* dictionnariesList = view->getDictionnaryList();
    dm = mainController->getDictionnaryManager();
    list<string> nameList = dm->getDictionnaryNames();

    unsigned int i;
    for(list<string>::iterator it=nameList.begin();
        it != nameList.end(); it++)
    {
        QListWidgetItem* listItem = new QListWidgetItem(QString::fromStdString(*it), dictionnariesList);
        listItem->setFlags(listItem->flags() | Qt::ItemIsUserCheckable);
        listItem->setCheckState(Qt::Unchecked);
        dictionnariesList->addItem(listItem);
        i++;
    }

    connect(dictionnariesList, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(slotItemChecked(QListWidgetItem*)));
    connect(view->getValidationButton(), SIGNAL(clicked()), this, SLOT(slotCreateNewGrid()));
    connect(view->getCancelButton(), SIGNAL(clicked()), this,SLOT(slotCancelGridCreation()));
    connect(dm, SIGNAL(dictionnaryAdded(string)), this, SLOT(slotAddWord(string)));
}

void NewGameDialogController::slotCreateNewGrid()
{
    QListWidget* dictionnariesList = view->getDictionnaryList();
    vector<string> dictionnaries;

    for(int i = 0 ; i < dictionnariesList->count() ; i++)
    {
        if(dictionnariesList->item(i)->checkState() == Qt::Checked)
        {
            string dictionnary_name = (dictionnariesList->item(i)->text()).toUtf8().constData();
            dictionnaries.push_back(dictionnary_name);
        }
    }
    int heigth = view->getHeightBox()->value();
    int width = view->getWidthBox()->value();

    mainController->generateGrid(heigth, width, dictionnaries);
}

void NewGameDialogController::slotCancelGridCreation()
{
    view->setVisible(false);
}

void NewGameDialogController::slotItemChecked(QListWidgetItem *item)
{
    bool check = false;
    QListWidget* dicList = view->getDictionnaryList();
    for(int i = 0 ; i < dicList->count() ; i++)
    {
        if(dicList->item(i)->checkState() == Qt::Checked)
        {
            check = true;
            break;
        }
    }
    if(!check)
    {
        view->getValidationButton()->setEnabled(false);
    }
    else
        view->getValidationButton()->setEnabled(true);
}

void NewGameDialogController::slotAddWord(string dictionnary){
    QListWidget* dictionnariesList = view->getDictionnaryList();

    QListWidgetItem* listItem = new QListWidgetItem(qPrintable(dictionnary.c_str()), dictionnariesList);
    listItem->setFlags(listItem->flags() | Qt::ItemIsUserCheckable);
    listItem->setCheckState(Qt::Unchecked);
    dictionnariesList->addItem(listItem);
}
