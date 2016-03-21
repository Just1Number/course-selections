#include "jsontranslator.h"

JsonTranslator::JsonTranslator()
{

}

bool JsonTranslator::read_file() {
    QFile loadFile("../json_test.json");
    if (!loadFile.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open file.");
            return false;
    }
    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData) );
    QJsonObject root = loadDoc.object();
    QMessageBox msgbox;
    QString simple = root["simpleString"].toString();
    msgbox.setText(simple);
    msgbox.exec();
    // read listOfVotelists
    QJsonArray jListOfVotelists = root["listOfVotelists"].toArray();
    for (int listIndex = 0; listIndex < jListOfVotelists.size(); ++listIndex) {
        QJsonArray jVotelist = jListOfVotelists[listIndex].toArray();
        std::list<QString> votelist;
        for (int voteIndex = 0; voteIndex < jVotelist.size(); ++voteIndex) {
            QString vote = jVotelist[voteIndex].toString();
            votelist.push_back(vote);
        }
        this->listOfVotelists.push_back(votelist);
    }
    // read listOfCoursesAndMaxMembers
    QJsonArray jListOfCoursesAndMaxMembers = root["listOfCoursesAndMaxMembers"].toArray();
    for (int listIndex = 0; listIndex < jListOfCoursesAndMaxMembers.size(); ++listIndex) {
        QJsonObject jCourse = jListOfCoursesAndMaxMembers[listIndex].toObject();
        QString courseName = jCourse.keys()[0];
        unsigned maxMembers = jCourse.value(courseName).toInt();
        std::tuple<QString, unsigned> course (courseName, maxMembers);
        this->listOfCoursesAndMaxMembers.push_back(course);
    }
    return true;
}
