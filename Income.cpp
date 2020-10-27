#include "Income.h"

void Income::setIncomeId(int incomeId)
{
    if(incomeId >= 0)
        this->incomeId = incomeId;
}

void Income::setUserId(int userId)
{
    if(userId >= 0)
        this->userId = userId;
}

void Income::setDate(time_t date)
{
    if(date > 0)
        this->date = date;
}

void Income::setItem(string item)
{
    this->item = item;
}

void Income::setAmount(float amount)
{
    if(amount > 0)
        this->amount = amount;
}

int Income::getIncomeId()
{
    return incomeId;
}

int Income::getUserId()
{
    return userId;
}

time_t Income::getDate()
{
    return date;
}

string Income::getItem()
{
    return item;
}

float Income::getAmount()
{
    return amount;
}
