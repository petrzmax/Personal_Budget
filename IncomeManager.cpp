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

time_t IncomeManager::getCorrectDate()
{
    string newDate;

    cout << "Podaj date przychodu w formacie rrrr-mm-dd: ";
    while(true)
    {
        newDate = AuxiliaryMethods::getLine();

        if(AuxiliaryMethods::isDateCorrect(newDate))
            return AuxiliaryMethods::stringDateToUnixTime(newDate);
        else
            cout << "Bledna data! Podaj poprawna date: ";
    }
}

void  IncomeManager::addIncome()
{
    Income newIncome = getNewIncomeData();
    incomes.push_back(newIncome);

    incomeFile.appendIncomeToFile(newIncome);
    AuxiliaryMethods::timedMessage("Przychod dodany pomyslnie!");
}
