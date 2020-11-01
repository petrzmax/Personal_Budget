#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <conio.h>
#include "AuxiliaryMethods.h"
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
    time_t getCorrectDate();

public:
    IncomeManager(string fileName, int loggedUserId)
        : LOGGED_USER_ID(loggedUserId),
          incomeFile(fileName)
    {
        incomes = incomeFile.loadIncomesFromFile();
    }

    void  addIncome();

};

#endif // INCOMEMANAGER_H