#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include "Income.h"
#include "IncomeFile.h"

using namespace std;

class IncomeManager
{
    const int LOGGED_USER_ID;
    vector <Income> incomes;

    Income getNewIncomeData();
    int getNewIncomeId();

public:
    IncomeManager();
    void  addIncome();

};

#endif // INCOMEMANAGER_H
