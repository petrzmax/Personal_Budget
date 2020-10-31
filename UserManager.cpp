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
    User newUser = getNewUserData();
    users.push_back(newUser);

    userFile.appendUserToFile(newUser);
    cout << "Konto zalozone pomyslnie!";
}

void UserManager::loginUser()
{
    string login;

    cout << "Podaj login: ";
    login = AuxiliaryMethods::getLine();

    vector<User>::iterator itr = users.begin();

    while(itr != users.end())
    {
        if(itr->getLogin() == login)
        {
            cout << "Podaj haslo: ";
            if(itr->getPassword() == AuxiliaryMethods::getLine())
            {
                loggedUserId = itr->getUserId();
                AuxiliaryMethods::timedMessage("Logowanie zakonczone sukcesem!");
                return;
            }
            else
            {
                AuxiliaryMethods::timedMessage("Haslo niepoprawne!");
                return;
            }
        }

        ++itr;
    }
    loggedUserId = 0;
    AuxiliaryMethods::timedMessage("Nie ma uzytkownika z takim loginem.");
}

void UserManager::logoutUser()
{
    loggedUserId = 0;
}

void UserManager::changePassword()
{
    system("cls");

    vector<User>::iterator itr = users.begin();

    while(itr != users.end())
    {
        if(itr->getUserId() == loggedUserId)
        {
            cout << "Podaj nowe haslo: ";
            itr->setPassword(AuxiliaryMethods::getLine());

            userFile.updateUserPassword(*itr);

            AuxiliaryMethods::timedMessage("Haslo zmienione pomyslnie!");
            return;
        }
        ++itr;
    }
}

bool UserManager::isUserLoggedIn()
{
    if(loggedUserId > 0)
        return true;
    else
        return false;
}
