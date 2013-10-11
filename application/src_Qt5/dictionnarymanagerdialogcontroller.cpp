#include "dictionnarymanagerdialogcontroller.h"

using namespace std;

/**
 * Constructeur du controleur
 * @brief DictionnaryManagerDialogController::DictionnaryManagerDialogController
 * @param dialog La  vue qui va être modifiée
 * @param dm Le modèle qui va permettre l'affichage et qui va être modifiée
 */
DictionnaryManagerDialogController::DictionnaryManagerDialogController(DictionnaryManager *dm, QWidget *parent)
{
    this->dialog = new DictionnaryManagerDialog(parent);
    this->awDialog = new SelectNameDialog(parent);
    this->sdDialog = new SelectNameDialog(parent);

    this->dm = dm;

    this->oldWords = new vector<string>();
    this->newWords = new vector<string>();
    this->oldDefinitions = new vector< vector<string> >();
    this->newDefinitions = new vector< vector<string> >();

    // Connection entre les signaux envoyés par l'interface graphique et les slots du contoleur
    connect(dialog->getUi()->boutonImporter, SIGNAL(clicked()), this, SLOT(slotImportDictionnary()));
    connect(dialog->getUi()->boutonSupprimer, SIGNAL(clicked()), this, SLOT(slotDeleteDictionnary()));
    connect(dialog->getUi()->dictionnaires, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotSelectDictionnary(QString)));
    connect(dialog->getUi()->deleteWord, SIGNAL(clicked()), this, SLOT(slotDeleteWord()));
    connect(dialog->getUi()->addWord, SIGNAL(clicked()), awDialog, SLOT(show()));
    connect(dialog->getUi()->createDictionnary, SIGNAL(clicked()), sdDialog, SLOT(show()));
    connect(dialog->getUi()->definitions, SIGNAL(cellChanged(int,int)), this, SLOT(slotModifyWord(int,int)));
    //connect(dialog->getUi()->definitions, SIGNAL(cellClicked(int,int)), this, SLOT(slotControlCell(int,int)));

    connect(dialog->getUi()->buttonBox, SIGNAL(accepted()), this, SLOT(slotSaveChanges()));
    connect(dialog->getUi()->buttonBox, SIGNAL(rejected()), dialog, SLOT(hide()));

    connect(dm, SIGNAL(wordAdded()), this, SLOT(slotActualize()));
    connect(dm, SIGNAL(dictionnaryAdded(string)), this, SLOT(slotImportDictionnaryDM(string)));

    connect(awDialog, SIGNAL(accepted()), this, SLOT(slotAddWord()));
    connect(sdDialog, SIGNAL(accepted()), this, SLOT(slotCreateDictionnary()));

    connect(dialog->getUi()->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(slotSearchWord(QString)));

    // A l'initialisation, on importe tous les dictionnaires qui étaient déjà importés auparavant
    ifstream fichier(".dictionnaires.txt", ios::in);
    if(fichier){
        string ligne;
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
            this->importDictionnaire(ligne);
            lastPath = ligne; // On enregistre le chemin
        }
    }
    initialized = true;

    fichier.close();
}

void DictionnaryManagerDialogController::show(){
    dialog->show();
}

DictionnaryManagerDialogController::~DictionnaryManagerDialogController(){
    delete oldDefinitions;
    delete oldWords;
    delete newDefinitions;
    delete newWords;
}

/**
 * Slot qui permet la création d'un dictionnaire
 * @brief DictionnaryManagerDialogController::slotCreateDictionnary
 */
void DictionnaryManagerDialogController::slotCreateDictionnary(){
    QString currentPath = QDir::currentPath();
    QString name = sdDialog->getUi()->lineEdit->text();
    string path = currentPath.toStdString() + "/" + name.toStdString() + ".txt";
    if((dialog->getUi()->dictionnaires->findText(name)) == -1){


        ofstream myfile;
        myfile.open (".dictionnaires.txt", ios::app);
        myfile << path << endl;
        myfile.close();

        myfile.open(path, ios::app);
        myfile << "" << endl;
        myfile.close();

        importDictionnaire(path);

    }else{
        QMessageBox messageBox;
        messageBox.information(0, tr("Error"), tr("This dictionnary already exists"));
        messageBox.setFixedSize(500,200);
    }

    awDialog->getUi()->lineEdit->clear();
}

