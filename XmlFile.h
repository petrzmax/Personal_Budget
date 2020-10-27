#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include "Markup.h"

using namespace std;

class XmlFile
{
    const string FILE_NAME;
    CMarkup xml;

public:
    XmlFile(string fileName) : FILE_NAME(fileName){};

};
#endif // XMLFILE_H
