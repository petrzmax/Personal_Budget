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

public:
    ExpenseFile(string fileName) : XmlFile(fileName) {};

    vector<Expense> loadExpensesFromFile();
    void appendExpenseToFile(Expense expense);

};
#endif // EXPENSEFILE_H
