#include "Grid.h"

void displayFinalGrid(vector<Square*>sq);
//Constructeur par d?faut
Grid::Grid(void)
{
    height=0;
    width=0;

    squares = vector<Square*>();
}

/** Constructeur avec initialisation de la taille de la grille**/
Grid::Grid(int height, int width){
    this->height=height;
    this->width=width;
    squares = vector<Square*>();
}

/** Constructeur en reseignant tous les attributs**/
Grid::Grid(int height, int width, vector<Square*> squares){
    this->height=height;
    this->width=width;
    this->squares=squares;
}

/** Destructeur **/
Grid::~Grid(void)
{
    for(vector<Square*>::iterator it = squares.begin(); it != squares.end(); ++it) {
        delete *it;
    }
}



/** Surcharge de  l'affectation **/
Grid& Grid::operator=(const Grid& g){
    this->height = g.height;
    this->width = g.width;
    this->squares = g.squares;

    return *this;
}

/** Surcharge de l'op?rateur << pour affichage simple**/
ostream& operator<<(ostream& os, Grid &g){
    //Si la liste est vide, on renvoie dans le flux un message
    if(g.squares.size()==0){
        return os << "  La grille est vide ! ";
    }
    //Sinon on parcourt les ?l?ments du vecteur et on affiche
    else{
        for(unsigned int j=0;j<g.getSquares().size();j++){
            int k=j;
            if((k%g.width)==0){
                os<<endl;
            }
            os<<g.getSquares().at(j)->toString()<<" | ";

        }
        return os;
    }
}

void Grid::setContent(int x, int y, char c) {
    StandardSquare* square = dynamic_cast<StandardSquare*>(getSquare(x,y));

    if(square->getModifiable() && square->content != c) {
        square->content = c;
        emit contentChanged(x, y, c);
    }

}

/** **/
bool Grid::check(){

    return 1;
}
void Grid::correct(int x, int y){
    StandardSquare* square = dynamic_cast<StandardSquare*>(getSquare(x,y));
    square->correct();
    emit contentChanged(x,y,square->content);
}

void Grid::deleteContent() {

    for(vector<Square*>::iterator it = squares.begin(); it != squares.end(); ++it) {
        if((*it)->getWordCount() == 0) {
            StandardSquare* s = dynamic_cast<StandardSquare*>((*it));
            if(s->getModifiable()) {
                s->content = ' ';
                emit contentChanged(s->getX(), s->getY(), ' ');
            }

        }
    }

}

