#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include "UserManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    //IncomeManager *incomeManager;
    //ExpenseManager *expenseManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

    float getTotalExpenses();
    float getTotalIncomes();
    float getPeriodExpenses();
    float getPeriodIncomes();

public:

    PersonalBudget(string usersFileName, string incomesFileName, string expensesFileName)
        : userManager(usersFileName),
          INCOMES_FILE_NAME(incomesFileName),
          EXPENSES_FILE_NAME(expensesFileName) {};

    void registerUser();
    void loginUser();
    void changePassword();
    void logoutUser();

    void addIncome();
    void addExpense();

    void displayLastMonthBalance();
    void displayCurrentMonthBalance();
    void displayChosenPeriodBalance();

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();

};

#endif // PERSONALBUDGET_H
