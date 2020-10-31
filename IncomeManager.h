#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include "Income.h"
#include "IncomeFile.h"

using namespace std;

class IncomeManager
{
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    IncomeFile incomeFile;

    Income getNewIncomeData();
    int getNewIncomeId();

public:
    IncomeManager(string fileName, int loggedUserId)
        : LOGGED_USER_ID(loggedUserId),
          incomeFile(fileName) {};

    void  addIncome();

};

#endif // INCOMEMANAGER_H
