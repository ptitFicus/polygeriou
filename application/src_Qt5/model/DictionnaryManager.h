#ifndef DICTIONNARYMANAGER_H
#define DICTIONNARYMANAGER_H
#include <list>
#include <map>
#include <string>
#include <QObject>

#include "Dictionnary.h"

using namespace std;

class DictionnaryManager : public QObject
{
    Q_OBJECT
public:
    DictionnaryManager();
    ~DictionnaryManager();
    DictionnaryManager& operator= (const DictionnaryManager& other);
    DictionnaryManager(const DictionnaryManager& other);


    /**
         * @brief add a dictionnary to this dictionnary manager
         *
         * @param name identifiers of the dictionnary
         * @param path path to the file which contains the dictionnary
         */
    void addDictionnary (string name, string path);



    /**
         * @brief Delete a ditcionnary from the current manager
         *
         * @param name the name of the dictionnary to delete
         */
    void deleteDictionnary (const string& name);


    /**
         * @brief Give the content of one dictionnary
         *
         * @param name the name of the wanted dictionnary
         *
         * @return content of the dictionnary
         */
    map<string, vector<string> > getContent (string name);

    /**
         * @brief Append a Word at a dictionnary
         *
         * @param dictionnaryName the name of the dictionnary which will received the new word
         * @param spelling the spelling of the new word
         * @param definitions list of definitions for the new word
         *
         * @return true if the append was a success, false otherwise
         */
    bool addWord(string dictionnaryName, string spelling, vector<string> definitions);

    /**
         * @brief Delete a word from a dictionnary
         *
         * @param dictionnaryName the name of the dictionnary which will loose a word
         * @param spelling the spelling of the word to delete
         * @param definitions definitions associate with the word to delete
         *
         * @return
         */
    bool deleteWord(string dictionnaryName, string spelling, vector<string> definitions);

    /**
         * @brief Modify a word in a dictionnary
         *
         * @param dictionnaryName the name of the dictionnary which will be modify
         * @param oldSpelling the old spelling of the word to modify
         * @param oldDefinitions the old definitions of the word to modify
         * @param newSpelling the new spelling for the word
         * @param newDefinitions new definitions for the word
         *
         * @return
         */
    bool modifyWord(string dictionnaryName, string oldSpelling, vector<string> oldDefinitions, string newSpelling, vector<string> newDefinitions);

    bool isInDictionnary(string dictionnary, string word);

    list<string> getDictionnaryNames();

    Dictionnary* getDictionnary(string name);

signals:
    void wordAdded();
    void dictionnaryAdded(string dictionnaire);

private:
    list<string> names;
    map<string, Dictionnary*> dictionnaries;

};

#endif
