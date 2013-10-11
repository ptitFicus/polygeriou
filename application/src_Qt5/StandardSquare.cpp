#include "StandardSquare.h"


StandardSquare::StandardSquare(void)
{
    this->content=' ';
    this->expected=' ';
    this->modifiable=true;
    this->wordCount=0;
    this->options.push_back("Correct");
    this->options.push_back("Check");
    this->options.push_back("Empty");
    this->options.push_back("Modify");
}

StandardSquare::StandardSquare(char expected, char content)
{
    this->content=content;
    this->expected=expected;
    this->wordCount=0;
    this->modifiable=true;
    this->options.push_back("Correct");
    this->options.push_back("Check");
    this->options.push_back("Empty");
    this->options.push_back("Modify");

}

StandardSquare::~StandardSquare(void)
{
}

StandardSquare::StandardSquare(const StandardSquare &s)
{
    this->content = s.content;
    this->wordCount=s.wordCount;
    this->expected = s.expected;
    this->modifiable = s.getModifiable();
    this->options = s.options;
}

void StandardSquare::correct()
{
    this->content=expected;
    this->modifiable = false;
}

void StandardSquare::changeContent(char c)
{
    this->content=c;
}
bool StandardSquare::check()
{
    if(this->content==this->expected){
        return true;
    }else{
        return false;
    }
}

void StandardSquare::clear()
{
    this->content = ' ';
}

vector<string> StandardSquare::getOptions(){
    return this->options;
}

int StandardSquare::getWordCount(){
    return this->wordCount;
}

StandardSquare& StandardSquare::operator=(const StandardSquare &s)
{
    this->content = s.content;
    this->expected = s.expected;
    this->modifiable = s.modifiable;
    return *this;
}

string StandardSquare::toString()
{
    char tab[4] ;
    tab[0] = this->content;
    tab[1] = ';';
    tab[2] = this->expected;
    tab[3] = '\0';
    return string(tab);
}
