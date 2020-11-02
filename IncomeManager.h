#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <conio.h>
#include <algorithm>
#include "AuxiliaryMethods.h"
#include "Income.h"
#include "IncomeFile.h"

using namespace std;

class IncomeManager
{
    const int LOGGED_USER_ID;
    vector<Income> incomes;
    IncomeFile incomeFile;

    Income getNewIncomeData();
    int getNewIncomeId();
    void displayIncomeHeader();
    void displayIncomesVector(vector<Income> &incomes);
    float getTotalIncomesValueInVector(vector<Income> &incomes);

public:
    IncomeManager(string fileName, int loggedUserId)
        : LOGGED_USER_ID(loggedUserId),
          incomeFile(fileName)
    {
        incomes = incomeFile.loadIncomesFromFile();
    }

    void  addIncome();
    float displayCurrentMonthIncomes();
    float displayLastMonthIncomes();
    float displayChosenPeriodIncomes(time_t beginPeriodUnixTime, time_t endPeriodUnixTime);

};

#endif // INCOMEMANAGER_H
