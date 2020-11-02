#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <conio.h>
#include <algorithm>
#include "AuxiliaryMethods.h"
#include "Expense.h"
#include "ExpenseFile.h"

using namespace std;

class ExpenseManager
{
    const int LOGGED_USER_ID;
    vector<Expense> expenses;
    ExpenseFile expenseFile;

    Expense getNewExpenseData();
    int getNewExpenseId();
    void displayExpenseHeader();
    void displayExpensesVector(vector<Expense> &expenses);
    float getTotalExpensesValueInVector(vector<Expense> &expenses);

public:
    ExpenseManager(string fileName, int loggedUserId)
        : LOGGED_USER_ID(loggedUserId),
          expenseFile(fileName)
    {
        expenses = expenseFile.loadExpensesFromFile(LOGGED_USER_ID);
    }

    void  addExpense();
    float displayCurrentMonthExpenses();
    float displayLastMonthExpenses();
    float displayChosenPeriodExpenses(time_t beginPeriodUnixTime, time_t endPeriodUnixTime);

};

#endif // EXPENSEMANAGER_H
