#include "Income.h"

void Income::setIncomeId(int incomeId)
{
    if(incomeId >= 0)
        this->incomeId = incomeId;
}

int Income::getIncomeId()
{
    return incomeId;
}