/**
 * Slot qui permet l'import de dictionnaire
 * @brief DictionnaryManagerDialogController::slotImportDictionnary
 */
void DictionnaryManagerDialogController::slotImportDictionnary(){

    // Ouverture d'une fenêtre permettant de selectionner le fichier à importer
    QString fileName = QFileDialog::getOpenFileName(dialog, tr("Select dictionnary"),QString(lastPath.c_str()), tr("Dictionnary File(*.txt)"), 0, QFileDialog::DontUseNativeDialog);
    if(!fileName.isEmpty()){
        string filePath = qPrintable(fileName);

        // On cherche le nom du fichier sans l'extansion ni le chemin, ce sera le nom donné  à notre dictionnaire
        unsigned found = filePath.find_last_of("/\\");
        unsigned txt = filePath.find(".");
        string file = filePath.substr(found+1, txt-found-1);

        // Test si le dictionnaire est déjà présent dans la liste des dictionnaires
        if((dialog->getUi()->dictionnaires->findText(QString(file.c_str()))) == -1){

            ofstream myfile;
            myfile.open (".dictionnaires.txt", ios::app);
            myfile << filePath << endl;
            myfile.close();

            // On ajoute le dictionnaire au dictionnaryManager
            importDictionnaire(filePath);

        }else{
            QMessageBox messageBox;
            messageBox.information(0, tr("Error"), tr("This dictionnary already exists"));
            messageBox.setFixedSize(500,200);
        }

    }
}

void DictionnaryManagerDialogController::slotImportDictionnaryDM(string name){

    // On ajoute le dictionnaire à la liste des dictionnaires et on le selectionne
    dialog->getUi()->dictionnaires->addItem(QString(name.c_str()));

}

/**
 * Méthode qui importe le fichier passé en paramètre
 * @brief DictionnaryManagerDialogController::importDictionnaire
 * @param filePath Le chemin du fichier à importer
 * @param init Indique si c'est la phase d'initialisation ou non
 */
void DictionnaryManagerDialogController::importDictionnaire(string filePath){

    // On cherche le nom du fichier sans l'extansion ni le chemin, ce sera le nom donné  à notre dictionnaire
    unsigned found = filePath.find_last_of("/\\");
    unsigned txt = filePath.find(".");
    string file = filePath.substr(found+1, txt-found-1);

    if(dialog->getUi()->dictionnaires->findText(qPrintable(file.c_str())) == -1){
        // On ajoute le dictionnaire au dictionnaryManager
        dm->addDictionnary(file, filePath);
    }
}

/**
 * Slot qui supprime le dictionnaire en cours d'utilisation
 * @brief DictionnaryManagerDialogController::slotDeleteDictionnary
 */
void DictionnaryManagerDialogController::slotDeleteDictionnary(){

    int index = dialog->getUi()->dictionnaires->currentIndex();
    QString dictionnaire = dialog->getUi()->dictionnaires->itemText(index);
    string question = tr("Are you sure you want to delete the dictionnary ").toStdString() + dictionnaire.toStdString() + "?";
    // Demande à l'utilisateur confirmation de la suppression
    QMessageBox messageBox;
    QMessageBox::StandardButton button = messageBox.question(0, tr("Confirm"), QString(question.c_str()), QMessageBox::Yes|QMessageBox:: No);
    messageBox.setFixedSize(500,200);

    if(button == QMessageBox::Yes){

        // Il doit au moins rester un élément dans la liste
        if(dialog->getUi()->dictionnaires->count() == 1){
            QMessageBox messageBox;
            messageBox.information(0, tr("Error"), tr("An element should remain in the list"));
            messageBox.setFixedSize(500,200);
        }else{
            // Suppression du dictionnaire de la liste
            dialog->getUi()->dictionnaires->removeItem(index);
            removeLine(index);
        }

    }
}

/**
 * Slot activé après la selection d'un dictionnaire dans la liste, il affiche le dictionnaire sélectionné
 * @brief DictionnaryManagerDialogController::slotSelectDictionnary
 * @param dict Le dictionnaire sélectionné
 */
