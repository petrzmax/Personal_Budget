#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int incomeId;
    int userId;
    time_t date;
    string item;
    float amount;

public:
    Income(int incomeId = 0, int userId = 0, time_t date = 0, string item = "", float amount = 0)
    {
        this->incomeId = incomeId;
        this->userId = userId;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }

    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setDate(time_t date);
    void setItem(string item);
    void setAmount(float amount);

    int getIncomeId();
    int getUserId();
    time_t getDate();
    string getItem();
    float getAmount();
};
#endif // INCOME_H
