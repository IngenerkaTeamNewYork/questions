#include "base64.h"
using namespace std;

namespace questionLib
{
    int number[100];
    string question[100];
    int i,c = 0;
    string line;

    void decryptionFunc(std::string &nString)
    {
        const int KEY = 23;
        int strLen = (nString.length());
        char *cString = (char*)(nString.c_str());

        for (int i = 0; i < strLen; i++)
        {
         *(cString+i) = (*(cString+i) ^ KEY);
        }
    }

    void readFile()
    {
        ifstream questions(".//questions.txt");
        while (getline(questions, line))
        {
            if (line.substr(0, 1) == "#")
            {
                string tmp = base64_decode(line.substr(1, 100));
                decryptionFunc(tmp);
                question[i] = tmp;
                i++;
            }
            else
            {
                number[c] = atoi(base64_decode(line).c_str());
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
