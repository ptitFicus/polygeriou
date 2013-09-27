#ifndef STANDARDSQUARE_H
#define STANDARDSQUARE_H

#include "Square.h"

class StandardSquare : public Square
{
private:

public:
    char content;
    char expected;
    StandardSquare(void);
    StandardSquare(const StandardSquare &s);
    StandardSquare(char expected, char content = ' ');
    void correct();
    bool check();
    void clear();
    void changeContent(char c);
    vector<string> getOptions();
    string toString();
    int getWordCount();
    StandardSquare& operator=(const StandardSquare &s);
    ~StandardSquare(void);
};

#endif
