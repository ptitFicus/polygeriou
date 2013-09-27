#ifndef SQUARE_H
#define SQUARE_H

#include<vector>
#include<string>

using namespace std;

class Square
{
private:
    int color;


protected:
    bool modifiable;
    int wordCount;
    vector<string> options;
    int x;
    int y;
public:
    Square(void);
    Square(const Square& sq);
    Square& operator=(const Square& sq);
    virtual vector<string> getOptions();
    int getColor();
    int getX();
    int getY();
    void setPos(int x, int y);
    bool getModifiable() const;
    virtual int getWordCount()=0;
    virtual string toString();

    virtual ~Square(void);
};

#endif
