#include "UserFile.h"

User UserFile::getUserData()
{

}

vector<User> UserFile::loadUsersFromFile()
{

}

void UserFile::appendUserToFile(User user)
{
    bool fileExists = xml.Load(getFileName());

    if(!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem(); //Sets position to "Users" element
    xml.IntoElem(); //Make Users element current parent position

    xml.AddElem("User");
    xml.IntoElem();

    xml.AddElem("userId", user.getUserId());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());

    xml.Save(getFileName());
}
