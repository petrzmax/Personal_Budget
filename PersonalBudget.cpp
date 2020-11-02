#include "PersonalBudget.h"

float PersonalBudget::getTotalExpenses()
{

}

float PersonalBudget::getTotalIncomes()
{

}

float PersonalBudget::getPeriodExpenses()
{

}

float PersonalBudget::getPeriodIncomes()
{

}

void PersonalBudget::registerUser()
{
    userManager.registerUser();
}

void PersonalBudget::loginUser()
{
    userManager.loginUser();
    incomeManager = new IncomeManager(INCOMES_FILE_NAME, userManager.getLoggedUserId());
    expenseManager = new ExpenseManager(EXPENSES_FILE_NAME, userManager.getLoggedUserId());
}

void PersonalBudget::changePassword()
{
    userManager.changePassword();
}

void PersonalBudget::logoutUser()
{
    userManager.logoutUser();

    delete incomeManager;
    delete expenseManager;

    incomeManager = NULL;
    expenseManager = NULL;
}

bool PersonalBudget::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

void PersonalBudget::addIncome()
{
    incomeManager->addIncome();
}

void PersonalBudget::addExpense()
{
    expenseManager->addExpense();
}

void PersonalBudget::displayLastMonthBalance()
{
    float lastMonthIncomes, lastMonthExpenses;

    system("cls");
    cout << fixed;


    lastMonthIncomes = incomeManager->displayLastMonthIncomes();
    cout << endl;

    lastMonthExpenses = expenseManager->displayLastMonthExpenses();

    cout << endl << "Suma przychodow: " << lastMonthIncomes << endl;
    cout << "Suma wydatkow: " << lastMonthExpenses << endl;
    cout << "Bilans: " << lastMonthIncomes - lastMonthExpenses << endl;

    cout << endl <<"Wcisnij dowolny klawisz aby powrocic do menu.";
    getch();
}

void PersonalBudget::displayCurrentMonthBalance()
{
    float currentMonthIncomes, currentMonthExpenses;

    system("cls");
    cout << fixed;

    currentMonthIncomes = incomeManager->displayCurrentMonthIncomes();
    cout << endl;

    currentMonthExpenses = expenseManager->displayLastMonthExpenses();

    cout << endl << "Suma przychodow: " << currentMonthIncomes << endl;
    cout << "Suma wydatkow: " << currentMonthExpenses << endl;
    cout << "Bilans: " << currentMonthIncomes - currentMonthExpenses << endl;

    cout << endl <<"Wcisnij dowolny klawisz aby powrocic do menu.";
    getch();
}

void PersonalBudget::displayChosenPeriodBalance()
{

}

char PersonalBudget::selectOptionFromMainMenu()
{
    system("cls");
    cout << "-----Budzet Osobisty-----\n"
         << "1. Dodaj przychod\n"
         << "2. Dodaj wydatek\n"
         << "3. Bilans z biezacego miesiaca\n"
         << "4. Bilans z poprzedniego miesiaca\n"
         << "5. Bilans z wybranego okresu\n"
         << "6. Zmien haslo\n"
         << "7. Wyloguj sie\n";

    return AuxiliaryMethods::getChar();
}

char PersonalBudget::selectOptionFromUserMenu()
{
    system("cls");
    cout << "-----Budzet Osobisty-----\n"
         << "1. Logowanie\n"
         << "2. Rejestracja\n"
         << "3. Koniec programu\n";

    return AuxiliaryMethods::getChar();
}
