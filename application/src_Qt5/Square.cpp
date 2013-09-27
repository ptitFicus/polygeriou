#include "Square.h"


Square::Square(void)
{
    this->x=-1;
    this->y=-1;
    this->color=0;
    this->options=vector<string>();
}

Square::Square(const Square& sq)
{
    this->x = sq.x;
    this->y = sq.y;
    this->color = sq.color;
    this->options = sq.options;
}

Square& Square::operator=(const Square& sq)
{
    this->x=sq.x;
    this->y=sq.y;
    this->color=sq.color;
    this->options=sq.options;
    return *this;
}

vector<string> Square::getOptions()
{
    return this->options;
}

int Square::getColor()
{
    return this->color;
}

int Square::getX()
{
    return this->x;
}
int Square::getY()
{
    return this->y;
}
void Square::setPos(int x, int y) {
    this->x = x;
    this->y = y;
}

bool Square::getModifiable() const
{
    return this->modifiable;
}

string Square::toString(){
    return "SQUARE";
}

Square::~Square(void)
{
}
