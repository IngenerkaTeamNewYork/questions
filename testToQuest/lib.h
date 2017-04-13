#include "base64.h"
using namespace std;

namespace questionLib
{
int number[100];
string question[100];
int i,c = 0;
string line;

string vigenere_decrypt(string str, string key)
{
    string s = str;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    unsigned int j = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]))
        {
            s[i] = s[i] >= key[j] ?
                   s[i] - key[j] + 'A' :
                   'A' + ('Z' - key[j] + s[i] - 'A') + 1;
        }
        j = j + 1 == key.length() ? 0 : j + 1;
    }
    return s;
}

void readFile()
{
    ifstream questions(".//questions.txt");
    while (getline(questions, line))
    {
        if (line.substr(0, 1) == "#")
        {
            string szText = vigenere_decrypt(base64_decode(line.substr(1, 100)),"upper");
            question[i] = szText;
            i++;
        }
        else
        {
            number[c] = atoi(base64_decode(line.c_str()).c_str());
            c++;

        }
    }
    questions.close();
}

int getNumber(int a)
{
    return number[a];
}

string getQuestion(int a)
{
    return question[a];
}
}
