#ifndef GRID_H
#define GRID_H

#include <string>
#include <iostream>
#include <vector>
#include <QObject>
#include<fstream>
#include "Square.h"
#include "DefinitionSquare.h"
#include "StandardSquare.h"
#include "Node.h"
#include "Dictionnary.h"
using namespace std;

class Grid : public QObject
{
    Q_OBJECT
public:
    enum align { horiz, vert, decHoriz, decVerti}; //alignment of the word

    Grid(void);
    Grid(int height, int width);
    Grid(int height, int width, vector<Square*> squares);




    Grid& operator=(const Grid& grid);
    friend ostream& operator<<(ostream& os, Grid& g);

    vector<Square*> getSquares();
    int getHeight();
    int getWidth();

    void setSize(int w, int h);

    void addWord(string word, string def, align a, int x, int y);
    void addTwoWords(string word1, string word2, string def1, string def2, align a1, align a2, int x, int y);

    bool check();
    void correct(int x, int y);
    void deleteContent();
    void updateContent();
    Square* getSquare(int x, int y);
    DefinitionSquare* getHorizDef(StandardSquare* stdSquare, bool* lower);
    DefinitionSquare* getVertiDef(StandardSquare* stdSquare, bool* lower);


    bool Xport(string path, bool empty);
    bool import(string path);
    vector<string> split(string csvline);


    /**
     * Generate a new grid based on given dictionaries and dimensions
     * @param dictionaries list of dictionaries to use for new grid's generation
     * @param height height of the new grid
     * @param width width of the new grid
     * @return true if the function was able to generate the grid, false otherwise
     */
    bool fill(const vector<Dictionnary*>& dictionary, int height, int width);

    const list<Word> mergeAllDictionnaries(const vector<Dictionnary*>& d);
    void displayGrid(char**grid);
    void setContent(int x, int y, char c);
    ~Grid(void);


signals:
    void contentChanged(int x, int y, char);
    void iterationFailed(int);

public slots:


private:
    int height;
    int width;
    int iterationCount;
    clock_t tempsDebut;
    vector<Square*> squares;

    //private methods
    void addStandardSquares(DefinitionSquare* defSq, string word, align a, int x, int y, bool upper = true);

    void initRoot(const vector<Dictionnary*>& dic, Node* root);

    /**
         * Recursive method used to fill the grid with dictionaries' Words
         * @param line the line of the case
         * @param column the column of the case
         * @param grid the grid to fill
         * @param node the tree fill with dictionaries content
         * @return
         */
    int seekChar(int line, int column, char** grid, Node** nodes, Node* root);

    /**
         * Determine if a definition case is possible at the given square
         * @param height height of the grid
         * @param width width of the grid
         * @param line square's line
         * @param column square's column
         * @param grid
         * @return true if a definition square is possible, false otherwise
         */
    bool isDefinitionPossible(int line, int column, char** grid);
    void initDefinitions(char** grid);
    int getLineMaxSize(int x, int y, char** grid);
    int getColMaxSize(int x, int y, char** grid);
    void convertCharGrid(char** grid, const list<Word>& content);
    Word findLineWord(char** grid, int line, int column, const list<Word> content);
    Word findColWord(char** grid, int line, int column, const list<Word> content);
    void initPreplacedDefinitions(char** grid);

};

#endif
