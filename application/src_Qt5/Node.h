#ifndef NODE_H
#define NODE_H
#include <vector>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

class Node
{
    public:
        Node();
        ~Node();
        Node (const Node& other);
        Node& operator=(const Node& other);
        Node (char c);

        /**
         * @brief Give content of this node
         *
         * @return the char contained by this node
         */
        char getContent();

        /**
         * @brief provide next nodes
         *
         * @return a vector containing next nodes
         */
        vector<Node*> getNext();

        /**
         * @brief Add a son node to this node
         *
         * @param aNode the son
         */
        void addNext(Node* aNode);

        /**
         * @brief Indicate if this node has son containing a given char
         *
         * @param c the seeked char
         *
         * @return true if one of this node's son contains c, false otherwise
         */
        bool hasChar(char c);

        /**
         * @brief give son's count of this node
         *
         * @return this node son's count
         */
        unsigned int getSonCount();

        /**
         * @brief give content of a son of this node
         *
         * @param i index of the son
         *
         * @return char contained in the son number i
         */
        char operator[] (unsigned int i) const;

        /**
         * @brief Add a word from this node
         *
         * @param spelling the word to add
         */
        void addWord(const string& spelling);

        Node* findSon(char c);

        bool isEnd();

        Node* getFather();

        void addSon(Node *n);

        inline int getDepth(){return depth;};

        bool deleteSon (char c);

        unsigned int getMaxLength();
        unsigned int getMinLength();
        friend vector<char> getIntersection(Node* n1, Node* n2, unsigned int firstMaxLength, unsigned int secondMaxLength);
        inline bool hasBeenExplored (){return explored>0;}
        inline void setExplored (){explored++;}
        inline void setUnexplored (){if(explored > 0)explored --;}
        vector<char> getSonForMaxLength(unsigned int maxLength);
    private:
        vector<Node*> nextNodes;
        char content;
        bool isFinal;
        int explored;
        Node *father;
        int depth;
        unsigned int maxLength;
        unsigned int minLength;
        bool wordAdded;
};




#endif
