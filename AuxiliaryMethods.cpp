#include "AuxiliaryMethods.h"

string AuxiliaryMethods::getLine()
{
    string temporaryLine = "";
    getline(cin, temporaryLine);
    return temporaryLine;
}

char AuxiliaryMethods::getChar()
{
    string input = "";
    char temporaryChar  = NULL;

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            temporaryChar = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return temporaryChar;
}

int AuxiliaryMethods::getInteger()
{

}

string AuxiliaryMethods::floatToString()
{

}

float AuxiliaryMethods::stringToFloat()
{

}

string AuxiliaryMethods::commaToDotInString()
{

}

time_t AuxiliaryMethods::getCurrentUnixDate()
{

}

string AuxiliaryMethods::unixTimeToStringDate()
{

}

time_t AuxiliaryMethods::stringDateToUnixTime()
{

}

bool AuxiliaryMethods::isDateCorrect()
{

}

bool AuxiliaryMethods::isYearLeap(int year)
{
    if((year%4 == 0 && year%100 != 0) || year%400 == 0)
        return true;
    else
        return false;
}
