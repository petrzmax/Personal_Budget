#include "ExpenseManager.h"

Expense ExpenseManager::getNewExpenseData()
{
    Expense newExpense;
    char selection;

    newExpense.setExpenseId(getNewExpenseId());
    newExpense.setUserId(LOGGED_USER_ID);

    cout << "Czy wydatek dotyczy dnia dzisiejszego? t - Tak, n - nie" << endl;

    while(true)
    {
        selection = getch();

        if(selection == 't')
        {
            newExpense.setDate(AuxiliaryMethods::getCurrentUnixTime());
            break;
        }
        else if(selection == 'n')
        {
            cout << "Podaj date wydatku w formacie rrrr-mm-dd: ";
            newExpense.setDate(AuxiliaryMethods::getCorrectDate());
            break;
        }
        else
            cout << "Blad! Wybierz odpowiedni znak." << endl;
    }

    cout << "Podaj czego dotyczy wydatek: ";
    newExpense.setItem(AuxiliaryMethods::getLine());

    cout << "Okresl wysokosc wydatku: ";
    newExpense.setAmount(AuxiliaryMethods::getFloat());

    return newExpense;
}

int ExpenseManager::getNewExpenseId()
{
    if(expenses.empty())
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}

void  ExpenseManager::addExpense()
{
    Expense newExpense = getNewExpenseData();
    expenses.push_back(newExpense);

    expenseFile.appendExpenseToFile(newExpense);
    AuxiliaryMethods::timedMessage("Wydatek dodany pomyslnie!");
}
