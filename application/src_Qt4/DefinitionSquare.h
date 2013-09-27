#ifndef DEFINITIONSQUARE_H
#define DEFINITIONSQUARE_H

#include "Square.h"
#include "StandardSquare.h"
#include "Word.h"

class DefinitionSquare : public Square
{
private:
    Word upperWord;
    Word lowerWord;
    string upperWordDefinition;
    string lowerWordDefinition;

public:vector<StandardSquare*> upperWordSquares;
    vector<StandardSquare*> lowerWordSquares;
    DefinitionSquare(void);
    DefinitionSquare(Word upperWord, Word lowerWord);
    DefinitionSquare(Word word);
    DefinitionSquare(const DefinitionSquare& sq);
    DefinitionSquare& operator=(const DefinitionSquare& sq);

    string getUpperWordDefinition();
    string getLowerWordDefinition();
    int getWordCount();

    void correctUpperWord();
    void correctLowerWord();

    bool checkUpperWord();
    bool checkLowerWord();


    string toString();

    ~DefinitionSquare(void);
};

#endif
