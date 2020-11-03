#include "IncomeFile.h"

Income IncomeFile::getIncomeData()
{
    Income income;

    xml.IntoElem(); //Make Income element current parent position

    xml.FindElem("incomeId");
    income.setIncomeId(atoi(xml.GetData().c_str()));

    xml.FindElem("userId");
    income.setUserId(atoi(xml.GetData().c_str()));

    xml.FindElem("date");
    income.setDate(atoll(xml.GetData().c_str()));

    xml.FindElem("item");
    income.setItem(xml.GetData());

    xml.FindElem("amount");
    income.setAmount(atof(xml.GetData().c_str()));

    xml.OutOfElem(); //Make Incomes element current parent position again (go out from current income)

    return income;
}

vector<Income> IncomeFile::loadIncomesFromFile(int loggedUserId)
{
    if(xml.Load(getFileName()))
    {
        Income loadedIncome;
        vector<Income> incomes;

        xml.FindElem(); //Sets position to "Incomes" element
        xml.IntoElem(); //Make Incomes element current parent position

        while(xml.FindElem("Income"))
        {
            loadedIncome = getIncomeData();
            if(loadedIncome.getUserId() == loggedUserId)
                incomes.push_back(loadedIncome);

            lastIncomeId = loadedIncome.getIncomeId();
        }
        return incomes;
    }
    else
    {
        cout << "Nie udalo sie zaladowac pliku z przychodami!";
        return vector<Income>();
    }
}

void IncomeFile::appendIncomeToFile(Income income)
{
    bool fileExists = xml.Load(getFileName());

    if(!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem(); //Sets position to "Incomes" element
    xml.IntoElem(); //Make Incomes element current parent position

    xml.AddElem("Income");
    xml.IntoElem();

    xml.AddElem("incomeId", income.getIncomeId());
    xml.AddElem("userId", income.getUserId());
    xml.AddElem("date", income.getDate());
    xml.AddElem("item", income.getItem());
    xml.AddElem("amount", to_string(income.getAmount()));

    xml.Save(getFileName());

    lastIncomeId++;
}

int IncomeFile::getLastIncomeId()
{
    return lastIncomeId;
}
