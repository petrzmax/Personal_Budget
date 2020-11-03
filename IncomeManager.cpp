#include "IncomeManager.h"

Income IncomeManager::getNewIncomeData()
{
    Income newIncome;
    char selection;

    newIncome.setIncomeId(getNewIncomeId());
    newIncome.setUserId(LOGGED_USER_ID);

    system("cls");

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
            cout << "Podaj date przychodu w formacie rrrr-mm-dd: ";
            newIncome.setDate(AuxiliaryMethods::getCorrectDate());
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

void IncomeManager::displayIncomeHeader()
{
    cout << "-----------------------Lista przychodow-----------------------" << endl;
    cout << left << setw(4) << "id"
         << left << setw(35)<< "Przedmiot"
         << left << setw(15)<< "Data"
         << left << setw(30)<< "Przychod" << endl;
}

void IncomeManager::displayIncomesVector(vector<Income> &incomes)
{
    for(int i = 0; i < incomes.size(); i++)
        cout << left << setw(4) << incomes[i].getIncomeId()
             << left << setw(35)<< incomes[i].getItem()
             << left << setw(15)<< AuxiliaryMethods::unixTimeToStringDate(incomes[i].getDate())
             << left << setw(30)<< setprecision(2) << incomes[i].getAmount() << endl;
}

float IncomeManager::getTotalIncomesValueInVector(vector<Income> &incomes)
{
    float totalIncome = 0;

    for(int i = 0; i < incomes.size(); i++)
        totalIncome += incomes[i].getAmount();

    return totalIncome;
}

void  IncomeManager::addIncome()
{
    Income newIncome = getNewIncomeData();
    incomes.push_back(newIncome);

    incomeFile.appendIncomeToFile(newIncome);
    AuxiliaryMethods::timedMessage("Przychod dodany pomyslnie!");
}

float IncomeManager::displayCurrentMonthIncomes()
{
    time_t currentTime = AuxiliaryMethods::getCurrentUnixTime();
    time_t currentMonthfirstDayUnixTime = AuxiliaryMethods::getLastMonthLastDayUnixTime();

    vector<Income> currentMonthIncomes;

    for(int i = 0; i < incomes.size(); i++)
    {
        if(incomes[i].getDate() >= currentMonthfirstDayUnixTime &&
                incomes[i].getDate() <= currentTime)
        {
            currentMonthIncomes.push_back(incomes[i]);
        }
    }

    sort(currentMonthIncomes.begin(), currentMonthIncomes.end(), greater <>());

    displayIncomeHeader();
    displayIncomesVector(currentMonthIncomes);

    return getTotalIncomesValueInVector(currentMonthIncomes);
}

float IncomeManager::displayLastMonthIncomes()
{
    time_t lastMonthFirstDayUnixTime = AuxiliaryMethods::getLastMonthFirstDayUnixTime();
    time_t lastMonthLastDayUnixTime = AuxiliaryMethods::getLastMonthLastDayUnixTime();

    vector<Income> lastMonthIncomes;

    for(int i = 0; i < incomes.size(); i++)
    {
        if(incomes[i].getDate() >= lastMonthFirstDayUnixTime &&
                incomes[i].getDate() <= lastMonthLastDayUnixTime)
        {
            lastMonthIncomes.push_back(incomes[i]);
        }
    }

    sort(lastMonthIncomes.begin(), lastMonthIncomes.end(), greater <>());

    displayIncomeHeader();
    displayIncomesVector(lastMonthIncomes);

    return getTotalIncomesValueInVector(lastMonthIncomes);
}

float IncomeManager::displayChosenPeriodIncomes(time_t beginPeriodUnixTime, time_t endPeriodUnixTime)
{
    vector<Income> lastMonthIncomes;

    for(int i = 0; i < incomes.size(); i++)
    {
        if(incomes[i].getDate() >= beginPeriodUnixTime &&
                incomes[i].getDate() <= endPeriodUnixTime)
        {
            lastMonthIncomes.push_back(incomes[i]);
        }
    }

    sort(lastMonthIncomes.begin(), lastMonthIncomes.end(), greater <>());

    displayIncomeHeader();
    displayIncomesVector(lastMonthIncomes);

    return getTotalIncomesValueInVector(lastMonthIncomes);
}