/*Fonction pour exporter une grille en fichier texte.
* Premiere ligne :Hauteur,Largeur de la grille
* Autres lignes: Cases lue de gauche a droite, haut en bas
* Case lettre : contenu;reponse
* Case définition:
*/
bool Grid::Xport(string path, bool empty){

    int compteur=1;
    ofstream fichier(path, ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

        if(fichier)
        {
            //On ecrit la hauteur et la largeur de la grille
            fichier<<this->height<<";"<<this->width<<endl;

            //Pour chaque case de la grille
            //for(unsigned int i=0; i<this->squares.size();i++){
            for (vector<Square*>::iterator it = squares.begin(); it!=squares.end(); ++it) {
                Square* sq = (*it);
                //Cas d'une case de définition
                if(sq->getWordCount()>=1){

                    //On écrit un numero unique, puis la définition du haut (celle obligatoire)
                    fichier<<compteur<<";"<< (dynamic_cast<DefinitionSquare *>(sq) )->getUpperWordDefinition();
                    compteur++;
                    //On récupère la deuxieme definition et on regarde si elle existe. Si oui, on l'écrit.
                    string s = (dynamic_cast<DefinitionSquare *>(sq) )->getLowerWordDefinition();
                    if(!s.empty()){
                        fichier<<";"<<compteur<<";"<<s<<endl;
                        compteur++;
                    }
                    else{
                        fichier<<endl;
                    }

                }
                //Sinon, cas d'une case standard
                else{
                    if(!empty){
                        fichier<<(dynamic_cast<StandardSquare *>(sq))->content<<";";
                    }
                    else{
                        fichier<<" ;";
                    }

                    fichier<<(dynamic_cast<StandardSquare *>(sq))->expected<<endl;
                }

            }
            fichier.close();
            return 1;
        }
        else{
                cerr << "Impossible d'ouvrir le fichier !" << endl;
                return 0;
        }
}
/*
*  Méthode d'import d'une grille à partir du fichier texte. On lit le fichier ligne par ligne.
* On utilise la méthode split pour avoir la ligne eclatée par ;. Selon la taille du vecteur de split,
* On sait quel type de case on importe. Une case de definition est identifiée par un chiffre en premier caractere.
* Si le vecteur est de taille 4 : Case de definition a deux mots.
*/
bool Grid::import(string path){
    squares.clear();


    //Ouverture du fichier
    ifstream fichier(path);
    vector<string> split;
        //Si on arrive a ouvrir le fichier
        if(fichier)
        {
            //Chaine de caractere qui contient la ligne courante.
            string contenu="";
            //On récupère d'abord la hauteur et la largeur de la grille, ce qui est la premiere info du fichier.
            int hauteur;
            int largeur;

            //On récupère la premiere ligne de fichier dans la variable contenu
            getline(fichier, contenu);

            //On éclate la string par le ;
            split = this->split(contenu);
            //Si on a plus ou moins de deux infos, on arrete      //A FAIRE : VERIFIER QUE LES TAILLES NE SONT QUE DES CHIFFRES
            if(split.size()!=2){
                return 0;
            }
            //Sinon on rempli les tailles
            largeur = atoi(string(split.at(0)).c_str());
            hauteur = atoi(string(split.at(1)).c_str());
            //Variables locales pour créer des objets dans la boucle
            DefinitionSquare* df;
            StandardSquare* sq;

            //Positions
            int x = 0;
            int y = 0;

            //Création de Cases au cas par cas
            while(getline(fichier, contenu)){
                split = this->split(contenu);

                //Vérification du format de la ligne
                if(split.size()==0 || split.size()==3 || split.size()>4){
                    //cout<<"Ligne erronée ! : "<<split.size()<<" : "<<contenu<<endl;
                    return 0;
                }
                //Cas de case de définition
                if(split.at(0)[0]>='0' && split.at(0)[0]<='9'){
                    //Cas ou on a deux definitions
                    if(split.size()>2){
                        //cout<<"DF2 , "<<split.at(1)<<split.at(3)<<endl;
                        Word w;
                        w.addDefinition(split.at(1));

                        Word w2;
                        w2.addDefinition(split.at(3));

                        df = new DefinitionSquare(w,w2);
                        df->getUpperWordDefinition()=split.at(1);
                        df->getLowerWordDefinition()=split.at(3);
                        df->setPos(x,y);
                        if(x==largeur-1){
                            x=0;
                            y++;
                        }
                        else{
                            x++;
                        }
                        squares.push_back(df);

                    }
                    else{
                        Word w;
                        w.addDefinition(split.at(1));
                        df = new DefinitionSquare (w);
                        df->getUpperWordDefinition() = split.at(1);
                        df->setPos(x,y);
                        if(x==largeur-1){
                            x=0;
                            y++;
                        }
                        else{
                            x++;
                        }
                        squares.push_back(df);
                    }
                }
                //Sinon case standard
                else{
                    //On récupère le prmier caractère (normalement l'unique) pour instancier les cases
                    if(split.at(0).length()>1 || split.at(1).length()>1){
                        //cout<<"Le contenu ou la correction contient plus d'un caractère : "<<split.at(0)<<split.at(1)<<endl;
                        return 0;
                    }
                    sq = new StandardSquare(split.at(1)[0],split.at(0)[0]);
                    sq->setPos(x,y);

                    if(x==largeur-1){
                        x=0;
                        y++;
                    }
                    else{
                        x++;
                    }
                    squares.push_back(sq);

                }


            }

            for (vector<Square*>::iterator it = squares.begin(); it!=squares.end(); ++it) {
                if( ((*it)->getWordCount()==0) ){
                    StandardSquare* sq = (dynamic_cast<StandardSquare*>(*it));
                    //Remplissage des vecteurs de squares pour chaque case de def
                    //On insere chaque standardSquare dans 2 definition square.
                    bool b=true;
                    DefinitionSquare* assoDF = this->getHorizDef(sq, &b);
                    if(assoDF!=nullptr){
                        if(b){
                            assoDF->lowerWordSquares.push_back(sq);
                        }
                        else{
                            assoDF->upperWordSquares.push_back(sq);
                        }
                    }

                    assoDF = this->getVertiDef(sq, &b);
                    if(assoDF!=nullptr){
                        if(b){
                            assoDF->lowerWordSquares.push_back(sq);
                        }
                        else{
                            assoDF->upperWordSquares.push_back(sq);
                        }
                    }
                }
            }/*
            string s="";
            for (vector<Square*>::iterator it = squares.begin(); it!=squares.end(); ++it) {

                 if( ((*it)->getWordCount()>=1) ){
                     DefinitionSquare* df = (dynamic_cast<DefinitionSquare*>(*it));

                     for (vector<StandardSquare*>::iterator jt = df->upperWordSquares.begin(); jt!=df->upperWordSquares.end(); ++jt) {
                         StandardSquare* sq = (dynamic_cast<StandardSquare*>(*jt));
                         s = s+ sq->expected;
                     }
                     df->setUpperWord(Word(s));
                     s="";
                     if(((*it)->getWordCount()==2) ){
                         for (vector<StandardSquare*>::iterator kt = df->lowerWordSquares.begin(); kt!=df->lowerWordSquares.end(); ++kt) {
                             StandardSquare* sq = (dynamic_cast<StandardSquare*>(*kt));
                             s = s+ sq->expected;
                         }
                         df->setLowerWord(Word(s));
                         s="";
                     }
                     cout<<df->getLowerWord()<<"|||"<<df->getUpperWord();
                 }

            }*/

            //On affecte ensuite les infos extraites à la Grille
            this->height = hauteur;
            this->width = largeur;


            //On ferme le flux fichier
            fichier.close();
            return 1;
        }
        else{
                cerr << "Impossible d'ouvrir le fichier !" << endl;
                return 0;
        }
}

void Grid::updateContent() {
    for(int i = 0; i < squares.size(); i++) {
        if(squares.at(i)->getWordCount() == 0) {
            StandardSquare* s = dynamic_cast<StandardSquare*>(squares[i]);
            if(s->content != ' ' && s->content != '\0') {
                emit contentChanged(s->getX(), s->getY(), s->content);
            }
        }

    }
}

/**Méthode qui éclate une ligne csv avec ; comme séparateur.
* On parcourt un par un les caracteres de la lignes et on coupe quand on trouve un ;
* On mets les sous chaines dans un vecteur.
**/
vector<string> Grid::split(string csvline){
    string temp="";
    vector<string> v;
    int size=0;

    for(int i=0;i<csvline.length();i++){
        if(csvline.at(i)==';'){
            v.push_back(temp);
            temp="";
        }
        else{
            temp = temp + csvline.at(i);
        }
    }
    v.push_back(temp);
    return v;
}

/**
 * @brief Grid::addWord Add a def square and the stand squares for the word in parameters
 * @param word string representation of the word
 * @param def string representation of the definition that will be displayed
 * @param a alignement of the word
 * @param x x position of the definition square
 * @param y y position of the definition square
 */
void Grid::addWord(string word, string def, align a, int x, int y) {
    //Cr?e l'instance de Word en y mettant le mot et la definition
    Word w(word);
    w.addDefinition(def);
    //Cr?e la carr? de d?fintion et l'ajoute ? la grille
    DefinitionSquare* defSq = new DefinitionSquare(w);
    defSq->setPos(x,y);
    squares.push_back(defSq);

    addStandardSquares(defSq, word, a, x, y);


}

/**
 * @brief Grid::addTwoWords Add a def square containing two words
 * @param word1 first string word
 * @param word2 second string word
 * @param def1 first string def
 * @param def2 second string def
 * @param a1 first word alignment
 * @param a2 second word alignment (must obviously be different drom the first)
 * @param x x position of the def square
 * @param y y position of the def square
 */
void Grid::addTwoWords(string word1, string word2, string def1, string def2, align a1, align a2, int x, int y) {
    Word w1(word1);
    Word w2(word2);
    w1.addDefinition(def1);
    w2.addDefinition(def2);
    DefinitionSquare* defSq = new DefinitionSquare(w1, w2);
    defSq->setPos(x,y);
    squares.push_back(defSq);

    //Ajoute les cases du mot superieur
    addStandardSquares(defSq, word1, a1, x, y);
    //Ajoute les cases du mot inferieur
    addStandardSquares(defSq, word2, a2, x, y, false);


}

/**
 * @brief Grid::addStandardSquares Add the standard squares
 * @param defSq reference on the def square
 * @param word string word
 * @param a alignment of the word
 * @param x x position of the def square
 * @param y y position of the def square
 * @param upper true if it's the upper (or only) word, false if it's the lower one (optional, true by default)
 */
void Grid::addStandardSquares(DefinitionSquare* defSq, string word, align a, int x, int y, bool upper) {
    //Applique le d?calage en fonction de l'alignement
    switch(a) {
    case vert:
    case decHoriz:
        y++;
        break;
    case horiz:
    case decVerti:
        x++;
        break;
    }

    for(unsigned int i = 0; i< word.length(); i++) {
        Square* s = getSquare(x,y);
        if(s == nullptr) {

            s = new StandardSquare(word[i]);
            s->setPos(x, y);
            //Ajout ? la grille
            squares.push_back(s);
        }

        //Ajout de la reference a la case de definition
        if(upper)
            defSq->upperWordSquares.push_back(dynamic_cast<StandardSquare *>(s));
        else
            defSq->lowerWordSquares.push_back(dynamic_cast<StandardSquare *>(s));

        //Incr?mente la case en fonction de l'alignement
        switch(a) {
        case horiz:
        case decHoriz:
            x++;
            break;

        case vert:
        case decVerti:
            y++;
            break;
        }
    }
}


void Grid::setSize(int w, int h) {
    width = w;
    height = h;

}
Square* Grid::getSquare(int x, int y) {
    for (vector<Square*>::iterator it = squares.begin(); it!=squares.end(); ++it) {
        if( ((*it)->getX() == x) && ((*it)->getY() == y) )
            return (*it);
    }
    return nullptr;
}


DefinitionSquare* Grid::getHorizDef(StandardSquare* stdSquare, bool* lower) {
    for(int x = stdSquare->getX(); x >= 0; x--) {
        Square* s = getSquare(x, stdSquare->getY());
        if(s->getWordCount() >0) {
            *lower = false;

            if(getSquare(s->getX()+2,s->getY()) == nullptr
                    || getSquare(s->getX()+2,s->getY())->getWordCount() != 0)
                return nullptr;

            return dynamic_cast<DefinitionSquare*>(s);
        }

    }
    Square* s2 = getSquare(0,stdSquare->getY()-1);


    if(s2 != nullptr) {
        if(s2->getWordCount() == 1)
            *lower = false;
        else
            *lower=true;

        return dynamic_cast<DefinitionSquare*>(s2);


    }

    else
        return nullptr;
}

DefinitionSquare* Grid::getVertiDef(StandardSquare* stdSquare,bool* lower ) {
    for(int y = stdSquare->getY(); y >= 0; y--) {
        Square* s = getSquare(stdSquare->getX(), y);
        if(s->getWordCount() >0){
            if(s->getWordCount() == 2)
                *lower = true;
            else
                *lower = false;

            if(getSquare(s->getX(),s->getY()+2) == nullptr
                    || getSquare(s->getX(),s->getY()+2)->getWordCount() != 0)
                return nullptr;

            return dynamic_cast<DefinitionSquare*>(s);
        }

    }

    Square* s2 = getSquare(stdSquare->getX()-1,0);
    *lower = false;
    if(s2 != nullptr)
        return dynamic_cast<DefinitionSquare*>(s2);
    else
        return nullptr;
}

//Accesseur Hauteur
int Grid::getHeight(){
    return this->height;
}
//Accesseur largeur
int Grid::getWidth(){
    return this->width;
}

vector<Square*> Grid::getSquares(){
    return this->squares;
}


void Grid :: initRoot(const list<Word>& dic, Node* root)
{
#ifdef DEBUG
    cout << "-----------------------------------------" << endl;
    cout << "initRoot()" << endl;
#endif

    for(list<Word>::const_iterator it = dic.begin();it != dic.end() ; it ++)
    {
#ifdef DEBUG
            //~ cout << "Mot : " << it->getSpelling() << endl;
#endif
        if (it ->getSize() <= height || it->getSize() <= width)
            root->addWord(it->getSpelling());
    }
    root->addSon(new Node('\0'));
#ifdef DEBUG
    cout << "Nombre de fils de la racine : " << root->getSonCount() << endl;
    cout << "Fin de initRoot" << endl;
    cout << "-----------------------------------------" << endl;
#endif
}

const list<Word> Grid::mergeAllDictionnaries(const vector<string>& d, DictionnaryManager *dm)
{
#ifdef DEBUG
    cout << "BEGIN of mergeAllDictionnaries" << endl;
#endif
    map<string, Dictionnary*>::iterator it = dm->dictionnaries.begin();
    list<Word> content = it->second->getWords();
#ifdef DEBUG
    cout << "BEGIN of the loop in mergeAllDictionnaries" << endl;
#endif
    it ++;
    while (it != dm->dictionnaries.end())
    {
#ifdef DEBUG
        cout << "BEGIN of loop iteration in mergeAllDictionnaries" << endl;
#endif
        it ++;
        list<Word>l = it->second->getWords();
        content.merge(l);
#ifdef DEBUG
        cout << "END of loop iteration in mergeAllDictionnaries" << endl;
#endif
    }
#ifdef DEBUG
    cout << "END of mergeAllDictionnaries" << endl;
#endif
    return content;
}

bool Grid::fill(const vector<string> &d, int height, int width, DictionnaryManager *dm)
{
#ifdef DEBUG
    cout << "BEGIN OF FILL" << endl;
#endif
    if (squares.size() != 0)
    {
        for (unsigned int i = 0 ; i<squares.size() ; i++)
        {
            delete squares.at(i);

        }
        squares.clear();
    }

    Node* root = new Node();
    this->height = height;
    this->width = width;
#ifdef DEBUG
    cout << "FILL BEFORE call to mergeAllDictionnaries" << endl;
#endif
    list<Word> dictionnaryContent = mergeAllDictionnaries(d, dm);
#ifdef DEBUG
    cout << "FILL AFTER call to mergeAllDictionnaries" << endl;
#endif
    initRoot(dictionnaryContent, root);

    Node** nodes = new Node* [height+width];
    for (int i = 0 ; i < height + width ; i++)
    {
        nodes[i] = root;
    }
    char **grid = new char*[height];

    for (int i = 0 ; i < height ; i++)
    {
        grid[i] = new char[width];
    }
    initDefinitions(grid);

    //initPreplacedDefinitions(grid);
    displayGrid(grid);

#ifdef DEBUG
    cout << "Apr?s l'init : " << endl;
    displayGrid(grid);


    cout << "-----------------------------------------" << endl;
    cout << "Appel de seekChar () " << endl;
#endif
    tempsDebut = clock();
    iterationCount = 0;
    clock_t beginTime = clock();
    emit(iterationFailed(1));
    int ret = seekChar(0, 1, grid, nodes, root);
    double currentEllapsedTime;
    while(ret!=1 && currentEllapsedTime < 60)
    {
        cout << "Retour en fill" << "(" << iterationCount <<")" << endl;
        initDefinitions(grid);
        for (int i = 0 ; i < height + width ; i++)
        {
            nodes[i] = root;
        }
        tempsDebut = clock();
        iterationCount = 0;
        ret = seekChar(0, 1, grid, nodes, root);
        currentEllapsedTime = (double)(clock() - beginTime)/CLOCKS_PER_SEC;
        cout << "Temps : " << currentEllapsedTime <<endl;
        emit(iterationFailed(currentEllapsedTime));
    }
    clock_t endTime = clock();
    double totalTime = (double)(endTime - tempsDebut)/CLOCKS_PER_SEC;
    cout << "Temps utile : " << totalTime;
#ifdef DEBUG
    cout << "Fin de seekChar()" << endl;
    cout << "-----------------------------------------" << endl;
#endif

    if(ret==1)
    {        displayGrid(grid);
        convertCharGrid(grid, dictionnaryContent);
    }
    //displayFinalGrid(this->squares);
    for (int i = 0 ; i < height ; i++)
    {
        delete [] grid[i];
    }
    delete [] grid;
    delete nodes;
    delete root;
    return ret==1;
}

void Grid::initDefinitions(char** grid)
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            grid[i][j] = '9';
        }
    }

    // Place definitions cases for the first line
    for (int i = 0 ; i < width ; i+=2)
    {
        if (i != width -1 )
        {
            grid[0][i] = '2';
        }else
        {
            grid[0][i] = '1';
        }
    }
    // Same for the first column
    for (int i = 2 ; i < height ; i+=2)
    {
        if (i != height -1 )
        {
            grid[i][0] = '2';
        }else
        {
            grid[i][0] = '1';
        }
    }
}

