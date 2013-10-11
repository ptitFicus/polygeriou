#include "DefinitionSquare.h"


DefinitionSquare::DefinitionSquare(void)
{
    this->wordCount=-1;
    this->upperWord = Word();
    this->lowerWord = Word();
    this->options.push_back("Corriger lower");
    this->options.push_back("Corriger upper");
}

DefinitionSquare::DefinitionSquare(const DefinitionSquare& sq)
{
    this->wordCount = sq.wordCount;
    this->upperWord=sq.upperWord;
    this->lowerWord=sq.lowerWord;
    this->upperWordDefinition = sq.upperWordDefinition;
    this->lowerWordDefinition = sq.lowerWordDefinition;
    this->options = sq.options;
    this->upperWordSquares = sq.upperWordSquares;
    this->lowerWordSquares = sq.lowerWordSquares;
}
DefinitionSquare& DefinitionSquare:: operator=(const DefinitionSquare& sq)
{
    this->wordCount = sq.wordCount;
    this->upperWord=sq.upperWord;
    this->lowerWord=sq.lowerWord;
    this->upperWordSquares = sq.upperWordSquares;
    this->lowerWordSquares = sq.lowerWordSquares;
    this->upperWordDefinition = sq.upperWordDefinition;
    this->lowerWordDefinition = sq.lowerWordDefinition;
    this->options = sq.options;

    return *this;
}

void DefinitionSquare::correctUpperWord()
{
    for(vector<StandardSquare*>::iterator it = upperWordSquares.begin(); it != upperWordSquares.end(); ++it) {
        (*it)->correct();
    }
}
void DefinitionSquare::correctLowerWord()
{
    for(vector<StandardSquare*>::iterator it = lowerWordSquares.begin(); it != lowerWordSquares.end(); ++it) {
        (*it)->correct();
    }
}

DefinitionSquare::~DefinitionSquare(void)
{
}

string DefinitionSquare::toString(){
    return string(upperWord.getSpelling())+";"+lowerWord.getSpelling();
}

DefinitionSquare::DefinitionSquare(Word upper, Word lower)
{
    //On récupère les mots qui correspondent aux définitions
    this->upperWord = upper;
    this->lowerWord = lower;

    /*Deprecated
    //Pour chaque lettre du mot upper, on remplit la liste des cases uppers
    for(unsigned int i=0;i<upper.getSpelling().length();i++){
        this->upperWordSquares.push_back(StandardSquare(' ',upper.getSpelling()[i]));
    }

    //On fait pareil pour le mot lower
    for(unsigned int i=0;i<lower.getSpelling().length();i++){
        this->lowerWordSquares.push_back(StandardSquare(' ',lower.getSpelling()[i]));
    }
    */
    this->upperWordDefinition = upperWord.getRandomDefinition();
    this->lowerWordDefinition = lowerWord.getRandomDefinition();

    this->wordCount=2;
}

DefinitionSquare::DefinitionSquare(Word upper)
{
    //On récupère les mots qui correspondent aux définitions
    this->upperWord = upper;
    this->upperWordDefinition = upper.getRandomDefinition();
    /*Deprecated
    //Pour chaque lettre du mot upper, on remplit la liste des cases upperes
    for(unsigned int i=0;i<upper.getSpelling().length();i++){
        this->upperWordSquares.push_back(StandardSquare(' ',upper.getSpelling()[i]));
    }
    */
    this->wordCount=1;
}

bool DefinitionSquare::checkUpperWord()
{
    for(vector<StandardSquare*>::iterator it = upperWordSquares.begin(); it != upperWordSquares.end(); ++it) {
        if((*it)->content!=(*it)->expected)
        {
            return false;
        }

    }
    return true;
}
bool DefinitionSquare::checkLowerWord()
{
    for(vector<StandardSquare*>::iterator it = lowerWordSquares.begin(); it != lowerWordSquares.end(); ++it) {
        if((*it)->content!=(*it)->expected)
        {
            return false;
        }

    }
    return true;
}

int DefinitionSquare::getWordCount(){
    return this->wordCount;
}

string DefinitionSquare::getUpperWordDefinition()
{
    return this->upperWordDefinition;
}

string DefinitionSquare::getLowerWordDefinition()
{
    return this->lowerWordDefinition;
}
