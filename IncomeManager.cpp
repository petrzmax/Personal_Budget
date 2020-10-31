#include "IncomeManager.h"

Income IncomeManager::getNewIncomeData()
{
    Income newIncome;
    char selection;

    newIncome.setIncomeId(getNewIncomeId());
    newIncome.setUserId(LOGGED_USER_ID);

    cout << "Czy przychod dotyczy dnia dzisiejszego? t - Tak, n - nie" << endl;

    while(true)
    {
        selection = getch();

        if(selection == 't')
        {
            newIncome.setDate(AuxiliaryMethods::getCurrentUnixTime());
            break;
        }
        else if(selection == 'n')
        {
            newIncome.setDate(getCorrectDate());
            break;
        }
        else
            cout << "Blad! Wybierz odpowiedni znak." << endl;
    }

    cout << "Podaj czego dotyczy przychod: ";
    newIncome.setItem(AuxiliaryMethods::getLine());

    cout << "Okresl wysokosc przychodu: ";
    newIncome.setAmount(AuxiliaryMethods::getFloat());

    return newIncome;
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