void Grid::initPreplacedDefinitions(char** grid)
{
    for (int line = 1 ; line < height ; line ++)
    {
        int size = 0;
        if(grid[1][0] == '1' || grid[1][0] == '2')
        {
            size = 1;
        }

        size = rand()%(width-1+size);
        if(size == width-1 || line == height-1)
        {
            grid[line][size] = '1';
        }
        else
        {
            grid[line][size] = '2';
        }
    }
}

void displayFinalGrid(vector<Square*> grid)
{
    for (unsigned int i = 0 ; i < grid.size() ; i++)
    {
        int wc = grid[i]->getWordCount();
        Square * cell = grid[i];
        switch(wc)
        {
        //            case 0:
        //            {
        //                cout << "Caract?re : ";
        //                StandardSquare* c = dynamic_cast<StandardSquare*>(cell);
        //                cout << c->expected<<endl;
        //                break;
        //            }
        case 1:
        {
            cout << "Definition : " << endl;
            DefinitionSquare* c = dynamic_cast<DefinitionSquare*>(cell);
            cout << c->getUpperWordDefinition() << ":"<<endl << " (lower)";
            vector<StandardSquare*>::iterator it = c->lowerWordSquares.begin();
            for(; it != c->lowerWordSquares.end(); it++)
            {
                cout << (*it)->content;
            }
            cout << endl;
            break;
        }
        case 2:
        {
            cout << "Definition : " << endl;
            DefinitionSquare* c = dynamic_cast<DefinitionSquare*>(cell);
            cout << c->getUpperWordDefinition() << endl;
            cout << c->getLowerWordDefinition() << endl;

            vector<StandardSquare*>::iterator it = c->lowerWordSquares.begin();
            cout << "(lower)";
            for(; it != c->lowerWordSquares.end(); it++)
            {
                cout << (*it)->content;
            }
            cout << endl <<"(upper)";

            it = c->upperWordSquares.begin();
            for(;it != c->upperWordSquares.end(); it++)
            {
                cout << (*it)->content;
            }
            cout << endl;
            break;
        }
        default:
            break;

        }
    }
}

