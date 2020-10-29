#include "UserManager.h"

User UserManager::getNewUserData()
{
    User newUser;

    newUser.setUserId(getNewUserId());

    cout << "Podaj imie: ";
    newUser.setName(AuxiliaryMethods::getLine());

    cout << "Podaj nazwisko: ";
    newUser.setSurname(AuxiliaryMethods::getLine());

    cout << "Podaj login: ";

    do
    {
        newUser.setLogin(AuxiliaryMethods::getLine());
    }
    while(loginExist(newUser.getLogin()));

    cout << "Podaj haslo: ";
    newUser.setPassword(AuxiliaryMethods::getLine());

    cout << "Podaj hasło ponownie: ";
    if(newUser.getPassword() == AuxiliaryMethods::getLine())
        return newUser;
}

int UserManager::getNewUserId()
{
    if(users.empty())
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::loginExist(string login)
{
    for(int i = 0; i < users.size(); i++)
        if(users[i].getLogin() == login)
        {
            cout << "Uzytkownik o takiej nazwie juz istnieje!\nPodaj inny login: ";
            return true;
        }

    return false;
}

void UserManager::registerUser()
{

}

void UserManager::loginUser()
{

}

void UserManager::logoutUser()
{

}

void UserManager::changePassword()
{

}

bool UserManager::isUserLoggedIn()
{

}
