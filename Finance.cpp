#include "Finance.h"

void Finance::setUserId(int userId)
{
    if(userId >= 0)
        this->userId = userId;
}

void Finance::setDate(time_t date)
{
    if(date > 0)
        this->date = date;
}

void Finance::setItem(string item)
{
    this->item = item;
}

void Finance::setAmount(float amount)
{
    if(amount > 0)
        this->amount = amount;
}

int Finance::getUserId()
{
    return userId;
}

time_t Finance::getDate()
{
    return date;
}

string Finance::getItem()
{
    return item;
}

float Finance::getAmount()
{
    return amount;
}
