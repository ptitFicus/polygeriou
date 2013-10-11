#include <iostream>

#include "Node.h"

using namespace std;

Node :: Node():nextNodes(),content('\0'), isFinal(false), explored(0), father(NULL), depth(0), maxLength(0), minLength(0), wordAdded(false)
{}

char Node :: getContent()
{
    return content;
}

vector<Node*> Node :: getNext()
{
    return nextNodes;
}

Node ::Node(char c):nextNodes(), content(c), isFinal(false), explored(0), father(NULL), depth(0), maxLength(0), minLength(0), wordAdded(false)
{
}

void Node :: addNext(Node* aNode)
{
    aNode->depth = depth +1;
    nextNodes.push_back(aNode);
}

Node :: ~Node()
{
    vector<Node*>::iterator it= nextNodes.begin();
    for (;it != nextNodes.end(); it++)
        delete *it;
}

Node :: Node (const Node& other):nextNodes(other.nextNodes.size())
{
    content = other.content;
    isFinal = other.isFinal;
    explored = other.explored;
    father = other.father;
    depth = other.depth;
    maxLength = other.maxLength;
    minLength = other.minLength;
    wordAdded = other.wordAdded;
    for (unsigned int i = 0 ; i < other.nextNodes.size() ; i++)
    {
        nextNodes[i] = new Node(*(other.nextNodes[i]));
    }
}

Node& Node :: operator=(const Node& other)
{
    // Delete current next elements
    vector<Node*>::iterator it= nextNodes.begin();
    for (;it != nextNodes.end(); it++)
        delete *it;

    content = other.content;
    isFinal = other.isFinal;
    explored = other.explored;
    father = other.father;
    depth = other.depth;
    maxLength = other.maxLength;
    minLength = other.minLength;
    wordAdded = other.wordAdded;
    for (unsigned int i = 0 ; i < other.nextNodes.size() ; i++)
    {
        nextNodes[i] = new Node(*(other.nextNodes[i]));
    }

    return *this;
}

bool Node :: hasChar(char c)
{
    vector<Node*>::iterator it = nextNodes.begin();
    bool ret = false;
    while (it != nextNodes.end())
    {
        if ((*it)->content == c)
        {
            ret = true;
            break;
        }
        it++;
    }
    return ret;
}

unsigned int Node :: getSonCount()
{
    return nextNodes.size();
}

char Node :: operator[] (unsigned int i) const
{
    if (i >= nextNodes.size())
        return '\0';
    else
        return nextNodes.at(i)->content;
}

vector<char> getIntersection(Node *n1, Node *n2, unsigned int firstMaxLength, unsigned int secondMaxLength)
{
    vector<char> ret;
    Node& a = *n1;
    Node& b = *n2;
    for (unsigned int i = 0 ; i < a.getSonCount() ; i++)
    {
        for (unsigned int j = 0 ; j < b.getSonCount() ; j++)
        {
            if(b.nextNodes.at(j)->getContent() == a.nextNodes.at(i)->getContent() && a.nextNodes.at(i)->getMinLength() <= firstMaxLength && b.nextNodes.at(j)->getMinLength() <= secondMaxLength)
            {
                #ifdef DEBUG
                cout << "Lettre " << b.nextNodes.at(j)->getContent() << " retenue. Longueur de la ligne : " << a.nextNodes.at(i)->getMinLength() << ". Longueur pour la colonne : " << b.nextNodes.at(j)->getMinLength()<<endl;
                #endif
                ret.push_back(a[i]);
                break;
            }
        }
    }
    return ret;
}


void Node::addWord(const string& spelling)
{
    //cout << "AddWord pour le mot : " << spelling << endl;
    //cout << "Nombre de fils du noeud : " << getSonCount() << endl;
    if (spelling.size() > 0 && spelling.at(0) != ' ')
    {
        if (!wordAdded)
        {
            minLength = spelling.size();
            wordAdded = true;
        }
        vector<Node*>::iterator it = nextNodes.begin();
        bool found = false;
        char c = spelling.at(0);
        //cout << "Recherche du caractère " << c << endl;
        for(;it!= nextNodes.end() ; it++)
        {
            //cout << (*it)->content;
            if((*it)->content == c)
            {
                //cout << " : trouvé ! " << endl;
                (*it)->addWord(spelling.substr(1));
                found = true;
                break;
            }
        }
        if (!found)
        {
            //cout << "pas trouvé" << endl;
            Node* n = new Node(c);
            addNext(n);
            n->addWord(spelling.substr(1));
        }
        if (spelling.size() < minLength)
            minLength = spelling.size();
        else if (spelling.size() > maxLength)
            maxLength = spelling.size();
    }
    else
    {
        nextNodes.push_back(new Node('\0'));
        minLength = 0;
        if (!wordAdded)
            wordAdded = true;
      //  cout << "Final : " <<this->content<< endl;
        isFinal = true;
    }
}

bool Node :: isEnd()
{
    return isFinal;
}

Node* Node :: findSon(char c)
{
    vector<Node*>::iterator it = nextNodes.begin();
    for(;it!= nextNodes.end() ; it++)
    {
        if ((*it)->content == c)
            return *it;
    }
    return NULL;
}


Node* Node :: getFather()
{
    return this->father;
}

void Node :: addSon(Node *n)
{
    n->depth = depth +1;
    nextNodes.push_back(n);
}

bool Node :: deleteSon (char c)
{
    if (nextNodes.back()->getContent() == c)
    {
        nextNodes.pop_back();
        return true;
    }
    else
    {
        for (vector<Node*>::iterator it = nextNodes.begin(); it != nextNodes.end() ; it++)
        {
            if ((*it)->getContent() == c)
            {
                nextNodes.erase(it);
                return true;
            }
        }
    }
    return false;
}

unsigned int Node::getMaxLength()
{
    return maxLength;
}

unsigned int Node::getMinLength()
{
    return minLength;
}

vector<char> Node :: getSonForMaxLength(unsigned int maxSize)
{
    vector<char> ret;
    vector<Node*>::iterator it = this->nextNodes.begin();
    for(; it != nextNodes.end(); it++)
    {
        if((*it)->minLength <= maxSize)
        {
            ret.push_back((*it)->getContent());
        }
    }
    return ret;
}
