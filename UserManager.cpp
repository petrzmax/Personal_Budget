#include "UserManager.h"

User UserManager::getNewUserData()
{

}

int UserManager::getNewUserId()
{

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
