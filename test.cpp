#include "TXLib.h"
#include "questionmodule.h"
#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <vector>
//#include "src\\RdoIntegers.cxx"
//#include <curl.h>  // cURL library

int main()
{
    txCreateWindow(600, 400);

    //Открыли файл
    //10 вопросов
    //записали куда-нибудь
    //файл закрыт
    int i = 0;
    questionLib::readFile();
    while (i < 3) {
        questionModule::runQuestionModule(questionLib::getNumber(i),questionLib::getQuestion(i).c_str());
        cout << i;
        i++;
    }

    return 0;
}
