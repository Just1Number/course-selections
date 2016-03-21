#include "jsontranslator.h"

JsonTranslator::JsonTranslator()
{

}

bool JsonTranslator::read_file() {
    QFile loadFile("json_test.json");
    if (!loadFile.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open save file.");
            return false;
    }
    QJsonDocument loadDoc(QJsonDocument::fromJson(loadFile.readAll()) );
    return true;
}
