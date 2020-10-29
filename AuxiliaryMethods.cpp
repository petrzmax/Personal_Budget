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

bool AuxiliaryMethods::isCharInDate(string stringDate)
{
    for(int i = 0; i < stringDate.length(); i++)
        if((stringDate[i] >= '0' && stringDate[i] <= '9') || stringDate[i] == '-')
            continue;
        else
            return true;

    return false;
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

int AuxiliaryMethods::stringToInt(string intNumber)
{
    return atoi(intNumber.c_str());
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

bool AuxiliaryMethods::isDateCorrect(string stringDate)
{
    int inputYear = 0, inputMonth = 0, inputDay = 0;
    int currentYear = 0, currentMonth = 0;


    string input;
    time_t currentTime = getCurrentUnixTime();

    struct tm *localTime = localtime(&currentTime);

    currentYear = 1900 + localTime->tm_year;
    currentMonth = 1 + localTime->tm_mon;

    istringstream stringStream(stringDate);

    getline(stringStream, input, '-');
    inputYear = atoi(input.c_str());

    getline(stringStream, input, '-');
    inputMonth = atoi(input.c_str());

    getline(stringStream, input);
    inputDay = atoi(input.c_str());

    if(isCharInDate(stringDate))
        return false;

    if(inputYear < 2000 || inputYear > currentYear)
        return false;

    if(inputMonth < 1 || inputMonth > 12)
        return false;

    if(inputYear == currentYear && inputMonth > currentMonth)
        return false;

    if(inputDay < 1 || inputDay > 31)
        return false;

    if(inputDay > getNumberOfDaysInMonth(inputMonth, inputYear))
        return false;

    return true;
}

bool AuxiliaryMethods::isYearLeap(int year)
{
    if((year%4 == 0 && year%100 != 0) || year%400 == 0)
        return true;
    else
        return false;
}
