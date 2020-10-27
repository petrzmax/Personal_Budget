#include "Expense.h"

void Expense::setExpenseId(int expenseId)
{
    if(expenseId >= 0)
        this->expenseId = expenseId;
}

int Expense::getExpenseId()
{
    return expenseId;
}