int Grid::seekChar(int line, int column, char** grid, Node** nodes, Node* root)
{
    iterationCount ++;
    if(iterationCount >= 1700000)
    {
        return -1;
    }
#ifdef DEBUG
    cout << "Entr?e dans seekChar line = " << line << " colonne = " << column << endl;
#endif
    int newLine;
    int newColumn;

    //Initialise x and y for next call
    if (column < width -1)
    {
        newLine = line;
        newColumn = column+1;
    }
    else
    {
        newLine = line+1;
        newColumn = 0;
    }
    Node* colNode = nodes[column%width];
    Node* lineNode = nodes[width+line];
    if (grid[line][column] != '1' && grid[line][column] != '2')
    {
        // It isn't definition case
#ifdef DEBUG
        cout << "Ce n'est pas une case de definition " << endl;
#endif

#ifdef DEBUG
        cout << "Nombre de fils : " <<  lineNode->getSonCount()  << "/" << colNode->getSonCount() << endl;
#endif
        int ret = 0;

        // Find all possibilites to continue in this way
#ifdef DEBUG
        cout << "On recherche des possibilit?s de moins de " << getLineMaxSize(line,column,grid) << " pour la ligne et moins de " << getColMaxSize(line,column,grid) <<" pour la colonne";
#endif
        vector<char> possibilities;
        if(line == height-1 && grid[line-1][column]=='4')
        {
            possibilities = lineNode->getSonForMaxLength(getLineMaxSize(line, column, grid));
        }
        else if(column == width-1 && grid[line][column-1]=='4')
        {
            possibilities = colNode->getSonForMaxLength(getColMaxSize(line, column, grid));
        }
        else
        {
            possibilities = getIntersection(lineNode, colNode,getLineMaxSize(line,column,grid) , getColMaxSize(line,column,grid));
        }
        vector<char>::iterator it = possibilities.begin();
#ifdef DEBUG
        //            cout << "Caract?res possibiles : ";
        //
        //            for (list<char>::iterator it2 = possibilities.begin() ; it2 != possibilities.end() ; it2 ++)
        //                cout << *it2<< ", ";
        //            cout << endl;
        //            cout << "Nombre de caract?res possibles : " << possibilities.size() << endl;
#endif
        random_shuffle(possibilities.begin(), possibilities.end());
        for (; it!= possibilities.end() && !ret; it++)
        {
            if (*it == '\0')
            {
#ifdef DEBUG
                cout << "Fin des 2 mots possible, on place une case de dfinition" << endl;
#endif

                if((!isDefinitionPossible(line,column,grid)))
                {
#ifdef DEBUG
                    cout << "Pas possible de placer une d?finition ici" << endl;
#endif
                    continue;
                }
                else
                {
                    grid[line][column] = '4';
                    nodes [(column)%width] = root;
                    nodes [(width+line)] = root;
                }
            }
            else
            {
                //            	Node* potentialLineNode = lineNode->findSon(*it);
                //            	Node* potentialColNode = colNode->findSon(*it);
#ifdef DEBUG
                cout << "Caractre possible : " << *it << endl;
#endif
                if (column == width-1 && grid[line][column-1]!='4'&&  line != 0 && !lineNode->findSon(*it)->isEnd())
                {
#ifdef DEBUG
                    cout << "Derniere case de la ligne et le mot n'est pas fini !" << endl;
                    cout << lineNode->getContent() << " est final : " << lineNode->isEnd() << endl;
#endif
                    continue;
                }
                else if (line == height -1 && grid[line-1][column]!='4' && column!=0 && !colNode->findSon(*it)->isEnd() )
                {
#ifdef DEBUG
                    cout << "Derniere case de la colonne et le mot n'est pas fini ! " << endl;
#endif
                    continue;
                }
                grid[line][column] = *it;
#ifdef DEBUG
                cout << "Mise ? jour des nodes : " << column%width << "(colonne) et " << width+line <<"(ligne)" << endl;
#endif

                if(line != height-1 || grid[line-1][column]!='4')
                {
                    nodes [column%width] = colNode->findSon(*it);
                }
                if (column != width-1 || grid[line][column-1]!='4')
                {
                    nodes [width+line] = lineNode->findSon(*it);
                }
            }
            if (line == height-1 && column == width-1)
            {
                cout << "Grille compl?te !!!!! " << endl;
                return true;
            }
#ifdef DEBUG
            displayGrid(grid);
#endif
            ret = seekChar(newLine, newColumn, grid, nodes, root);
#ifdef DEBUG
            cout << "Retour en seekChar x=" << line << " y=" << column << endl;
#endif
            if (ret == 1 || ret == -1)
                break;
            nodes [(width+line)] = lineNode;
            nodes [(column)%width] = colNode;
        }
        return ret;
    }
    else
    {
        // C'est une case de d?finition, il faut r?initialiser les nodes de la ligne et de la colonne
        // pour les mots qui suivent
        nodes [(column)%width] = root;
        nodes [(width+line)] = root;
        //		nodes [(width+x)] = lineNode;
        //		nodes [(y)%width] = colNode;
        int res = seekChar(newLine, newColumn, grid, nodes, root);
        return res;
    }
}

