#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <string>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QSpacerItem>
#include <QGridLayout>

#include "squarescene.h"

namespace Ui {
class MainWindow;
}

using namespace std;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /**
      * @brief returns the ui windows
      */
    Ui::MainWindow* getUi();
    /**
      * @brief returns the squareCOntiner array
      */
    QGridLayout* getSquareContainer();

    /**
      *
      */
    vector<QGraphicsView*>* getSquareView();
    vector<SquareScene*>* getSquareScene();
    QPainterPath* getArrows();

    void initSize(int,int);

    int getGridW();


    
private:
    /**
      * @brief ENumeration for the word alignment
      */
    enum align { horiz, vert, decHoriz, decVerti};
    /**
      * @brief Ui object
      */
    Ui::MainWindow *ui;
    /**
      * Array of square
      */
    QGridLayout* squareContainer;
    /**
      * Vector of graphic view
      */
    vector<QGraphicsView*> squareView;
    /**
      * Vector of graphc scene
      */
    vector<SquareScene*> squareScene;
    /**
      * Grid width
      */
    int gridW;
    /**
      * Grid height
      */
    int gridH;
    /**
      * Array of arrows
      */
    QPainterPath arrows[4];

    //Private methods
    void initArrows(void);
    void addDefinitionSquare(QGraphicsView* view, QGraphicsScene* scene);
};

#endif // MAINWINDOW_H
