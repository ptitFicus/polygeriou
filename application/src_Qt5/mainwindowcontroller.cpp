#include "mainwindowcontroller.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtPrintSupport>
#include <QGridLayout>

#include <iostream>
using namespace std;

MainWindowController::MainWindowController(MainWindow *mainWindow){

    this->view = mainWindow;

    //Creates the Dctionnary manager
    dm = new DictionnaryManager();

    newGD = new NewGameDialog();
    newGDC = new NewGameDialogController(newGD, this);

    dmController = new DictionnaryManagerDialogController(dm, view);

    //Initialization of the attrbutes
    selectedItem = nullptr;//Selected item in the list
    counter = 1; //counter for incrementing the definition number
    //selected Point
    selected.setX(-1);
    selected.setY(-1);
    selectedLower = false; //Upper or lower
    currentSquare = 0; //index of the selected square
    horizSelect = true;
    rightClicked = nullptr; //SquareScene of the left clicked square


    progressBar = new QProgressDialog(tr("Remaining time"), tr("Cancel"), 0, 60, 0, Qt:: Dialog | Qt:: FramelessWindowHint | Qt:: WindowTitleHint | Qt:: CustomizeWindowHint);
    progressBar->setCancelButton(NULL);
    progressBar->setVisible(false);

    //Create and connect the left click menu
    connect(stdMenu.addAction(tr("Correct")), SIGNAL(triggered()), this,SLOT(slotCorrectStd()));
    connect(stdMenu.addAction(tr("Delete")), SIGNAL(triggered()), this, SLOT(slotDeleteStd()));
    connect(stdMenu.addAction(tr("Check")), SIGNAL(triggered()), this, SLOT(slotCheckStd()));
    connect(defMenu.addAction(tr("Correct")), SIGNAL(triggered()), this,SLOT(slotCorrectDef()));
    connect(defMenu.addAction(tr("Delete")), SIGNAL(triggered()), this, SLOT(slotDeleteDef()));
    connect(defMenu.addAction(tr("Check")), SIGNAL(triggered()), this, SLOT(slotCheckDef()));

    //Connect the action from the menu bar
    connect(view->getUi()->actionNouvelle_partie, SIGNAL(triggered()), this, SLOT(slotNewGame()));
    connect(view->getUi()->actionEnregistrer_partie, SIGNAL(triggered()), this, SLOT(slotSaveGame()));
    connect(view->getUi()->actionExporter_grille, SIGNAL(triggered()), this, SLOT(slotExportGrid()));
    connect(view->getUi()->actionCharger_une_partie, SIGNAL(triggered()), this, SLOT(slotImportGrid()));
    connect(view->getUi()->actionGestion_des_dictionnaire, SIGNAL(triggered()), this, SLOT(slotManageDictionnaries()));
    connect(view->getUi()->definitionWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(slotList(QListWidgetItem*)));
    connect(view->getUi()->actionVider_la_grille, SIGNAL(triggered()), this, SLOT(slotDeleteGrid()));
    connect(view->getUi()->actionV_rifier_la_grille, SIGNAL(triggered()), this, SLOT(slotCheckGrid()));
    connect(view->getUi()->actionCorriger_la_grille, SIGNAL(triggered()), this, SLOT(slotCorrectGrid()));
    connect(view->getUi()->actionQuitter, SIGNAL(triggered()), this, SLOT(slotQuitApplication()));
    connect(view->getUi()->exportPDF, SIGNAL(triggered()), this, SLOT(exportToPDF()));


    //Connect the model to the view
    connect(&grid, SIGNAL(contentChanged(int,int,char)), this, SLOT(slotContentChanged(int,int,char)));
    connect(&grid, SIGNAL(iterationFailed(int)), this, SLOT(slotIncrementProgressBar(int)));

}

void MainWindowController::slotNewGame(){
    newGD->show();
}

void MainWindowController::slotManageDictionnaries(){
     dmController->show();
}


void MainWindowController::slotSaveGame(){
    QString fileName = QFileDialog::getSaveFileName(nullptr, tr("Choose location"), "", tr("Grid File(*.grid)"));
    string filePath = qPrintable(fileName);

    grid.Xport(filePath, false); //false = with content
}

