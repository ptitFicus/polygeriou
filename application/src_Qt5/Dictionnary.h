#ifndef DICTIONNARY_H
#define DICTIONNARY_H
#include "Word.h"
#include <fstream>
#include <cstring>
#include <list>

class Dictionnary
{
	public:
		Dictionnary();
		Dictionnary(const Dictionnary& other);
		~Dictionnary();
		Dictionnary& operator=(const Dictionnary& other);
		/**
		 * @brief Constructor which fill this dictionnary with a given source file
		 *
		 * @param filePath path of the source file for this dictionnary
		 */
		Dictionnary(string aName,string aFilePath);

		/**
		 * @brief Add a word and its definitions to the current Dictionnary
		 *
		 * @param w the word to add
		 *
		 * @return true if the operation was successfull, false otherwise
		 */
		bool addWord(const Word& w);

		/**
		 * @brief Delete a word from the current Dictionnary
		 *
		 * @param w the word to delete
		 *
		 * @return true if the operation was successfull, false if unable to open the file
		 */
		bool deleteWord(const Word& w);

		/**
		 * @brief Modify a word in the current Dictionnary
		 *
		 * @param old the word to modify
		 * @param w the new version of the word
		 *
		 * @return true if the operation was successfull, false if unable to open the file
		 */
		bool modifyWord(const Word& old, const Word& w);

		bool addWord(const vector<Word>& w);
		bool deleteWord(vector<Word> w);
		bool modifyWord(vector<Word> old, const vector<Word>& w);

		inline const list<Word>& getWords() const {return words;};
		string getName() const;
	private:
		list<Word> words;
		string filePath;
		bool doesContain(string line, Word w);
		string name;
};

#endif
