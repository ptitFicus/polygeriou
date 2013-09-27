#ifndef WORD_H
#define WORD_H
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


class Word
{
    public:
        Word (const Word& other);
        Word(const string& aSpelling);

        /**
         * @brief Constructor
         *
         * @param aSpelling spelling of the new word
         * @param def vector of definitions for the word
         */
        Word(const string& aSpelling, const vector<string>& def);
        ~Word();
        Word& operator=(const Word& other);
        Word();
        char operator[](int i) const;

        /**
         * @brief Give a random definition of the current word
         *
         * @return a randomed chosen definition of the current word
         */
        string getRandomDefinition() const; // TODO : in case of no definitions
        /**
         * @brief Add a definition to the current Word
         *
         * @param newDefinition the definition to add
         */
        void addDefinition (const string& newDefinition);
        inline string getSpelling()const{return spelling;};
        inline vector<string> getDefinitions() const {return definitions;};
        friend ostream& operator<<(ostream&  stream, const Word& w);
        friend bool operator< (const Word& w1, const Word& w2);
        friend bool operator== (const Word& w1, const Word& w2);
        const static char separatorWordDef = ':';
        const static char separatorDef = ';';
        operator string() const;
        int getSize() const;
    private:
        string spelling;
        vector<string> definitions;
};

#endif