void MainWindowController::slotExportGrid(){
    QString fileName = QFileDialog::getSaveFileName(nullptr, tr("Choose location"), "", tr("Grid File(*.grid)"));
    string filePath = qPrintable(fileName);

    grid.Xport(filePath, true); //true = empty grid
}

void MainWindowController::slotImportGrid(){
    QString fileName = QFileDialog::getOpenFileName(nullptr, tr("Chooose grid file"), "", tr("Grid File(*.grid)"));
    string filePath = qPrintable(fileName);
    grid.import(filePath);


    this->deleteGraphicalGrid();
    this->fillGrid();
    this->grid.updateContent();
}

void MainWindowController::slotDeleteGrid() {
    grid.deleteContent();
}

void MainWindowController::slotCorrectGrid() {
    for(int i = 0; i< view->getSquareScene()->size(); i++) {
        SquareScene*  s= (*(view->getSquareScene()))[i];
        if(s->getIndex() == -1) {
            rightClicked = s;
            slotCorrectStd();
        }
    }

}

void MainWindowController::slotCheckGrid() {
    for(int i = 0; i< view->getSquareScene()->size(); i++) {
        SquareScene*  s= (*(view->getSquareScene()))[i];
        if(s->getIndex() == -1) {
            rightClicked = s;
            slotCheckStd();
        }
    }

}


void MainWindowController::slotDeleteStd(){
      grid.setContent(rightClicked->getX(), rightClicked->getY(), ' ');
}

void MainWindowController::slotDeleteDef(){

    if(selected == QPoint(-1,-1))
        slotClickDefSquare(rightClicked);

    for (vector<QPoint>::iterator it = selectedSquares.begin(); it!=selectedSquares.end(); ++it) {
        rightClicked = getScene((*it).x(), (*it).y());
        slotDeleteStd();
    }

    getView(selected.x(), selected.y())->setFocus();
    unselect();



}

void MainWindowController::slotCheckStd(){
    StandardSquare* s = dynamic_cast<StandardSquare*>(
                grid.getSquare(rightClicked->getX(), rightClicked->getY()));
    if(s->check()) {
        cout << "OK" << endl;
        slotCorrectStd();

    }
    else {
        cout << "NOT OK" << endl;
        getView(s->getX(), s->getY())->setBackgroundBrush(QBrush(QColor(236, 19, 16 )));
    }

}

void MainWindowController::slotCheckDef(){


    if(selected == QPoint(-1,-1))
        slotClickDefSquare(rightClicked);

    QPoint sel = selected;
    vector<QPoint> selSq = selectedSquares;
    getView(sel.x(), sel.y())->setFocus();
    unselect();
    for (vector<QPoint>::iterator it = selSq.begin(); it!=selSq.end(); ++it) {
        rightClicked = getScene((*it).x(), (*it).y());
        slotCheckStd();
    }



}

void MainWindowController::slotCorrectStd(){

    grid.correct(rightClicked->getX(), rightClicked->getY());
    rightClicked->setLocked(true);
    getView(rightClicked->getX(), rightClicked->getY())->setBackgroundBrush(QBrush(QColor(217, 208, 46 )));

    getView(selected.x(), selected.y())->setFocus();
    unselect();

}

void MainWindowController::slotCorrectDef() {

    if(selected == QPoint(-1,-1))
        slotClickDefSquare(rightClicked);

    QPoint sel = selected;
    vector<QPoint> selSq = selectedSquares;
    for (vector<QPoint>::iterator it = selSq.begin(); it!=selSq.end(); ++it) {
        rightClicked = getScene((*it).x(), (*it).y());
        slotCorrectStd();
    }

    getView(sel.x(), sel.y())->setFocus();
    unselect();
}


void MainWindowController::slotDelKeyPress(SquareScene* scene) {

    nextSquare(-1);
    QPoint selPoint = selectedSquares[currentSquare];
    scene = getScene(selPoint.x(), selPoint.y());
    rightClicked = scene;
    slotDeleteStd();

}

