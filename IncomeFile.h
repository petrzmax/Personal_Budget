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
    int lastIncomeId;

public:
    IncomeFile(string fileName) : XmlFile(fileName) {};

    vector<Income> loadIncomesFromFile(int loggedUserId);
    void appendIncomeToFile(Income income);

    int getLastIncomeId();

};
#endif // INCOMEFILE_H
