#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <map>



using namespace std;

class AuxiliaryMethods
{
public:
    static map<int, int> DAYS_IN_MONTHS;

    AuxiliaryMethods();

    static string getLine();
    static char getChar();
    static int getInteger();
    static string floatToString();
    static float stringToFloat();
    static string commaToDotInString();

    static time_t getCurrentUnixDate();
    static string unixTimeToStringDate();
    static time_t stringDateToUnixTime();
    static bool isDateCorrect();
    static bool isYearLeap(int year);

};
#endif // AUXILIARYMETHODS_H
