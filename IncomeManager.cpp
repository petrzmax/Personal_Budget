#include "IncomeManager.h"

Income IncomeManager::getNewIncomeData()
{

}

int IncomeManager::getNewIncomeId()
{
    if(incomes.empty())
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}

void  IncomeManager::addIncome()
{

}