void MainWindowController::slotLetterKeyPress(SquareScene* scene,QString text) {
    grid.setContent(scene->getX(), scene->getY(),text[0].unicode());
    nextSquare();
}

void MainWindowController::slotClickDefSquare(SquareScene* square) {
    Square* selectedSq = grid.getSquare(square->getX(),square->getY());
    switch(selectedSq->getWordCount()) {
    case 0:
        if(selected != QPoint(-1,-1))
            nextSquare();
        break;
    case 1:
    case 2:
        if(selected == QPoint(-1,-1)) {
            select(square->getX(),square->getY(), selectedSq, square->getLower());
        }
        else {
            int x1 = selected.x();
            int x2 = selected.y();
            bool lower2 = selectedLower;
            unselect();
            if( x1 != square->getX() || x2 != square->getY() || square->getLower() != lower2)
                select(square->getX(),square->getY(), selectedSq, square->getLower());
        }
        break;
    }
}

void MainWindowController::slotClickStdSquare(SquareScene* square) {
    bool lower = false;
    DefinitionSquare* defSq = nullptr;
    int c = 0;
    while(defSq == nullptr) {
        if(horizSelect) {
            defSq = grid.getHorizDef(dynamic_cast<StandardSquare*>(grid.getSquare(square->getX(),square->getY())), &lower);

            horizSelect=false;
        }else {
            defSq = grid.getVertiDef(dynamic_cast<StandardSquare*>(grid.getSquare(square->getX(),square->getY())), &lower);
            horizSelect=true;
        }
        c++;
        if(c>2) {
            exit(-1);
        }
    }
    if(selected == QPoint(-1,-1)) {
        select(defSq->getX(),defSq->getY(),defSq,lower, square->getX(), square->getY());
    }
    else {
        unselect();
        select(defSq->getX(),defSq->getY(),defSq, lower, square->getX(), square->getY());
    }
}

void MainWindowController::slotLeftClickDef(SquareScene* scene, QPoint p) {
    rightClicked = scene;
    defMenu.popup(p);

}

void MainWindowController::slotLeftClickStd(SquareScene* scene, QPoint p) {
    rightClicked = scene;
    stdMenu.popup(p);
}

void MainWindowController::select(int x, int y, Square* defSq, bool lower, int xS, int yS) {
    currentSquare = 0;
    selected.setX(x);
    selected.setY(y);
    selectedLower = lower;
    vector<StandardSquare*> selectedStandardSquares;
    if(lower)
        selectedStandardSquares = (dynamic_cast<DefinitionSquare *>(defSq)) -> lowerWordSquares;
    else
        selectedStandardSquares = (dynamic_cast<DefinitionSquare *>(defSq)) -> upperWordSquares;

    for (vector<StandardSquare*>::iterator it = selectedStandardSquares.begin(); it!=selectedStandardSquares.end(); ++it) {
        if((*it)->getModifiable()) {
            x = (*it)->getX();
            y = (*it)->getY();

            getView(x,y)->setBackgroundBrush(QBrush(QColor(228, 211, 170)));
            selectedSquares.push_back(QPoint(x,y));
        }

    }
    if(selectedSquares.size() != 0) {
        if(xS != -1 && yS != -1) {
            for(int i = 0; i < selectedSquares.size(); i++) {
                if(selectedSquares[i].x() == xS && selectedSquares[i].y() == yS)
                    currentSquare = i;
            }
        }

        QPoint selPoint = selectedSquares[currentSquare];
        QGraphicsView* v =  getView(selPoint.x(), selPoint.y());
        v->setBackgroundBrush(QBrush(QColor(150, 250, 150 )));
        v->setFocus();
    }
    else {
        QGraphicsView* v = getView(selected.x(), selected.y());
        v->setFocus();
        selected.setX(-1);
        selected.setY(-1);
    }


}

void MainWindowController::unselect() {
    currentSquare = 0;
    for (vector<QPoint>::iterator it = selectedSquares.begin(); it!=selectedSquares.end(); ++it) {
        if(grid.getSquare((*it).x(), (*it).y())->getModifiable())
            getView((*it).x(),(*it).y())->setBackgroundBrush(QBrush(QColor(255, 255, 255 )));
    }
    selected.setX(-1);
    selected.setY(-1);
    selectedSquares.clear();
    selectedLower = false;

}

