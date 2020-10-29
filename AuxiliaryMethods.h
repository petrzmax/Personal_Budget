#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <time.h>

using namespace std;

class AuxiliaryMethods
{
public:
    static map<int, int> DAYS_IN_MONTHS;

    AuxiliaryMethods();

    static string getLine();
    static char getChar();
    static int getInteger();
    static string floatToString(float floatNumber);
    static float stringToFloat(string floatNumber);
    static string commaToDotInString(string inputString);

    static time_t getCurrentUnixTime();
    static string unixTimeToStringDate(time_t unixTime);
    static bool isDateCorrect();
    static time_t stringDateToUnixTime(string stringDate);
    static bool isYearLeap(int year);

};
#endif // AUXILIARYMETHODS_H
