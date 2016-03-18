#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <vector>
#include <string>
#include "messagebox.h"
#include <QString>
#include <tuple>

using namespace std;
class Algorithm
{
    public:
        Algorithm(
                vector<vector<string> > listOfVotelists,
                vector<tuple<string, int> > listOfCoursesAndMaxMembers);
        void course_matching_algo();
        vector<string> matchlist;
    private:
        vector<vector<string>> listOfVotelists;
        vector<tuple<string,int>> listOfCoursesAndMaxMembers;
        MessageBox msgbox;

};

#endif // ALGORITHM_H