void MainWindowController::nextSquare(int dir) {
    QPoint selPoint = selectedSquares[currentSquare];
    getView(selPoint.x(), selPoint.y())->setBackgroundBrush(QBrush(QColor(228, 211, 170 )));
    if( (currentSquare == selectedSquares.size()-1 && dir == 1))
        currentSquare = 0;
    else if  ( (currentSquare == 0 && dir == -1))
        currentSquare = selectedSquares.size()-1;
    else
        currentSquare+= dir;
    selPoint = selectedSquares[currentSquare];
    QGraphicsView* v =  getView(selPoint.x(), selPoint.y());
    v->setBackgroundBrush(QBrush(QColor(150, 250, 150 )));
    v->setFocus();

}

void MainWindowController::slotEnterDefSquare(int index) {
    QListWidgetItem* lWidget = view->getUi()->definitionWidget->item(index-1);
    lWidget->setBackgroundColor(QColor(Qt::red));
    selectedItem = lWidget;
}

void MainWindowController::slotExitDefSquare(int index) {
    selectedItem = nullptr;
    QListWidgetItem* lWidget = view->getUi()->definitionWidget->item(index-1);
    lWidget->setBackgroundColor(QColor(Qt::white));
}

void MainWindowController::slotList(QListWidgetItem* item) {
    int index = item->listWidget()->row(item);
    SquareScene* sqS = get1stSquareScene(index);
    int x = sqS->getX();
    int y = sqS->getY();
    bool lower = sqS->getLower();
    Square* selectedSq = grid.getSquare(x,y);

    if(selected == QPoint(-1,-1)) {

        select(x,y, selectedSq, lower);
    }
    else {
        int x1 = selected.x();
        int x2 = selected.y();
        bool lower2 = selectedLower;
        unselect();
        if( x1 != x || x2 != y || lower != lower2)
            select(x,y, selectedSq, lower);



    }
}

void MainWindowController::slotContentChanged(int x, int y, char c) {

    rightClicked = getScene(x,y);
    if(rightClicked->getIsLetter())
        rightClicked->removeItem(rightClicked->items().at(0));
    if(c != ' ') {
        rightClicked->addText(QString(c).toUpper(), QFont("Helvetica",25,QFont::Bold));
        rightClicked->setIsLetter(true);
    }
    else
        rightClicked->setIsLetter(false);
}

void MainWindowController::deleteGraphicalGrid() {
    vector<SquareScene*>* sqScene = view->getSquareScene();

    if(sqScene->size() > 0)
    {

        for(int i = 0; i < sqScene->size(); i++) {
            delete (*sqScene)[i];
        }
        sqScene->clear();

        vector<QGraphicsView*>* sqView = view->getSquareView();

        for(int i = 0; i < sqView->size(); i++) {
            delete (*sqView)[i];
        }
        sqView->clear();
        delete[] view->getSquareContainer();
    }

    view->getUi()->definitionWidget->clear();

    //Initialization of the attrbutes
    selectedItem = nullptr;//Selected item in the list
    counter = 1; //counter for incrementing the definition number
    //selected Point
    selected.setX(-1);
    selected.setY(-1);
    selectedLower = false; //Upper or lower
    selectedSquares.clear();
    currentSquare = 0; //index of the selected square
    horizSelect = true;
    rightClicked = nullptr; //SquareScene of the left clicked square




}

