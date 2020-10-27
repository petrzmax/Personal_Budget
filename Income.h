#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "Finance.h"

using namespace std;

class Income : public Finance
{
    int incomeId;

public:
    Income(int incomeId = 0, int userId = 0, time_t date = 0, string item = "", float amount = 0) :
        Finance(userId, date, item, amount)
    {
        this->incomeId = incomeId;
    }

    void setIncomeId(int incomeId);

    int getIncomeId();
};
#endif // INCOME_H
