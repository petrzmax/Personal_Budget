#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");
    char selection = NULL;

    while(true)
    {
        if(personalBudget.isUserLoggedIn())
        {
            selection = personalBudget.selectOptionFromMainMenu();
            if(selection == '1') personalBudget.addIncome();
            else if(selection == '2') personalBudget.addExpense();
            else if(selection == '3') personalBudget.displayCurrentMonthBalance();
            else if(selection == '4') personalBudget.displayLastMonthBalance();
            else if(selection == '5') personalBudget.displayChosenPeriodBalance();
            else if(selection == '6') personalBudget.changePassword();
            else if(selection == '7') personalBudget.logoutUser();
        }
        else
        {
            selection = personalBudget.selectOptionFromUserMenu();
            if(selection == '1') personalBudget.loginUser();
            else if(selection == '2') personalBudget.registerUser();
            else if(selection == '3') exit(0);
        }
    }

    return 0;
}
