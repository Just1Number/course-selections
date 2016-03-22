#ifndef VOTINGDATA_H
#define VOTINGDATA_H
#include <list>
#include <QMessageBox>
#include <QString>
#include <tuple>
#include <vector>

using namespace std;

class VotingData
{
public:
    VotingData();
    vector<list<QString> > listOfVotelists();
    vector<tuple<QString, unsigned> > listOfCoursesAndMaxMembers();
    list<int> listOfVoterIds();
    vector<QString> getMatchlist();
    void setListOfVotelists(vector<list<QString> > list_of_votelists);
    void setListOfCoursesAndMaxMembers(vector<tuple<QString, unsigned> > list_of_courses_and_max_members);
    void setListOfVoterIds(list<int> list_of_voter_ids);
    void setMatchlist(vector<QString> matchlist);
private:
    vector<list<QString> > list_of_votelists;
    vector<tuple<QString, unsigned> > list_of_courses_and_max_members;
    list<int> list_of_voter_ids;
    vector<QString> matchlist;
    QMessageBox msgbox;
};

#endif // VOTINGDATA_H
