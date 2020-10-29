#include "AuxiliaryMethods.h"

int AuxiliaryMethods::getNumberOfDaysInMonth(int monthNumber, int year)
{
    int februaryDaysNumber = 28;

    if(isYearLeap(year))
        februaryDaysNumber = 29;

    const vector<int> DAYS_IN_MONTHS = {31, februaryDaysNumber, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    if(monthNumber < 1 || monthNumber > 12)
        return 0;
    else
        return DAYS_IN_MONTHS[monthNumber-1];
}

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
    string input = "";
    int number = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

string AuxiliaryMethods::floatToString(float floatNumber)
{
    return to_string(floatNumber);
}

float AuxiliaryMethods::stringToFloat(string floatNumber)
{
    return atof(floatNumber.c_str());
}

string AuxiliaryMethods::commaToDotInString(string inputString)
{
    for(int i = 0; i < inputString.length(); i++)
        if(inputString[i] == ',')
            inputString[i] = '.';

    return inputString;
}

time_t AuxiliaryMethods::getCurrentUnixTime()
{
    return time(0);
}

string AuxiliaryMethods::unixTimeToStringDate(time_t unixTime)
{
    string date = "";

    struct tm *localTime = localtime(&unixTime);

    date += to_string(1900 + localTime->tm_year);
    date += "-" + to_string(1 + localTime->tm_mon);
    date += "-" + to_string(localTime->tm_mday);

    return date;
}

time_t AuxiliaryMethods::stringDateToUnixTime(string stringDate)
{
    struct tm timeStruct = {};

    istringstream stringStream(stringDate);

    stringStream >> get_time(&timeStruct, "%Y-%m-%d");

    return mktime(&timeStruct);
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
