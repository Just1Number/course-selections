#include "algorithm.h"

Algorithm::Algorithm(
        vector<list<QString> > listOfVotelists,
        vector<tuple<QString, unsigned> > listOfCoursesAndMaxMembers)
{
    list<unsigned> sizeList;
    foreach (list<QString> voteList, listOfVotelists) {
        sizeList.push_back(voteList.size());
    }
    sizeList.sort();
    if(*(sizeList.begin()) != *(sizeList.end()) ) {
        throw invalid_argument("The votelists need to have equal size");
    }
    this->listOfVotelists = listOfVotelists;
    this->listOfCoursesAndMaxMembers = listOfCoursesAndMaxMembers;
    for (unsigned id = 0; id < *(sizeList.begin()); ++id) {
            this->listOfVoterIds.push_back(id);
    }

    this->matchlist.resize(*(sizeList.begin()) );
}

void Algorithm::course_matching_algo(){

    for (unsigned voteRound = 0; voteRound < listOfVotelists.size(); ++voteRound) {

        for (unsigned choice = 0; choice < listOfCoursesAndMaxMembers.size(); ++choice) {

            list<int> courseVoters;
            list<int>::iterator voterId = listOfVoterIds.begin();
            for (list<QString>::iterator vote = listOfVotelists[voteRound].begin(); vote != listOfVotelists[voteRound].end(); ++vote) {
                if (*vote == get<0>(listOfCoursesAndMaxMembers[choice] ) ) {
                    courseVoters.push_back(*(voterId) );
                }
                ++voterId;
            }

            while (courseVoters.size() > get<1>(listOfCoursesAndMaxMembers[choice] ) ) {
                list<int>::iterator kickChoice = courseVoters.begin();
                srand (time(NULL));
                advance(kickChoice, rand() % courseVoters.size());
                courseVoters.erase(kickChoice);
            }

            get<1>(listOfCoursesAndMaxMembers[choice]) = get<1>(listOfCoursesAndMaxMembers[choice]) - courseVoters.size();

            foreach (int voter, courseVoters) {
                matchlist[voter] = get<0>(listOfCoursesAndMaxMembers[choice]);

                int index = 0;
                for (list<int>::iterator i = listOfVoterIds.begin(); *(i) != voter || i == listOfVoterIds.end(); ++i) {
                    ++index;
                }
                listOfVoterIds.remove(voter);
                foreach (list<QString> voteList, listOfVotelists) {
                    list<QString>::iterator iter = voteList.begin();
                    advance(iter, index);
                    voteList.erase(iter);
                }
            }
        }
    }
}

vector<QString> Algorithm::get_matchlist(){
    return matchlist;
}
