#include "UserFile.h"

User UserFile::getUserData()
{
    User user;

    xml.IntoElem(); //Make User element current parent position

    xml.FindElem("userId");
    user.setUserId(atoi(xml.GetData().c_str()));

    xml.FindElem("name");
    user.setName(xml.GetData());

    xml.FindElem("surname");
    user.setSurname(xml.GetData());

    xml.FindElem("login");
    user.setLogin(xml.GetData());

    xml.FindElem("password");
    user.setPassword(xml.GetData());

    xml.OutOfElem(); //Make Users element current parent position again (go out from current user)

    return user;
}

vector<User> UserFile::loadUsersFromFile()
{
    if(xml.Load(getFileName()))
    {
        vector<User> users;

        xml.FindElem(); //Sets position to "Users" element
        xml.IntoElem(); //Make Users element current parent position

        while(xml.FindElem("User"))
        {
            users.push_back(getUserData());
        }
        return users;
    }
    else
    {
        cout << "Nie udalo sie zaladowac pliku z uzytkownikami!";
        return vector<User>();
    }
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

void UserFile::updateUserPassword(User user)
{
    if(xml.Load(getFileName()))
    {
        xml.FindElem(); //Sets position to "Users" element
        xml.IntoElem(); //Make Users element current parent position

        while(xml.FindElem("User"))
        {
            xml.FindChildElem("userId");
            if(AuxiliaryMethods::stringToInt(xml.GetChildData()) == user.getUserId())
            {
                //User found
                xml.FindChildElem("password");
                xml.SetChildData(user.getPassword());
                xml.Save(getFileName());

                return;
            }
        }
        AuxiliaryMethods::timedMessage("BLAD! W pliku nie ma takiego uzytkownika!");
    }
    else
    {
        AuxiliaryMethods::timedMessage("Nie udalo sie zaladowac pliku z uzytkownikami!");
    }
}
