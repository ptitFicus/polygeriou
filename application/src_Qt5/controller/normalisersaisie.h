#ifndef NORMALISERSAISIE_H
#define NORMALISERSAISIE_H

#include <string>
#include <algorithm>

using namespace std;

struct my_tolower
{
    char operator()(char c) const
    {
        return tolower(static_cast<unsigned char>(c));
    }
};

class NormaliserSaisie
{
public:
    NormaliserSaisie();
    static void normalize_specials (string& aString);
    static void replaceAll(string& str, const string& from, const string& to);
    static void normalize (string& aString);
    static bool checkAscii(const string& s);
    static bool normalizeString (string& s);
};

#endif // NORMALISERSAISIE_H
