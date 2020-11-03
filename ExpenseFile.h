#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include <iostream>
#include <vector>
#include "XmlFile.h"
#include "Expense.h"

using namespace std;

class ExpenseFile : public XmlFile
{
    Expense getExpenseData();
    int lastExpenseId;

public:
    ExpenseFile(string fileName) : XmlFile(fileName) {};

    vector<Expense> loadExpensesFromFile(int loggedUserId);
    void appendExpenseToFile(Expense expense);

    int getLastExpenseId();

};
#endif // EXPENSEFILE_H
