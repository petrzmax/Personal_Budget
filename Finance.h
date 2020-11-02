#ifndef FINANCE_H
#define FINANCE_H

#include <iostream>

using namespace std;

class Finance
{
    int userId;
    time_t date;
    string item;
    float amount;

public:
    Finance(int userId = 0, time_t date = 0, string item = "", float amount = 0)
    {
        this->userId = userId;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }

    bool operator > (const  Finance & other)
    {
        return amount > other.amount;
    }

    void setUserId(int userId);
    void setDate(time_t date);
    void setItem(string item);
    void setAmount(float amount);

    int getUserId();
    time_t getDate();
    string getItem();
    float getAmount();
};
#endif // FINANCE_H