void MainWindowController::testGridGenerator() {
    grid.setSize(13, 10);
    grid.addTwoWords("grenouille", "tria", "Batracien anoure", "classa", Grid::decVerti,Grid::decHoriz,0,0);
    grid.addTwoWords("nasa", "ines", "Agence aux USA", "Prenom espagnol", Grid::decVerti,Grid::vert,2,0);
    grid.addWord("partira", "Quittera", Grid::decVerti, 4,0);
    grid.addTwoWords("age", "lci", "Duree de vie", "Chaine sur le cable", Grid::decVerti,Grid::vert,6,0);
    grid.addTwoWords("crash", "electrice", "Chute soudaine", "Bonne citoyenne", Grid::decVerti,Grid::vert,8,0);
    grid.addTwoWords("veto", "intermede","Acte d'opposition", "Courte piece", Grid::decVerti,Grid::vert,10,0);
    grid.addWord("nectar", "Boisson des dieux", Grid::vert, 12,0);

    grid.addTwoWords("algerien", "ongule", "Homme d'Oran", "Dote de sabots", Grid::horiz,Grid::vert,4,1);

    grid.addTwoWords("ensorcelante", "aneanti", "Fascinante", "DÃ©truit", Grid::horiz,Grid::decHoriz,0,2);

    grid.addTwoWords("estoc", "enfuir", "Grande epee", "Calter (s')", Grid::horiz,Grid::vert,7,3);
    grid.addTwoWords("os", "bu", "A moelle dans le pot-au-feu", "pompe", Grid::horiz,Grid::decHoriz,0,4);

    grid.addTwoWords("gi", "cosse", "Soldat americain", "Anneau de batterie", Grid::horiz,Grid::vert,3,4);
    grid.addWord("eche", "appat", Grid::horiz, 6,4);
    grid.addWord("serin", "Canari", Grid::vert, 11,4);

    grid.addTwoWords("curent", "mail", "Nettoient a fond", "Allee arboree", Grid::horiz,Grid::vert,2,5);

    grid.addTwoWords("rsa", "in", "Complement de salaire", "prefixe", Grid::horiz,Grid::vert,9,5);

    grid.addTwoWords("imola", "blase", "Cirtcuit en Italie", "Devenu insensible", Grid::horiz,Grid::decHoriz,0,6);

    grid.addTwoWords("frimer", "rh", "Craner", "Facteur sanguin", Grid::horiz,Grid::vert,6,6);

    grid.addTwoWords("ruiner", "cs", "Causer la perte", "Cesium abrege", Grid::horiz,Grid::vert,5,7);

    grid.addWord("su", "Bien assimile", Grid::vert, 12,7);

    grid.addTwoWords("lis", "felees", "Embleme de la royaute", "fendues", Grid::horiz,Grid::decHoriz,0,8);

    grid.addWord("chic", "Bon et brave", Grid::horiz, 4,8);

    grid.addWord("dis", "Affirme", Grid::horiz, 9,8);

    grid.addWord("revenu", "Rentre ou rentree", Grid::horiz, 6,9);

    cout << grid << endl;
}

void MainWindowController::fillGrid() {
    int c = 1;
    view->initSize(grid.getWidth(), grid.getHeight());

    for(int y = 0; y < grid.getHeight(); y++) {
        for(int x = 0; x < grid.getWidth(); x++) {
            Square* s = grid.getSquare(x,y);
            if(s == nullptr) {
                //error
            } else {
                switch(s->getWordCount()) {
                case 0:
                    addSquare(0,x,y);
                    break;
                case 1:
                    addSquare(1,x,y);
                    addDefinition(c, (dynamic_cast<DefinitionSquare *>(s)) -> getUpperWordDefinition() );
                    c++;
                    break;
                case 2:
                    addSquare(2,x,y);
                    addDefinition(c,(dynamic_cast<DefinitionSquare *>(s))->getUpperWordDefinition());
                    c++;
                    addDefinition(c,(dynamic_cast<DefinitionSquare *>(s))->getLowerWordDefinition());
                    c++;
                    break;

                }
            }

        }

    }
    //add the arrows

    for(int y = 0; y < grid.getHeight(); y++) {
        for(int x = 0; x < grid.getWidth(); x++) {
            Square* s = grid.getSquare(x,y);
            StandardSquare* stand = nullptr;
            if(s!= nullptr && s->getWordCount() >= 1) {

                DefinitionSquare* defs = dynamic_cast<DefinitionSquare*>(s);
                stand = defs->upperWordSquares[0];

                addArrow(stand->getX(), stand->getY(),getArrow(defs, defs->upperWordSquares[0], defs->upperWordSquares[1]));

                if(s->getWordCount() == 2) {
                    stand = (dynamic_cast<DefinitionSquare*>(s))->lowerWordSquares[0];
                    addArrow(stand->getX(), stand->getY(), getArrow(defs, defs->lowerWordSquares[0], defs->lowerWordSquares[1]));
                }
            }
        }
    }

    //view->addArrow(1, 1,2);
}

