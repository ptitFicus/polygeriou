#include "Dictionnary.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

Dictionnary :: Dictionnary():words(), filePath(), name()
{
}

Dictionnary :: Dictionnary (const Dictionnary& other):
	words(other.words), filePath(other.filePath), name(other.name)
{
}

Dictionnary :: ~Dictionnary(){}

Dictionnary& Dictionnary :: operator=(const Dictionnary& other)
{
	filePath = other.filePath;
	words = other.words;
	name = other.name;
	return *this;
}

Dictionnary :: Dictionnary(string aName, string aFilePath):filePath(aFilePath), name(aName)
{
	// To read the dictionnary's file
	ifstream infile (filePath.c_str());


	// To contain lines of the file
	string line;

	// To contain parts of the line
	string content;

	// To store founded data
	Word w;

	// To know the index in the global vector
	
	while (infile.good())
	{
		//Get the whole line
		getline(infile, line);
	
        if(line!=""){
            //Using an istringstream to read line until
            //the next delimiter
            istringstream iss(line);
            getline(iss, content, Word::separatorWordDef);

            //Initialise a Word with the found definition
            Word w(content);

            //Getting definitions
            while (iss.good())
            {
                getline(iss, line, Word::separatorDef);
                w.addDefinition(line);
            }
            //Adding the new word to local list
            words.push_back(w);
        }
	}
	words.sort();
	
	infile.close();
}


bool Dictionnary :: addWord(const Word& w)
{
	// Stream to read / write in the file
	ofstream file;
	try
	{
		 file.open(filePath.c_str(), ios_base::out|ios_base::app);
	}
	catch(...)
	{
		return false;
	}
	file << endl << w ;
	
	file.close();

    bool insert = false;

    if(words.empty()){
        words.push_back(w);
        insert = true;
    }else{
        for (list<Word>::iterator it = words.begin() ; it != words.end() ; it ++)
        {
            if (!(*it < w))
            {
                words.insert(it, w);
                insert = true;
                break;
            }
        }
    }

    if(!insert)
       words.push_back(w);

	file.close();
	return true;
}


bool Dictionnary :: addWord(const vector<Word>& w)
{
	// Stream to read / write in the file
	ofstream file;
	try
	{
		 file.open(filePath.c_str(), ios_base::out|ios_base::app);
	}
	catch(...)
	{
		return false;
	}

	file << endl;
	vector<Word>::const_iterator it = w.begin(); 
	for (; it != w.end()-1 ; it ++)
	{
		words.push_back(*it);
		file << *it << endl;
	}
	file << *it;
	
	file.close();

	
	return true;
}

bool Dictionnary :: doesContain(string line, Word w)
{
	if (line.find(w.getSpelling()) != string::npos)
	{
		bool rightLine = true;
		vector<string> definitions = w.getDefinitions();
		vector<string>::iterator it = definitions.begin();

		// Check that all definitions are here
		while (it != definitions.end() && rightLine)
		{
			if (line.find(*it) == string::npos)
				rightLine = false;
			it ++;
		}
		return rightLine;
	}
	else
		return false;
}

bool Dictionnary :: deleteWord(vector<Word> w)
{
	fstream file;
	try
	{
		file.open(filePath.c_str());
	}
	catch(...)
	{
		return false;
	}

	string line;
	vector<string> lines;

	while (file.good())
	{
		getline(file, line);

		bool found = false;

		unsigned int i = 0;
		while(i < w.size() && (!found))
		{	
			if (doesContain(line, w.at(i)))
			{
				// We found position of the right word,
				// we delete it from the list and don't store it
				for (list<Word>::iterator it = words.begin() ; it != words.end(); it++)
				{
					if (*it == w.at(i))
					{
						words.erase(it);
						break;
					}
				}
				// Erase the word from the given list to avoid useless iterations
				w.erase(w.begin() + i);
				found = true;
			}
			if (!found)
				i++;
		}

		if (!found)
			lines.push_back(line);
	}
	file.close();

	try
	{
		file.open(filePath.c_str(), ios_base::in | ios_base::out | ios_base::trunc);
	}
	catch(...)
	{
		return false;
	}

	for (unsigned int i = 0 ; i < lines.size() -1 ; i++)
	{
		file << lines.at(i) << endl;
	}
	file << lines.at(lines.size()-1);
	file.close();

	return true;
}



bool Dictionnary :: deleteWord(const Word& w)
{
	
	fstream file;
	try
	{
		file.open(filePath.c_str());
	}
	catch(...)
	{
		return false;
	}

	string line;
	vector<string> lines;

	while (file.good())
	{
		getline(file, line);

		bool found = false;

		if (!found && doesContain(line, w))
		{
			// We found position of the right word,
			// we delete it from the list and don't store it
			for (list<Word>::iterator it = words.begin() ; it != words.end(); it++)
			{
				if (*it == w)
				{
					words.erase(it);
					break;
				}
			}
			found = true;
		}
		else
		{
			lines.push_back(line);
		}

	}
	file.close();

	try
	{
		file.open(filePath.c_str(), ios_base::in | ios_base::out | ios_base::trunc);
	}
	catch(...)
	{
		return false;
	}

	for (unsigned int i = 0 ; i < lines.size() -1 ; i++)
	{
		file << lines.at(i) << endl;
	}
	file << lines.at(lines.size()-1);
	file.close();

	return true;
}


bool Dictionnary :: modifyWord (const Word& old, const Word& w)
{
	if (deleteWord(old))
		return addWord(w);
	else
		return false;
}


bool Dictionnary :: modifyWord(vector<Word> old, const vector<Word>& w)
{
	if (deleteWord(old))
		return addWord(w);
	else
		return false;
}

string Dictionnary:: getName() const
{
	return name;
}
