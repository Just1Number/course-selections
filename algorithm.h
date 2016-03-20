#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <list>
#include <string>
#include "messagebox.h"
#include <QString>
#include <tuple>
#include <vector>

using namespace std;
class Algorithm
{
    public:
        Algorithm(vector<list<string> > listOfVotelists,
                vector<tuple<string, unsigned> > listOfCoursesAndMaxMembers);
        void course_matching_algo();
        vector<string> get_matchlist();
    private:
        vector<list<string> > listOfVotelists;
        vector<tuple<string, unsigned> > listOfCoursesAndMaxMembers;
        list<int> listOfVoterIds;
        vector<string> matchlist;
        MessageBox msgbox;

};

#endif // ALGORITHM_H
