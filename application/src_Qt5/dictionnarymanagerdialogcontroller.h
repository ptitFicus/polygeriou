#ifndef DICTIONNARYMANAGERDIALOGCONTROLLER_H
#define DICTIONNARYMANAGERDIALOGCONTROLLER_H

#include <QObject>
#include <QFile>
#include "selectnamedialog.h"
#include "ui_selectnamedialog.h"
#include "dictionnarymanagerdialog.h"
#include "DictionnaryManager.h"
#include "ui_dictionnarymanagerdialog.h"
#include "normalisersaisie.h"
#include <QStringList>
#include <iostream>
#include <QFileDialog>
#include <map>
#include <string>
#include <QTextCodec>
#include <fstream>
#include <QMessageBox>
#include <QProgressBar>


class DictionnaryManagerDialogController : public QObject
{
     Q_OBJECT
public:
    DictionnaryManagerDialogController(DictionnaryManager* dm, QWidget *parent = 0);
    ~DictionnaryManagerDialogController();

    void importDictionnaire(string filePath);
    void show();

public slots:
    void slotImportDictionnary();
    void slotDeleteDictionnary();
    void slotSelectDictionnary(QString dict);
    void slotModifyWord(int row, int column);
    void slotDeleteWord();
    void slotAddWord();
    void slotCreateDictionnary();
    void slotActualize();
    void slotSaveChanges();
    void slotImportDictionnaryDM(string name);
    void slotSearchWord(QString string);
private :
    DictionnaryManagerDialog* dialog;
    DictionnaryManager* dm;
    string dictionnaire;
    bool modify;
    bool initialized;
    string lastPath;
    vector<string> *oldWords;
    vector< vector<string> > *oldDefinitions;
    vector<string> *newWords;
    vector< vector<string> > *newDefinitions;
    SelectNameDialog *awDialog;
    SelectNameDialog *sdDialog;
    void removeLine(int line);

};

#endif // DICTIONNARYMANAGERDIALOGCONTROLLER_H
