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
    Income newIncome = getNewIncomeData();
    incomes.push_back(newIncome);

    incomeFile.appendIncomeToFile(newIncome);
    AuxiliaryMethods::timedMessage("Przychod dodany pomyslnie!");
}
