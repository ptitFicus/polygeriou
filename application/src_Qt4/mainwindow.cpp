#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <stdlib.h>

#include <stdio.h>
#include <iostream>



using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
setWindowState(Qt::WindowMaximized);
    this->setWindowTitle(QString("Polygeriou"));

    initArrows();

    ui->setupUi(this);
    ui->gameLayout->setSizeConstraint(QLayout::SetFixedSize);
    ui->scrollArea->setAlignment(Qt::AlignCenter);


}

void MainWindow::initArrows() {

    arrows[horiz].lineTo(QPoint(0,0));
    arrows[horiz].lineTo(QPoint(8,8));
    arrows[horiz].lineTo(QPoint(0,16));



    arrows[vert].lineTo(QPoint(20,0));
    arrows[vert].lineTo(QPoint(10,10));
    arrows[vert].lineTo(QPoint(0,0));

    arrows[decVerti].lineTo(QPoint(0,5));
    arrows[decVerti].lineTo(QPoint(40,5));
    arrows[decVerti].lineTo(QPoint(30,15));
    arrows[decVerti].lineTo(QPoint(20,5));


    arrows[decHoriz].lineTo(QPoint(5,0));
    arrows[decHoriz].lineTo(QPoint(5,40));
    arrows[decHoriz].lineTo(QPoint(15,30));
    arrows[decHoriz].lineTo(QPoint(5,20));
}

MainWindow::~MainWindow()
{

    delete ui;
    for(unsigned i=0; i< squareScene.size(); i++)
        //delete squareScene[i];
    for(int i =0; i< gridW*gridH; i++)
       delete squareView[i];

    delete[] squareContainer;

}

void MainWindow::initSize(int w, int h) {
    gridW = w;
    gridH = h;
    squareContainer = new QGridLayout[w*h];

}

Ui::MainWindow* MainWindow::getUi() {
    return ui;
}

QGridLayout* MainWindow::getSquareContainer() {
    return squareContainer;
}

vector<QGraphicsView*>* MainWindow::getSquareView() {
    return &squareView;
}

vector<SquareScene*>* MainWindow::getSquareScene() {
    return &squareScene;
}

QPainterPath* MainWindow::getArrows() {
    return arrows;
}


int MainWindow::getGridW() {
    return gridW;
}
