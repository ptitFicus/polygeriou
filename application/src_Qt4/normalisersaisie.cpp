#include "normalisersaisie.h"

NormaliserSaisie::NormaliserSaisie()
{

}

void NormaliserSaisie::normalize_specials (string& aString)
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


void NormaliserSaisie::replaceAll(string& str, const string& from, const string& to)
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

void NormaliserSaisie::normalize (string& aString)
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

bool NormaliserSaisie::checkAscii(const string& s)
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

bool NormaliserSaisie::normalizeString (string& s)
{
    normalize(s);
    normalize_specials(s);

    if(!checkAscii(s))
        return false;

    unsigned int index_tab = s.find_first_of('\t');
    unsigned int index_espace = s.find_first_of(' ');
    unsigned int index_eau = s.find_first_of("œ");
    unsigned int index_tiret = s.find_first_of("-");
    unsigned int size = s.size();
    if (index_espace < s.size() -1 || index_eau < s.size() -1 || index_tiret < s.size()-1 ||index_tab < s.size()-1|| size ==1)
    {

        return false;
    }
    return true;
}
