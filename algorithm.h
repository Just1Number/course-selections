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
                vector<tuple<string, unsigned> > listOfCoursesAndMaxMembers,
                vector<int> listOfVoterIds);
        void course_matching_algo();
        list<string> matchlist;
    private:
        vector<list<string> > listOfVotelists;
        vector<tuple<string, unsigned> > listOfCoursesAndMaxMembers;
        vector<int> listOfVoterIds;
        MessageBox msgbox;

};

#endif // ALGORITHM_H
