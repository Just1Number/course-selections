#include "algorithm.h"
#include <QApplication>

Algorithm::Algorithm(
        vector<vector<string> > listOfVotelists,
        vector<tuple<string, int> > listOfCoursesAndMaxMembers)
{
    this->listOfVotelists = listOfVotelists;
    this->listOfCoursesAndMaxMembers = listOfCoursesAndMaxMembers;
}

void Algorithm::course_matching_algo(){
    for (int voteRound = 0; voteRound < listOfVotelists.size(); ++voteRound) {
        for (int choice = 0; choice < listOfCoursesAndMaxMembers.size(); ++choice) {
            vector<int> courseVoters;
        }
    }
}
