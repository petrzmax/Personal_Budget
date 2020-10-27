#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include "Markup.h"

using namespace std;

class XmlFile
{
    const string FILE_NAME;


public:
    XmlFile(string fileName) : FILE_NAME(fileName){};

    string getFileName();
    CMarkup xml;

};
#endif // XMLFILE_H
