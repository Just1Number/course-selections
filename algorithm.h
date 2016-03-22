#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <list>
#include <QMessageBox>
#include <QString>
#include <tuple>
#include <vector>

using namespace std;

class Algorithm
{
    public:
        Algorithm(vector<list<QString> > list_of_votelists,
                vector<tuple<QString, unsigned> > list_of_courses_and_max_members);
        void matchCourses();
        vector<QString> getMatchlist();
    private:
        vector<list<QString> > list_of_votelists;
        vector<tuple<QString, unsigned> > list_of_courses_and_max_members;
        list<int> list_of_voter_ids;
        vector<QString> matchlist;
        QMessageBox msgbox;

};

#endif // ALGORITHM_H
