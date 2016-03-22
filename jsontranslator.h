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

using namespace std;

class JsonTranslator
{
public:
    JsonTranslator();
    bool read_file();
private:
    vector<list<QString> > list_of_votelists;
    vector<tuple<QString, unsigned> > list_of_courses_and_max_members;
    list<int> list_of_voter_ids;
    vector<QString> matchlist;
};

#endif // JSONTRANSLATOR_H
