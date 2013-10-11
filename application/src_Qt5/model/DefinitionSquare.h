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

public:
    /**
     * @brief upperWordSquares StandardSquares associate with the word positionned in uppper position
     */
    vector<StandardSquare*> upperWordSquares;

    /**
     * @brief lowerWordSquaresStandardSquares associate with the word positionned in lower position
     */
    vector<StandardSquare*> lowerWordSquares;

    /**
     * @brief DefinitionSquare Default constructor
     */
    DefinitionSquare(void);

    /**
     * @brief DefinitionSquare Constructor with two words
     * @param upperWord the word to place in upper position
     * @param lowerWord the word to place in lower position
     */
    DefinitionSquare(Word upperWord, Word lowerWord);

    /**
     * @brief DefinitionSquare Constructor with only one word
     * @param word The only word to associate with this DefinitionSquare
     */
    DefinitionSquare(Word word);

    /**
     * @brief DefinitionSquare Copy constructor
     * @param sq DefinitionSquare to copy
     */
    DefinitionSquare(const DefinitionSquare& sq);

    /**
     * @brief operator =
     * @param sq DefinitionSquare to copy
     * @return pointer on the current object
     */
    DefinitionSquare& operator=(const DefinitionSquare& sq);

    /**
     * @brief getUpperWordDefinition
     * @return definition associate with the upper word of this case
     */
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
