#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <time.h>
#include <windows.h>

// const values for static methods
#define UNIX_YEAR_OFFSET 1900

#define MINIMUM_ALLOWED_YEAR 2000

#define MINIMUM_ALLOWED_MONTH 1
#define MAXIMUM_ALLOWED_MONTH 12

#define MINIMUM_ALLOWED_DAY 1
#define MAXIMUM_ALLOWED_DAY 31

#define FEBRUARY_DAYS_NUMBER 28

// settings
#define MESSAGE_TIME 2000

using namespace std;

class AuxiliaryMethods
{
    static int getNumberOfDaysInMonth(int monthNumber, int year);
    static bool isCharInDate(string stringDate);
    static bool isYearLeap(int year);
    static bool isDateCorrect(string stringDate);

public:
    static string getLine();
    static char getChar();
    static int getInteger();
    static float getFloat();

    static string floatToString(float floatNumber);
    static float stringToFloat(string floatNumber);
    static int stringToInt(string intNumber);
    static string commaToDotInString(string inputString);
    static void timedMessage(string message);

    static time_t getCurrentUnixTime();
    static string unixTimeToStringDate(time_t unixTime);
    static time_t stringDateToUnixTime(string stringDate);
    static time_t getCorrectDate();
};
#endif // AUXILIARYMETHODS_H
