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

class JsonTranslator
{
public:
    JsonTranslator();
    bool read_file();
};

#endif // JSONTRANSLATOR_H
