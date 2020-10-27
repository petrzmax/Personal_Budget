#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "Finance.h"

using namespace std;

class Expense : public Finance
{
    int expenseId;

public:
    Expense(int expenseId = 0, int userId = 0, time_t date = 0, string item = "", float amount = 0) :
        Finance(userId, date, item, amount)
    {
        this->expenseId = expenseId;
    }

    void setExpenseId(int expenseId);

    int getExpenseId();
};
#endif // EXPENSE_H
