#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include "XmlFile.h"
#include "User.h"

using namespace std;

class UserFile : public XmlFile
{
    User getUserData();

public:
    UserFile(string fileName) : XmlFile(fileName) {};

    vector<User> loadUsersFromFile();
    void appendUserToFile(User user);

};
#endif // USERFILE_H
