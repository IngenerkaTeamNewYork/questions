#include "TXLib.h"
#include "questionmodule.h"
#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <vector>
int main()
{
    txCreateWindow(600,400);
    int i = 0;
    questionLib::readFile();
    while (i < 100)
    {
        questionModule::runQuestionModule(questionLib::getNumber(i),questionLib::getQuestion(i).c_str());
        i++;
    }

    return 0;
}
