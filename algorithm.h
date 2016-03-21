#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <list>
#include <string>
#include <QMessageBox>
#include <QString>
#include <tuple>
#include <vector>

using namespace std;
class Algorithm
{
    public:
        Algorithm(vector<list<QString> > listOfVotelists,
                vector<tuple<QString, unsigned> > listOfCoursesAndMaxMembers);
        void course_matching_algo();
        vector<QString> get_matchlist();
    private:
        vector<list<QString> > listOfVotelists;
        vector<tuple<QString, unsigned> > listOfCoursesAndMaxMembers;
        list<int> listOfVoterIds;
        vector<QString> matchlist;
        QMessageBox msgbox;

};

#endif // ALGORITHM_H