void DictionnaryManagerDialogController::slotSelectDictionnary(QString dict){
    // Déplace le curseur sur le fichier (utile lors de l'initialisation)
    int index = dialog->getUi()->dictionnaires->findText(dict);
    dialog->getUi()->dictionnaires->setCurrentIndex(index);

    // Indique qu'on est pas en mode modification (n'appelle pas le slot modifyWord lorsqu'on change une case)
    modify = false;

    // On charge le contenu
    dictionnaire = qPrintable(dict);
    map<string, vector<string> > contenu = dm->getContent(dictionnaire);
    map<string, vector<string> >::iterator it;


    // Création de la barre de progression
    QProgressBar *barre = new QProgressBar();
    barre->setMinimum(0);
    barre->setMaximum(contenu.size());
    barre->setVisible(true);

    // Calcul du nombre maximum de définitions afin d'initialiser le nombre de colonnes
    int tailleDefinitions = 0;
    for(it=contenu.begin() ; it!=contenu.end() ; it++){
        int tmpSize = it->second.size();
        if(tmpSize > tailleDefinitions) tailleDefinitions = tmpSize;
    }

    tailleDefinitions = tailleDefinitions + 1;

    // On efface la table affichée
    QTableWidget* table = dialog->getUi()->definitions;
    table->clear();

    QTableWidgetItem* itemMot;
    QTableWidgetItem* itemDefinition;

    // On initialise le nombre de lignes et de colonnes de la table
    table->setColumnCount(tailleDefinitions+1);
    table->setRowCount(contenu.size());

    // i nous permet de mettre à jour la barre de progression
    int i = 0;

    // On parcourt le dictionnaire afin d'afficher chaque élément
    // On commence par parcourir les mots
    for(it=contenu.begin() ; it!=contenu.end() ; it++)
    {

        // Création de l'item qui sera à ajouter à la table
        itemMot = new QTableWidgetItem(QString((it->first).c_str()));
        vector<string>::iterator vIt;
        vector<string> vect = it->second;

        barre->setValue(i);

        int j = 0;
        // On parcourt toutes les définitions du mot afin de les ajouter
        for(vIt = vect.begin(); vIt!=vect.end(); vIt++){

            j++;

            if(j >= table->columnCount())
                table->setColumnCount(j+1);

            // Création d'un item pour chaque définition
            itemDefinition = new QTableWidgetItem(QString((*vIt).c_str()));
            // Ajout de l'item à la table représentant le dictionnaire
            table->setItem(i, j, itemDefinition);

        }

        // Ajout de l'item du mot dans la table
        itemMot = new QTableWidgetItem(QString((it->first).c_str()));
        table->setItem(i, 0, itemMot);

        i++;
    }

    barre->setVisible(false);
    delete barre;

    modify = true;
}

/**
 * @brief DictionnaryManagerDialogController::slotModifyWord
 * @param row La ligne de la cellule modifiée
 * @param column La colonne de la cellule modifiée
 */
void DictionnaryManagerDialogController::slotModifyWord(int row, int column){

    // On teste si on doit faire appel à cette méthode
    if(modify){

        // Récupération du contenu du dictionnaire
        map<string, vector<string>> contenu = dm->getContent(dictionnaire);
        map<string, vector<string> >::iterator it;

        // Variables qui stockeront les anciens mots et définitions afin de les mettre à jour
        string ancienMot;
        vector<string> anciennesDefinitions;

        // On cherche le mot et les définitions de la ligne du mot modifié
        int i = 0;
        for(it=contenu.begin() ; it!=contenu.end() ; it++)
        {
            string mot = it->first;
            if(i == row){
                ancienMot = it->first;
                anciennesDefinitions = it->second;
            }
            i++;
        }

        // Variables qui stockeront le nouveau mot et les nouvelles définitions
        vector<string> nouvellesDef(anciennesDefinitions);
        string nouvMot(ancienMot);

        if(column == 0){
            nouvMot = qPrintable(dialog->getUi()->definitions->item(row, column)->text());
        }else{
            if(column > nouvellesDef.size()){
                nouvellesDef.push_back(qPrintable(dialog->getUi()->definitions->item(row, column)->text()));
            }else{
                nouvellesDef.at(column-1) = qPrintable(dialog->getUi()->definitions->item(row, column)->text());
            }
        }

        int defSize = nouvellesDef.size();
        int nbCol = dialog->getUi()->definitions->columnCount();
        if(nouvellesDef.size()== dialog->getUi()->definitions->columnCount()-1)
            dialog->getUi()->definitions->setColumnCount(dialog->getUi()->definitions->columnCount() + 1);

        oldWords->push_back(ancienMot);
        newWords->push_back(nouvMot);
        oldDefinitions->push_back(anciennesDefinitions);
        newDefinitions->push_back(nouvellesDef);
    }
}

