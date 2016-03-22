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
    QByteArray save_data = loadFile.readAll();
    QJsonDocument loaded_doc (QJsonDocument::fromJson(save_data) );
    QJsonObject root = loaded_doc.object();
    QMessageBox msgbox;
    QString simple = root["simpleString"].toString();
    msgbox.setText(simple);
    msgbox.exec();
    // read list_of_votelists
    QJsonArray j_list_of_votelists = root["list_of_votelists"].toArray();
    for (int list_index = 0; list_index < j_list_of_votelists.size(); ++list_index) {
        QJsonArray j_votelist = j_list_of_votelists[list_index].toArray();
        list<QString> votelist;
        for (int vote_index = 0; vote_index < j_votelist.size(); ++vote_index) {
            QString vote = j_votelist[vote_index].toString();
            votelist.push_back(vote);
        }
        this->list_of_votelists.push_back(votelist);
    }
    // read list_of_courses_and_max_members
    QJsonArray j_list_of_courses_and_max_members = root["list_of_courses_and_max_members"].toArray();
    for (int list_index = 0; list_index < j_list_of_courses_and_max_members.size(); ++list_index) {
        QJsonObject j_course = j_list_of_courses_and_max_members[list_index].toObject();
        QString course_name = j_course.keys()[0];
        unsigned max_members = j_course.value(course_name).toInt();
        tuple<QString, unsigned> course (course_name, max_members);
        this->list_of_courses_and_max_members.push_back(course);
    }
    return true;
}