int Grid :: getLineMaxSize(int x, int y, char** grid)
{
    if (x == 0)
    {
        return 100;
    }
    int count = 0;
    for (; (y>0 && y%(width) != 0) || y == 0 ; y++)
    {
        if (grid[x][y] == '1' || grid[x][y] == '2')
        {
            return count;
        }
        else
        {
            count ++;
        }
    }
    return count;
}

int Grid :: getColMaxSize(int x, int y, char** grid)
{
    if (y == 0)
    {
        return 100;
    }
    int count = 0;
    for (; (x>0 && x%(height) != 0) || x == 0 ; x++)
    {
        if (grid[x][y] == '1' || grid[x][y] == '2')
        {
            return count;
        }
        else
        {
            count ++;
        }
    }
    return count;
}

void Grid::displayGrid(char**grid)
{
    cout << endl;
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}


void Grid::convertCharGrid(char** grid, const list<Word>& content)
{

    for (int i = 0 ; i < height ; i++)
    {
        for(int j = 0 ; j < width ; j++)
        {
            //cout << "Ligne " << j << " / Colonne " << i << ":"<< endl;
            Square *sq;
            char c = grid[i][j];
            if(c == '1' || (c=='4' && (i>=height-2 || j >= width-2)))
            {
                if(j >= width-2)
                {
                    sq = new DefinitionSquare(findColWord(grid, i+1,j,content));
                    //cout << "DefinitionSquare avec un seul mot débutant :" << endl << "1) en ligne "<<i+1 << " et colonne " << j<<"(colonne)" << endl;
                }
                else
                {
                    sq = new DefinitionSquare(findLineWord(grid, i,j+1,content));
                    //cout << "DefinitionSquare avec un seul mot débutant :" << endl << "1) en ligne " <<i << " et colonne " << j+1 << "(ligne)"<< endl;
                }
            }
            else if (c=='2' || (c=='4' && j < width-2 && i < height-2))
            {
                if(i != 0 && j != 0)
                {
                    sq = new DefinitionSquare(findLineWord(grid,i,j+1,content), findColWord(grid, i+1,j,content));
                    //cout << "DefinitionSquare avec deux mots débutants :" <<endl <<
                    //        "1)en ligne "<<i+1 << " et colonne " << j <<"(colonne)"<< endl <<
                    //       "2) en ligne " << i << " et colonne "<<j+1 <<"(ligne)"<< endl;
                }
                else if (j==0 && i == 0)
                {
                    sq = new DefinitionSquare(findColWord(grid, i, j+1, content), findLineWord(grid, i+1, j, content));
                    //cout << "DefinitionSquare avec deux mots débutants :" <<endl <<
                    //        "1)en ligne "<<i+1 << " et colonne " << j<<"(ligne)" << endl <<
                    //        "2) en ligne " << i << " et colonne "<<j+1 <<"(colonne)"<< endl;
                }
                else if (j == 0)
                {
                    //Premi?re colonne
                    if(grid[i][j+1]!='4')
                    {
                        sq = new DefinitionSquare(findLineWord(grid,i,j+1,content), findLineWord(grid,i+1,j,content));
                        //cout << "DefinitionSquare avec deux mots débutants :" <<endl <<
                        //        "1)en ligne "<<i << " et colonne " << j+1<<"(ligne)" << endl <<
                        //        "2) en ligne " << i+1 << " et colonne "<<j <<"(ligne)"<< endl;
                    }
                    else
                    {
                        sq = new DefinitionSquare(findLineWord(grid,i+1,j,content));
                        //cout << "DefinitionSquare avec un seul mot débutant :" <<endl <<
                        //        "1)en ligne "<<i+1 << " et colonne " << j<<"(ligne)" << endl;
                    }
                }
                else if (i == 0)
                {
                    if(grid[i+1][j] != '4')
                    {
                        sq = new DefinitionSquare(findColWord(grid,i,j+1,content), findColWord(grid,i+1,j,content));
                        //cout << "DefinitionSquare avec deux mots débutants :" <<endl <<
                        //        "1)en ligne "<<i+1 << " et colonne " << j<<"(colonne)" << endl <<
                        //        "2) en ligne " << i << " et colonne "<<j+1 <<"(colonne)"<< endl;
                    }
                    else
                    {
                        sq = new DefinitionSquare((findColWord(grid,i,j+1,content)));
                        //cout << "DefinitionSquare avec un seul mot débutant :" <<endl <<
                        //        "1)en ligne "<<i << " et colonne " << j+1<<"(colonne)" << endl;
                    }
                }
            }
            else
            {
                //cout << "StandardSquare" << endl;
                StandardSquare* stdSq = new StandardSquare(grid[i][j], '\0');
                sq = dynamic_cast<StandardSquare*>(stdSq);
            }
            sq->setPos(j,i);
            this->squares.push_back(sq);
        }
    }
    cout << "taille vexteir : " << squares.size() << endl;
    cout << "squares [0] : " << squares[0] << endl;
    for(unsigned int i = 0; i< squares.size(); i++) {
        cout << "Creating square " << i <<  endl;
        bool lower;
        cout << "avant if" << endl;
        if(squares[i]->getWordCount() == 0) {
            cout << "apres if" << endl;
            StandardSquare* s = dynamic_cast<StandardSquare*>(squares[i]);
            cout << "afant getHorizDef" << endl;
            DefinitionSquare* dSq = getHorizDef(s, &lower);

            if(dSq != nullptr)
            {
                if(lower) {
                    dSq->lowerWordSquares.push_back(s);
                }
                else {
                    dSq->upperWordSquares.push_back(s);
                }
            }


            dSq = getVertiDef(s, &lower);
            if(dSq != nullptr) {
                if(lower) {
                    dSq->lowerWordSquares.push_back(s);
                }
                else {
                    dSq->upperWordSquares.push_back(s);
                }
            }
        }
    }
     cout << "Bonjour" << endl;

}

