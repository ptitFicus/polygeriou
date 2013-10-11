#include "squarescene.h"
#include <iostream>
#include<QKeyEvent>

SquareScene::SquareScene(int index, int x, int y, bool lower) : QGraphicsScene() {
    this->index = index;
    this->x = x;
    this->y = y;
    this->lower = lower;
    isLetter = false;
    locked = false;

}

bool SquareScene::event ( QEvent * e ) {
    if(e->type() == QEvent::Enter)
        emit enter(this->index);
    else if(e->type() == QEvent::Leave)
        emit exit(this->index);
    else if(e->type() == QEvent::KeyPress) {
        QKeyEvent* keyevent = dynamic_cast<QKeyEvent*>(e);
        if(keyevent->key() >= Qt::Key_A && keyevent->key() <= Qt::Key_Z )
            emit letterkeypress(this, keyevent->text());
        else if(keyevent->key() == Qt::Key_Backspace)
            emit delkeypress(this);
    }

    QGraphicsScene::event(e);
 return true;
}

void SquareScene::mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent ) {
    if(mouseEvent->button() == Qt::LeftButton) {
        emit clicked(this);
    }
    else if(mouseEvent->button() == Qt::RightButton) {
        emit leftClicked(this, mouseEvent->screenPos());
        emit clicked(this);
    }

}

int SquareScene::getX() {
    return x;
}

int SquareScene::getY() {
    return y;
}

bool SquareScene::getLower() {
    return lower;
}

int SquareScene::getIndex() {
    return index;
}

bool SquareScene:: getIsLetter() {
    return isLetter;
}

void  SquareScene::setIsLetter(bool val) {
    isLetter = val;
}

bool SquareScene:: getLocked() {
    return locked;
}

void  SquareScene::setLocked(bool val) {
    locked = val;
}
