#ifndef SQUARESCENE_H
#define SQUARESCENE_H

#include <QGraphicsView>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>

class SquareScene : public QGraphicsScene
{
    Q_OBJECT
public:
    /**
     * @brief Construcote of a SquareScene
     * @param index index of the definition if it's a Definition Square, -1 if it's a Standard Square
     * @param x x position of the Square
     * @param y y position of the Square
     * @param lower true if it's the lower defintion, false otherwise
     */
    SquareScene(int index, int x, int y, bool lower = false);

    bool event ( QEvent * e );
    void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    int getX();
    int getY();
    bool getLower();
    int getIndex();
    bool getIsLetter();
    void setIsLetter(bool val);
    bool getLocked();
    void setLocked(bool val);
signals:
    /**
     * @brief emitted when the mouse enters the square
     */
    void enter(int);
    /**
     * @brief emitted when the mouse exits the square
     */
    void exit(int);
    /**
     * @brief emitted when the square is clicked
     * @param sq this object
     */
    void clicked(SquareScene* sq);
    /**
     * @brief emitted when the square is left clicked
     * @param sq this object
     * @param p Coordinates of the click (to dislay the menu)
     */
    void leftClicked(SquareScene* sq, QPoint p);
    /**
     * @brief emitted when a letter key is pressed
     * @param sq this object
     * @param s a string containing the pressed character
     */
    void letterkeypress(SquareScene* sq, QString s);
    /**
     * @brief emitted when the backspace ket is pressed
     * @param sq this object
     */
    void delkeypress(SquareScene* sq);

    
public slots:

private:

    int index;
    int x;
    int y;
    bool lower;
    bool isLetter;
    bool locked;
    
};

#endif // SQUAREVIEW_H
