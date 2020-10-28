#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
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
    static string commaToDotInString();

    static time_t getCurrentUnixDate();
    static string unixTimeToStringDate();
    static time_t stringDateToUnixTime();
    static bool isDateCorrect();
    static bool isYearLeap(int year);

};
#endif // AUXILIARYMETHODS_H
