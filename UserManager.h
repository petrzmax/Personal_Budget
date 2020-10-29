#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "UserFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    UserFile userFile;

    User getNewUserData();
    int getNewUserId();
    bool loginExist(string login);

public:

    UserManager(string usersFileName) : userFile(usersFileName)
    {
        users = userFile.loadUsersFromFile();
    }

    void registerUser();
    void loginUser();
    void logoutUser();
    void changePassword();

    bool isUserLoggedIn();

};

#endif // USERMANAGER_H
