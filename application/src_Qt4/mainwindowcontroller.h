#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include "newgamedialog.h"
#include "newgamedialogcontroller.h"
#include "dictionnarymanagerdialog.h"
#include "DictionnaryManager.h"
#include "dictionnarymanagerdialogcontroller.h"
#include "Grid.h"
#include <QPainterPath>
#include <QMenu>
#include <QProgressDialog>
#include <QMessageBox>
#include <QFileDialog>

class NewGameDialogController;
class MainWindowController : public QObject
{
    Q_OBJECT
public:
    MainWindowController(MainWindow *mainWindow);
    void deleteGraphicalGrid();
    DictionnaryManager* getDictionnaryManager();
    bool generateGrid(int heigth, int width, const vector<Dictionnary*>& dictionnaries);

public slots:

    /*
     *Slots for the menu buttons
     */
    void slotNewGame();
    void slotManageDictionnaries();
    void slotDeleteGrid();
    void slotCorrectGrid();
    void slotCheckGrid();
    void slotSaveGame();
    void slotExportGrid();
    void slotImportGrid();


    /*
     *Slots for the actions that are done on a square
     */
    void slotDeleteStd();
    void slotDeleteDef();
    void slotCheckStd();
    void slotCheckDef();
    void slotCorrectStd();
    void slotCorrectDef();

    void slotLeftClickDef(SquareScene*, QPoint);
    void slotLeftClickStd(SquareScene*, QPoint);

    void slotClickDefSquare(SquareScene*);
    void slotClickStdSquare(SquareScene* square);
    void slotEnterDefSquare(int index);
    void slotExitDefSquare(int index);
    void slotList(QListWidgetItem*);
    void slotDelKeyPress(SquareScene* scene);
    void slotLetterKeyPress(SquareScene* scene,QString);
    void slotContentChanged(int x, int y, char c);

    void slotQuitApplication();
    void slotIncrementProgressBar(int value);
    void exportToPDF();


private:
    MainWindow *view;
    NewGameDialog* newGD;
    NewGameDialogController* newGDC;
    DictionnaryManagerDialog* dictionnaryMD;
    DictionnaryManager* dm;
    DictionnaryManagerDialogController* dmController;
    Grid grid;
    int counter; //Counter for the definitions number
    QListWidgetItem* selectedItem; //Selected list item
    QPoint selected; //Selected definition square
    bool selectedLower; //True if lower definition selected
    vector<QPoint> selectedSquares; //vector of points for the selected squares
    int currentSquare; //selected square in the vector
    bool horizSelect; //true if the selected word is the horizontal one
    QMenu stdMenu; //menu when left clicked on a standard square
    QMenu defMenu; //menu when right clicked on a standard square

    SquareScene* rightClicked; //reference on the right clicked square

    QProgressDialog* progressBar;

    //Test method that generates a grid with pre-entered words
    void testGridGenerator();
    //Fill the graphical grid woth the Grid object
    void fillGrid();
    //Returns the arrow index to use for the given parameters (the def square and the two first standard square)
    int getArrow(DefinitionSquare* defs, StandardSquare* s1, StandardSquare* s2);
    //Add a definition in the list
    void addDefinition(int c, string def);
    //Add a Square to the graphical grid
    void addSquare(int def, int i, int j);
    //Add an arrow to the graphical grid
    void addArrow(int x, int y, int arrow);
    //Add a Definition square to the graphical grid
    void addDefinitionSquare(QGraphicsView* view, SquareScene* scene);
    //Returns the SquareScene at (x,y)
    SquareScene* getScene(int x, int y);
    //Returns the GraphicsView at (x,y)
    QGraphicsView* getView(int x, int y);
    //returns the squarescene corresponding to the index
    SquareScene* get1stSquareScene(int index);
    //select the square
    void select(int, int,Square*, bool lower, int xS = -1, int yS = -1);
    //Unselect everything
    void unselect();
    //Switch to the nextsquare
    void nextSquare(int dir = 1);
};

#endif // MAINWINDOWCONTROLLER_H