int MainWindowController::getArrow(DefinitionSquare* defs, StandardSquare* s1, StandardSquare* s2) {
    if(defs->getX() == s1->getX() && defs->getX() == s2->getX()) {
        return Grid::vert;
    }
    else if (s1->getX() == s2->getX())
        return Grid::decVerti;
    else if(defs->getY() == s1->getY() && defs->getY() == s2->getY()) {
        return Grid::horiz;
    }
    else
        return Grid::decHoriz;
}



void MainWindowController::addDefinitionSquare(QGraphicsView* gview, SquareScene* scene) {
    char buffer[3];
    sprintf(buffer, "%d", this->counter);
    scene->addText(buffer);
    this->counter++;
    gview->setBackgroundBrush(QBrush(QColor(255, 255, 204)));
    connect(scene, SIGNAL(enter(int)), this, SLOT(slotEnterDefSquare(int)) );
    connect(scene, SIGNAL(exit(int)), this, SLOT(slotExitDefSquare(int)) );
    connect(scene, SIGNAL(clicked(SquareScene*)), this, SLOT(slotClickDefSquare(SquareScene*)) );
    connect(scene, SIGNAL(leftClicked(SquareScene*,QPoint)), this, SLOT(slotLeftClickDef(SquareScene*,QPoint)));
}

/**
  Add a square to the grid
 * @brief MainWindow::addSquare
 * @param definition
 * @param i
 * @param j
 * @param arrowIndex
 */
void MainWindowController::addSquare(int definition, int x, int y) {
    int index = (y*view->getGridW())+x;
    view->getSquareContainer()[index].setSizeConstraint(QLayout::SetFixedSize);
    int defNum = -1;
    if(definition != 0)
        defNum = this->counter;
    SquareScene* scene = new SquareScene(defNum, x, y);
    QGraphicsView* gview = new QGraphicsView(scene);


    gview->setFixedSize(50,50);
    gview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gview->setFocusPolicy(Qt::ClickFocus);
    gview->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    if(definition >= 1) {
        addDefinitionSquare(gview, scene);
    }
    else {
        //Make connections for standardSquare
        connect(scene, SIGNAL(clicked(SquareScene*)), this, SLOT(slotClickStdSquare(SquareScene*)));
        connect(scene, SIGNAL(letterkeypress(SquareScene*,QString)), this, SLOT(slotLetterKeyPress(SquareScene*,QString)) );
        connect(scene, SIGNAL(delkeypress(SquareScene*)), this, SLOT(slotDelKeyPress(SquareScene*)) );
        connect(scene, SIGNAL(leftClicked(SquareScene*,QPoint)), this, SLOT(slotLeftClickStd(SquareScene*,QPoint)));

    }
    view->getSquareContainer()[index].addWidget(gview);
    if(definition == 2) {
        SquareScene* scene2 = new SquareScene(this->counter,x ,y, true);
        QGraphicsView* gview2 = new QGraphicsView(scene2);
        gview->setFixedSize(50,25);
        gview2->setFixedSize(50,25);
        gview2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gview2->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        gview2->setFocusPolicy(Qt::ClickFocus);
        addDefinitionSquare(gview2, scene2);
        view->getSquareContainer()[index].addWidget(gview2);
        ( *(view->getSquareView()) ).push_back(gview2);
        ( *(view->getSquareScene()) ).push_back(scene2);
    }
    view->getSquareView()->push_back(gview);
    view->getSquareScene()->push_back(scene);

    view->getUi()->gameLayout->addLayout(&(view->getSquareContainer())[index], y, x);

}

