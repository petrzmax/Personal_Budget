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
    cout << left << setw(4) << "id"
         << left << setw(35)<< "Przedmiot"
         << left << setw(15)<< "Data"
         << left << setw(30)<< "Przychod" << endl;
}

void  IncomeManager::addIncome()
{
    Income newIncome = getNewIncomeData();
    incomes.push_back(newIncome);

    incomeFile.appendIncomeToFile(newIncome);
    AuxiliaryMethods::timedMessage("Przychod dodany pomyslnie!");
}

/*
1. Znajdz Date w Unix, z polnocy ostatniego dnia poprzedniego miesiaca.
2. Znajdz Date w Unix, z polnocy pierwszego dnia ostatniego miesiaca.
3. Przejdz po wektorze przychodow, i do nowego wektora przepisz te,
    ktorych czas unixowy zawiera sie pomiedzy czasami z pkt. 1 i 2.
4. Posegreguj powstaly wektor wedlug daty ich dodania, na gorze najstarsze.
5. Przejdz po powstalym wektorze, i wypisz dane na ekran.
6. Policz sume przychodow i zwroc ja.
*/

float IncomeManager::displayLastMonthIncomes()
{

}
