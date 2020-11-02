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

void ExpenseManager::displayExpenseHeader()
{
    cout << "------------------------Lista wydatkow------------------------" << endl;
    cout << left << setw(4) << "id"
         << left << setw(35)<< "Przedmiot"
         << left << setw(15)<< "Data"
         << left << setw(30)<< "Wydatek" << endl;
}

void ExpenseManager::displayExpensesVector(vector<Expense> &expenses)
{
    for(int i = 0; i < expenses.size(); i++)
        cout << left << setw(4) << expenses[i].getExpenseId()
             << left << setw(35)<< expenses[i].getItem()
             << left << setw(15)<< AuxiliaryMethods::unixTimeToStringDate(expenses[i].getDate())
             << left << setw(30)<< setprecision(2) << expenses[i].getAmount() << endl;
}

float ExpenseManager::getTotalExpensesValueInVector(vector<Expense> &expenses)
{
    float totalExpense = 0;

    for(int i = 0; i < expenses.size(); i++)
        totalExpense += expenses[i].getAmount();

    return totalExpense;
}

void  ExpenseManager::addExpense()
{
    Expense newExpense = getNewExpenseData();
    expenses.push_back(newExpense);

    expenseFile.appendExpenseToFile(newExpense);
    AuxiliaryMethods::timedMessage("Wydatek dodany pomyslnie!");
}

float ExpenseManager::displayCurrentMonthExpenses()
{
    time_t currentTime = AuxiliaryMethods::getCurrentUnixTime();
    time_t currentMonthfirstDayUnixTime = AuxiliaryMethods::getLastMonthLastDayUnixTime();

    vector<Expense> currentMonthExpenses;

    for(int i = 0; i < expenses.size(); i++)
    {
        if(expenses[i].getDate() > currentMonthfirstDayUnixTime &&
                expenses[i].getDate() < currentTime)
        {
            currentMonthExpenses.push_back(expenses[i]);
        }
    }

    sort(currentMonthExpenses.begin(), currentMonthExpenses.end(), greater <>());

    displayExpenseHeader();
    displayExpensesVector(currentMonthExpenses);

    return getTotalExpensesValueInVector(currentMonthExpenses);
}

float ExpenseManager::displayLastMonthExpenses()
{
    time_t lastMonthFirstDayUnixTime = AuxiliaryMethods::getLastMonthFirstDayUnixTime();
    time_t lastMonthLastDayUnixTime = AuxiliaryMethods::getLastMonthLastDayUnixTime();

    vector<Expense> lastMonthExpenses;

    for(int i = 0; i < expenses.size(); i++)
    {
        if(expenses[i].getDate() > lastMonthFirstDayUnixTime &&
                expenses[i].getDate() < lastMonthLastDayUnixTime)
        {
            lastMonthExpenses.push_back(expenses[i]);
        }
    }

    sort(lastMonthExpenses.begin(), lastMonthExpenses.end(), greater <>());

    displayExpenseHeader();
    displayExpensesVector(lastMonthExpenses);

    return getTotalExpensesValueInVector(lastMonthExpenses);
}
