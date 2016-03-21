#ifndef JSONTRANSLATOR_H
#define JSONTRANSLATOR_H
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonParseError>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>

class JsonTranslator
{
public:
    JsonTranslator();
    bool read_file();
private:
    std::vector<std::list<QString> > listOfVotelists;
    std::vector<std::tuple<QString, unsigned> > listOfCoursesAndMaxMembers;
    std::list<int> listOfVoterIds;
    std::vector<QString> matchlist;
};

#endif // JSONTRANSLATOR_H
