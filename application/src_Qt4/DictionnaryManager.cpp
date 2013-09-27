#include "DictionnaryManager.h"
#include <iostream>

using namespace std;

DictionnaryManager :: DictionnaryManager(): names(), dictionnaries()
{}


DictionnaryManager :: ~DictionnaryManager ()
{
    map<string, Dictionnary*>::iterator it = dictionnaries.begin();
    for (; it != dictionnaries.end() ; it ++)
    {
        delete it->second;
    }
}

DictionnaryManager :: DictionnaryManager(const DictionnaryManager& other):
    names(other.names), dictionnaries(other.dictionnaries)
{}

DictionnaryManager& DictionnaryManager :: operator= (const DictionnaryManager& other)
{
    names.clear();
    dictionnaries.clear();
    names = other.names;
    dictionnaries = other.dictionnaries;
    return *this;
}

void DictionnaryManager::deleteDictionnary(const string& name)
{
    dictionnaries.erase(name);
    names.remove(name);
}

map<string, vector<string> > DictionnaryManager :: getContent (string name)
{
    map<string, vector<string> > ret;
    Dictionnary* dic =dictionnaries.find(name)->second;
    list<Word> wordList = dic->getWords();

    for(list<Word>::const_iterator it = wordList.begin() ; it != wordList.end() ; it++)
    {
        ret.insert(pair<string, vector<string> >((*it).getSpelling(), (*it).getDefinitions()));
    }

    return ret;
}


bool DictionnaryManager :: addWord(string dictionnaryName, string spelling, vector<string> definitions)
{
    Word w(spelling, definitions);
    bool ret = false;
    map<string, Dictionnary*>::iterator it = dictionnaries.find(dictionnaryName);
    if (it != dictionnaries.end())
    {
        Dictionnary* d = it->second;
        ret = d->addWord(w);
        emit wordAdded();
    }
    else{
        ret =  false;
    }

    return ret;
}

bool DictionnaryManager :: deleteWord(string dictionnaryName, string spelling, vector<string> definitions)
{
    Word w(spelling, definitions);
    map<string, Dictionnary*>::iterator it = dictionnaries.find(dictionnaryName);
    if(it != dictionnaries.end())
    {
        Dictionnary* d = it->second;
        return d->deleteWord(w);
    }
    else
        return false;
}

bool DictionnaryManager :: modifyWord(string dictionnaryName, string oldSpelling, vector<string> oldDefinitions, string newSpelling, vector<string> newDefinitions)
{
    Word oldWord(oldSpelling, oldDefinitions);
    Word newWord(newSpelling, newDefinitions);

    map<string,Dictionnary*>::iterator it = dictionnaries.find(dictionnaryName);
    if (it != dictionnaries.end())
    {
        Dictionnary* d = dictionnaries.find(dictionnaryName)->second;

        return d->modifyWord(oldWord, newWord);
    }
    else{
        return false;
    }
}

list<string> DictionnaryManager::getDictionnaryNames()
{
    return names;
}

Dictionnary* DictionnaryManager::getDictionnary(string name)
{
    for(map<string, Dictionnary*>::iterator it = dictionnaries.begin();
        it != dictionnaries.end() ; it++)
    {
        if(it->first == name)
        {
            return it->second;
        }
    }
    return nullptr;
}


void DictionnaryManager::addDictionnary (string name, string path)
{

    Dictionnary* d = new Dictionnary(name, path);
    names.push_back(name);
    dictionnaries.insert(pair<string, Dictionnary*>(name, d));
    dictionnaryAdded(name);
}

bool DictionnaryManager::isInDictionnary(string dictionnary, string word){
    map<string, vector<string> > liste = this->getContent(dictionnary);
    map<string, vector<string> >::iterator itFind = liste.find(word);
    map<string, vector<string> >::iterator itEnd = liste.end();

    bool ret = false;

    if(itFind == itEnd)
        ret = false;
    else
        ret = true;

    return ret;

}