Word Grid::findLineWord(char** grid, int line, int column, const list<Word> content)
{
    //Get the spelling of the word
    int nextDefinitionPos = column;
    while(nextDefinitionPos < width &&  grid[line][nextDefinitionPos]!='1' && grid[line][nextDefinitionPos]!='2' && grid[line][nextDefinitionPos]!='4')
        nextDefinitionPos ++;

    string spell;
    for (; column < nextDefinitionPos ; column ++)
    {
        spell.push_back(grid[line][column]);
    }

    Word w(spell);

    //Look for this word in dictionnary
    list<Word>::const_iterator contentIt = content.begin();
    string definition;
    for(; contentIt != content.end() ; contentIt ++)
    {
        if (contentIt->getSpelling() == spell)
        {
            w.addDefinition(contentIt->getRandomDefinition());
        }
    }
    // cout << w << endl;
    return w;
}

Word Grid::findColWord(char** grid, int line, int column, const list<Word> content)
{
    //Get the spelling of the word
    int nextDefinitionPos = line;
    while(nextDefinitionPos < height-1 && grid[nextDefinitionPos+1][column]!='1' && grid[nextDefinitionPos+1][column]!='2' && grid[nextDefinitionPos+1][column]!='4')
    {
        nextDefinitionPos ++;
    }
    string spell;
    for (; line <= nextDefinitionPos ; line ++)
    {
        spell.push_back(grid[line][column]);
    }

    Word w(spell);

    //Look for this word in dictionnary
    list<Word>::const_iterator contentIt = content.begin();
    string definition;
    for(; contentIt != content.end() ; contentIt ++)
    {
        if (contentIt->getSpelling() == spell)
        {
            w.addDefinition(contentIt->getRandomDefinition());
            break;
        }
    }
    cout << w << endl;
    return w;
}


bool Grid::isDefinitionPossible(int line, int column, char** grid)
{
    // Definition cases are still present on first line/column
    if (line == 0 || column == 0)
    {
        return false;
    }
    else if((line == height -1 && column >= width-2) || (line >= height -2 && column == width-1)||(line==height-2 && column == width-2))
    {
        // Last case of the grid not allowed : it would be a definition case without definitions
        return false;
    }
    else if(line == 1 &&  grid[0][column] != '2')
    {
        // On second line / column a definition case mustn't be placed under/at the right of to a standard case
        // otherwise a word of size 1 would be needed to correctly fill the grid
        return false;
    }
    else if(column == 1  && grid[line][0]!= '2')
    {
        return false;
    }
    else if ((line > 1 && (grid[line-1][column] =='1' || grid[line-1][column] =='2' || grid[line-1][column] =='4'))
             || (column > 1 && (grid[line][column-1]=='1' || grid[line][column-1]=='2' ||grid[line][column-1]=='4')))
    {
        //If the case isn't on the second line / column, she mustn't become a definition one if they are definition case at its left/top
        return false;
    }
    else
        return true;
}
