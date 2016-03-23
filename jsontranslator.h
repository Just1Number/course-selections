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
#include "votingdata.h"

using namespace std;

class JsonTranslator
{
public:
    JsonTranslator();
    VotingData getVoteData();
    bool read_file();
private:
    VotingData vote_data;
    vector<QString> matchlist;
};

#endif // JSONTRANSLATOR_H
