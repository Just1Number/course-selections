#include "algorithm.h"
#include <QApplication>

Algorithm::Algorithm(
        vector<list<string> > listOfVotelists,
        vector<tuple<string, unsigned> > listOfCoursesAndMaxMembers,
        vector<int> listOfVoterIds)
{
    this->listOfVotelists = listOfVotelists;
    this->listOfCoursesAndMaxMembers = listOfCoursesAndMaxMembers;
    this->listOfVoterIds = listOfVoterIds;
}

void Algorithm::course_matching_algo(){
    for (unsigned voteRound = 0; voteRound < listOfVotelists.size(); ++voteRound) {

        for (unsigned choice = 0; choice < listOfCoursesAndMaxMembers.size(); ++choice) {

            list<int> courseVoters;
            int voterId = 0;
            for (list<string>::iterator voter = listOfVotelists[voteRound].begin(); voter != listOfVotelists[voteRound].end(); ++voter) {
                if (*voter == get<0>(listOfCoursesAndMaxMembers[choice] ) ) {
                    courseVoters.push_back(listOfVoterIds[voterId]);
                }
                ++voterId;
            }

            while (courseVoters.size() > get<1>(listOfCoursesAndMaxMembers[choice] ) ) {
                list<int>::iterator kickChoice = courseVoters.begin();
                srand (time(NULL));
                advance(kickChoice, rand() % courseVoters.size());
                courseVoters.erase(kickChoice);
            }
        }
    }
}
