#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>
#include "XmlFile.h"
#include "Income.h"

using namespace std;

class IncomeFile : public XmlFile
{
    Income getIncomeData();

public:
    IncomeFile(string fileName) : XmlFile(fileName) {};

    vector<Income> loadIncomesFromFile();
    void appendIncomeToFile(Income income);

};
#endif // INCOMEFILE_H
