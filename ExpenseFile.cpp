#include "ExpenseFile.h"

Expense ExpenseFile::getExpenseData()
{
    Expense expense;

    xml.IntoElem(); //Make Expense element current parent position

    xml.FindElem("expenseId");
    expense.setExpenseId(atoi(xml.GetData().c_str()));

    xml.FindElem("userId");
    expense.setUserId(atoi(xml.GetData().c_str()));

    xml.FindElem("date");
    expense.setDate(atoll(xml.GetData().c_str()));

    xml.FindElem("item");
    expense.setItem(xml.GetData());

    xml.FindElem("amount");
    expense.setAmount(atof(xml.GetData().c_str()));

    xml.OutOfElem(); //Make Expenses element current parent position again (go out from current Expense)

    return expense;
}

vector<Expense> ExpenseFile::loadExpensesFromFile(int loggedUserId)
{
    if(xml.Load(getFileName()))
    {
        Expense loadedExpense;
        vector<Expense> expenses;

        xml.FindElem(); //Sets position to "Expenses" element
        xml.IntoElem(); //Make Expenses element current parent position

        while(xml.FindElem("Expense"))
        {
            loadedExpense = getExpenseData();
            if(loadedExpense.getUserId() == loggedUserId)
                expenses.push_back(loadedExpense);
        }
        return expenses;
    }
    else
    {
        cout << "Nie udalo sie zaladowac pliku z wydatkami!";
        return vector<Expense>();
    }
}

void ExpenseFile::appendExpenseToFile(Expense expense)
{
    bool fileExists = xml.Load(getFileName());

    if(!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem(); //Sets position to "Expenses" element
    xml.IntoElem(); //Make Expenses element current parent position

    xml.AddElem("Expense");
    xml.IntoElem();

    xml.AddElem("expenseId", expense.getExpenseId());
    xml.AddElem("userId", expense.getUserId());
    xml.AddElem("date", expense.getDate());
    xml.AddElem("item", expense.getItem());
    xml.AddElem("amount", to_string(expense.getAmount()));

    xml.Save(getFileName());
}
