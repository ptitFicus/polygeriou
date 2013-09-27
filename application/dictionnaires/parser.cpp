#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void replaceAll(string& str, const string& from, const string& to);
void normalize (string& aString);
void normalize_specials (string& aString);

bool checkAscii(const string& s)
{
	for (unsigned int i = 0 ; i < s.size() ; i++)
	{
		int asc = (int)s.at(i);
		if(asc < 97 ||  asc > 122)
		{
			return false;
		}
	}
	return true;
}

int main ()
{
	int i = 1;
	vector<string> mots;
	vector<vector<string> > definition;
	string line;
	ifstream myfile("./res/thes_en.dat");

	if (myfile.is_open())
	{
		// On passe la ligne de l'encodage
		getline(myfile, line);
		int nbDef = 0;
		vector<string> local_definition;
		while(myfile.good())
		{
			getline(myfile, line);

			if (nbDef == 0)
			{
				// C'est une ligne contenant un nouveau mot
				int index_pipe = line.find_first_of('|');
				//Récuperation du nombre de définitions
				char nb[2];
				nb[0] = line[index_pipe+1];
				nb[1] = '\0';
				nbDef = atoi(nb);

				// Vérification de la validité de la ligne
				unsigned int index_espace = line.find_first_of(' ');
				unsigned int index_eau = line.find_first_of("œ");
                unsigned int index_tiret = line.find_first_of("-");
                unsigned int size = line.size();
                
                string mot = line.substr(0, index_pipe);

				if (index_espace < line.size() -1 || index_eau < line.size() -1 || index_tiret < line.size()-1 || size ==1 || !checkAscii(mot))
				{
					//C'est une expression, on en a pas besoin
					nbDef = -nbDef;
				}
				else	
				{
					// On garde juste le mot
					line = line.substr(0, index_pipe);

					// On transforme le mot de façon à neutraliser les caractères spéciaux
					normalize(line);
					line.erase (remove(line.begin(), line.end(), ' '), line.end());
					line.erase (remove(line.begin(), line.end(), '.'), line.end());

					mots.push_back(line);

					// On prépare la liste de définitions à recevoir les nouvelles pour ce mot
					local_definition.clear();
				}
			}
			else if (nbDef > 0)
			{
				//Définition
				int index_pipe = line.find_first_of('|');
				line = line.substr(index_pipe+1);
				bool cont = true;
				while (cont)
				{
					index_pipe = line.find_first_of('|');
					if (index_pipe != -1)
					{
						local_definition.push_back(line.substr(0, index_pipe));
						line = line.substr(index_pipe+1);
					}
					else
					{
						local_definition.push_back(line);
						cont = false;
					}
				}
				if (nbDef == 1)
				{
					definition.push_back(local_definition);
				}
				nbDef --;
			}
			else
			{
				// On est dans les définition d'un expression : on passe
				nbDef ++;
			}
			i++;
		}
		myfile.close();

		ofstream file;
		file.open("./res/dictionnaire_en_parse.txt");

		unsigned int i;
		for (i = 0 ; i < mots.size() ; i ++)
		{
			file << mots[i] << ":";
			unsigned int j;
			for (j = 0 ; j < definition[i].size() ; j++)
			{
				if (j != 0)
					file << ";";
				file << definition[i][j];
			}
			if (i != mots.size()-1)
				file << endl;
		}
		file.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	return 0;
}

struct my_tolower
{ 
	char operator()(char c) const 
	{
		return tolower(static_cast<unsigned char>(c));
	} 
};

void normalize (string& aString)
{
	// To get string in lower cases
	transform(aString.begin(), aString.end(), aString.begin(), my_tolower());

	// To replace special caracters
	int sizes[] = {4, 6, 4, 2, 3};
	string aLetters[] = {"a","à", "ä", "â", "ã"};
	string eLetters[] = { "e", "é", "è", "ê", "ë", "ẽ", "É"};
	string uLetters[] = {"u", "ù", "û", "ü", "ũ"};
	string iLetters[] = {"i", "ï", "î"};
	string oLetters[] = {"o", "ô", "ö", "õ"};
	string *letters[] = {aLetters, eLetters, uLetters, iLetters, oLetters};

	int i;
	int j;
	for (i = 0 ; i < 5 ; i++)
	{
		for (j = 1 ; j < sizes[i]; j++)
		{
			replaceAll(aString, letters[i][j], letters[i][0]);
		}
	}


	// For cedilla and few other caracters
	normalize_specials(aString);
}

void replaceAll(string& str, const string& from, const string& to) 
{
	if(from.empty())
		return;
	size_t start_pos = 0;
	while((start_pos = str.find(from, start_pos)) != string::npos) 
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
}


void normalize_specials (string& aString)
{
	size_t i = 0;
	for (i = 0 ; i < aString.size()-1 ; i++)
	{
		if (aString[i] == -61)
		{
			if(aString[i+1]== -89)
			{
				//ç
				string aString2 = aString.substr(i+2); 
				aString = aString.substr(0, i);
				aString = aString+ "c" + aString2;
			}
			else if (aString[i+1] == -119)
			{
				//É
				string aString2 = aString.substr(i+2); 
				aString = aString.substr(0, i);
				aString = aString+ "e" + aString2;
			}
			else if (aString[i+1] == -82)
			{
				//î
				string aString2 = aString.substr(i+2); 
				aString = aString.substr(0, i);
				aString = aString+ "i" + aString2;
			}
		}
	}
}
