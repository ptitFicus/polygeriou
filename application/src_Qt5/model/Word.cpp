#include <iostream>

#include "Word.h"

using namespace std;

Word :: Word():spelling(), definitions()
{}

Word :: Word (const Word& other):spelling(other.spelling), definitions(other.definitions)
{}

Word :: Word (const string& aSpelling, const vector<string>& def):
    spelling(aSpelling), definitions(def)
{}

Word& Word :: operator=(const Word& other)
{
    spelling = other.spelling;
    definitions = other.definitions;
    return *this;
}

char Word :: operator[] (int i) const
{
    return spelling.at(i);
}

string Word :: getRandomDefinition () const
{
    if (definitions.size() != 0)
    {
        srand(time(NULL));
        int i = rand() % definitions.size();
        return definitions.at(i);
    }
    else
    {
        // If there is no definition, return an empty string
        string s;
        return s;
    }
}

Word :: ~Word(){}

void Word::addDefinition(const string& newDefinition)
{
    definitions.push_back(newDefinition);
}

Word::Word(const string& aSpelling):spelling(aSpelling), definitions()
{}

ostream& operator<<(ostream& stream, const Word& w)
{
    stream << w.spelling<< Word::separatorWordDef;
    if (w.definitions.size() > 0)
    {
        vector<string>::const_iterator it = w.definitions.begin();
        stream << *it;
        it++;
        for (; it != w.definitions.end(); ++it)
        {
            stream <<Word::separatorDef<< *it;
        }
    }
    return stream;
}

Word :: operator string() const
{
    string s = spelling + Word::separatorWordDef;
    if (definitions.size() > 0)
    {
        vector<string>::const_iterator it = definitions.begin();
        s = s + *it;
        it ++;
        for (; it != definitions.end() ; ++it)
        {
            s = s + Word::separatorDef + *it;
        }
    }
    return s;
}

int Word :: getSize() const
{
    return spelling.size();
}

bool operator< (const Word& w1, const Word& w2)
{
    return (w1.spelling < w2.spelling);
}

bool operator==(const Word& w1, const Word& w2)
{
    if (w1.spelling == w2.spelling)
    {
        if (w1.definitions == w2.definitions)
            return true;
        else
            return false;
    }
    else
        return false;
}
