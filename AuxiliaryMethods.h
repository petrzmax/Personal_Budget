#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <time.h>

using namespace std;

class AuxiliaryMethods
{
    static int getNumberOfDaysInMonth(int monthNumber, int year);
    static bool isCharInDate(string stringDate);

public:
    AuxiliaryMethods();

    static string getLine();
    static char getChar();
    static int getInteger();
    static string floatToString(float floatNumber);
    static float stringToFloat(string floatNumber);
    static string commaToDotInString(string inputString);

    static time_t getCurrentUnixTime();
    static string unixTimeToStringDate(time_t unixTime);
    static time_t stringDateToUnixTime(string stringDate);
    static bool isDateCorrect(string stringDate);
    static bool isYearLeap(int year);

};
#endif // AUXILIARYMETHODS_H