void MainWindowController::addArrow(int x, int y, int arrow) {
    int index = (y*view->getGridW())+x;
    int count = 0;
    //Count to the subsquare number
    for( int i = 0; i< index; i++) {
        count+= view->getSquareContainer()[i].count();
    }

    QGraphicsView* v = (* (view->getSquareView()) )[count];
    SquareScene* s = (* (view->getSquareScene()) )[count];

    s->addPath(view->getArrows()[arrow]);
    switch(arrow) {
    case Grid::horiz:

        v->setAlignment(Qt::AlignLeft);
        break;
    case Grid::vert:
        v->setAlignment(Qt::AlignTop);
        break;
    }
    v->repaint();

}

void MainWindowController::addDefinition(int nb, string def) {
    char buffer[3];
    sprintf(buffer, "%d", nb);
    view->getUi()->definitionWidget->addItem(QString::fromUtf8((buffer + string(". ") + def).c_str()));

}

SquareScene* MainWindowController::getScene(int x, int y) {
    int count = 0;
    int index = (y*view->getGridW())+x;
    for( int i = 0; i< index; i++) {
        count+= view->getSquareContainer()[i].count();
    }
    return (* (view->getSquareScene()) )[count];
}

QGraphicsView* MainWindowController::getView(int x, int y) {
    int count = 0;
    int index = (y*view->getGridW())+x;
    for( int i = 0; i< index; i++) {
        count+= view->getSquareContainer()[i].count();
    }
    return (* (view->getSquareView()) )[count];

}

SquareScene* MainWindowController::get1stSquareScene(int index) {
    for (vector<SquareScene*>::iterator it = view->getSquareScene()->begin(); it!=view->getSquareScene()->end(); ++it) {
        if((*it)->getIndex() -1== index)
            return (*it);


    }
    return nullptr;
}

DictionnaryManager* MainWindowController::getDictionnaryManager()
{
    return dm;
}

bool MainWindowController::generateGrid(int newHeigth, int newWidth, const vector<Dictionnary*>& dictionnaries)
{
    progressBar->setVisible(true);
    qApp->processEvents();
    bool ret = this->grid.fill(dictionnaries, newHeigth, newWidth);
    progressBar->setVisible(false);
    progressBar->reset();

    if(ret)
    {
        this->deleteGraphicalGrid();
        this->fillGrid();
    }
    else
    {
        QMessageBox::warning(this->view, tr("Generation failure"),
                            tr("<html>The grid generation has failed, you can: <ul><li>Try again</li><li>Try with a smaller grid</li><li>Change the dictionnary selection</li></ul>"));
    }
    return ret;
}

void MainWindowController::slotQuitApplication()
{

   if(QMessageBox::question(this->view, tr("Confirm close"), tr("Exit application ?")) == QMessageBox::Yes)
   {
        QApplication::quit();
   }
}

void MainWindowController::slotIncrementProgressBar(int value)
{
    this->progressBar->setValue(60-value);
    QApplication::processEvents();
}

void MainWindowController:: exportToPDF()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, tr("Choose PDF location"), "", tr("PDF File(*.pdf)"));
    QPrinter prn;
    prn.setOutputFileName(QString(fileName));
    //QPrintDialog(&prn, mainWindow).exec();
    prn.setOrientation(QPrinter::Landscape);
    QPainter painter;
    painter.begin(&prn);
    double x = this->view->getUi()->gameLayout_2->width();
    painter.translate(prn.paperRect().x() + 20,
                                prn.paperRect().y()+20);
    this->view->getUi()->gameLayout_2->render(&painter);
    painter.translate(prn.paperRect().x() + x,
                                prn.paperRect().y());
    QFont font;
    font.setPixelSize(12);
    painter.setFont(font);
    for (int i = 0 ; i < this->view->getUi()->definitionWidget->count() ; i++)
    {
        painter.drawText(QPoint(10,10),this->view->getUi()->definitionWidget->item(i)->text() );

        if(i %40 == 0&&i>1)
        {
            painter.translate(QPoint(prn.paperRect().x()+200,
                                        -600));
        }
        else
        {
            painter.translate(QPoint(prn.paperRect().x(),
                                        prn.paperRect().y()+15));
        }
    }
}