void DictionnaryManagerDialogController::slotDeleteWord(){

    map<string, vector<string>> contenu = dm->getContent(dictionnaire);
    map<string, vector<string> >::iterator it;

    string mot;
    vector<string> definitions;

    int index = dialog->getUi()->definitions->currentRow();
    int i = 0;

    for(it=contenu.begin() ; it!=contenu.end() ; it++)
    {
        if(i == index){
            mot = it->first;
            definitions = it->second;
            break;
        }
        i++;
    }

    string question = tr("Are you sure you want to delete the word ").toStdString() + mot + " ? ";

    QMessageBox messageBox;
    QMessageBox::StandardButton button = messageBox.question(0, tr("Confirm"), QString(question.c_str()), QMessageBox::Yes|QMessageBox:: No);
    messageBox.setFixedSize(500,200);

    if(button == QMessageBox::Yes){

        dm->deleteWord(dictionnaire, mot, definitions);
        dialog->getUi()->definitions->removeRow(index);

    }
}

void DictionnaryManagerDialogController::slotAddWord(){

  map<string, vector<string> > liste = dm->getContent(dictionnaire);
  map<string, vector<string> >::iterator it;

    string addedWord = awDialog->getUi()->lineEdit->text().toStdString();
    if(NormaliserSaisie::normalizeString(addedWord)){
        bool trouve = dm->isInDictionnary(dictionnaire, addedWord);
        if(!trouve){
            dm->addWord(dictionnaire, addedWord, vector<string>());
        }else{
            QMessageBox messageBox;
            messageBox.information(0, tr("Error"), tr("This word already exists"));
            messageBox.setFixedSize(500,200);
        }
    }else{
        QMessageBox messageBox;
        messageBox.information(0, tr("Error"), tr("There ar some unvalid characters"));
        messageBox.setFixedSize(500,200);
    }

    awDialog->getUi()->lineEdit->clear();


}

void DictionnaryManagerDialogController::slotActualize(){

    for(int i = 0; i < oldWords->size(); i++){
        bool ret = dm->modifyWord(dictionnaire, oldWords->at(i), oldDefinitions->at(i),newWords->at(i), newDefinitions->at(i));
    }

    slotSelectDictionnary(qPrintable(dictionnaire.c_str()));

    oldDefinitions->clear();
    oldWords->clear();
    newDefinitions->clear();
    newWords->clear();

}

void DictionnaryManagerDialogController::slotSaveChanges(){


    for(int i = 0; i < oldWords->size(); i++){
        bool ret = dm->modifyWord(dictionnaire, oldWords->at(i), oldDefinitions->at(i),newWords->at(i), newDefinitions->at(i));
    }

    oldDefinitions->clear();
    oldWords->clear();
    newDefinitions->clear();
    newWords->clear();

    dialog->hide();
}

void DictionnaryManagerDialogController::slotSearchWord(QString string){
    QTableWidget *table = dialog->getUi()->definitions;
    QList<QTableWidgetItem *> LTempTable = table->findItems(string, Qt::MatchStartsWith);
    for(int i = LTempTable.size() -1; i >= 0 ; i--){
        if(LTempTable.at(i)->column() == 0)
            table->setCurrentItem(LTempTable.at(i));
    }
}

void DictionnaryManagerDialogController::removeLine(int line){
    ifstream fichier(".dictionnaires.txt", ios::in);
    vector<string> liste;
    if(fichier){
        string ligne;
        int i = 0;
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
            if(i!=line) liste.push_back(ligne);
            i++;
        }
    }
    fichier.close();
    QFile::remove(".dictionnaires.txt");
    ofstream fichierOut(".dictionnaires.txt", ios::out);
    //fichierOut.clear();
    for(int j = 0; j < liste.size() ; j++){
        fichierOut << liste.at(j) << endl;
    }
    fichierOut.close();
}
