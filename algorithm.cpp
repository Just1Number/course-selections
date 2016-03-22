#include "algorithm.h"

Algorithm::Algorithm(
        vector<list<QString> > list_of_votelists,
        vector<tuple<QString, unsigned> > list_of_courses_and_max_members)
{
    list<unsigned> size_list;
    foreach (list<QString> votelist, list_of_votelists) {
        size_list.push_back(votelist.size());
    }
    size_list.sort();
    if(*(size_list.begin()) != *(size_list.end()) ) {
        throw invalid_argument("The votelists need to have equal size");
    }
    this->list_of_votelists = list_of_votelists;
    this->list_of_courses_and_max_members = list_of_courses_and_max_members;
    for (unsigned id = 0; id < *(size_list.begin()); ++id) {
            this->list_of_voter_ids.push_back(id);
    }

    this->matchlist.resize(*(size_list.begin()) );
}

void Algorithm::matchCourses(){

    for (unsigned vote_round = 0; vote_round < list_of_votelists.size(); ++vote_round) {

        for (unsigned choice = 0; choice < list_of_courses_and_max_members.size(); ++choice) {

            list<int> course_voters;
            list<int>::iterator voter_id = list_of_voter_ids.begin();
            for (list<QString>::iterator vote = list_of_votelists[vote_round].begin(); vote != list_of_votelists[vote_round].end(); ++vote) {
                if (*vote == get<0>(list_of_courses_and_max_members[choice] ) ) {
                    course_voters.push_back(*(voter_id) );
                }
                ++voter_id;
            }

            while (course_voters.size() > get<1>(list_of_courses_and_max_members[choice] ) ) {
                list<int>::iterator kick_choice = course_voters.begin();
                srand (time(NULL));
                advance(kick_choice, rand() % course_voters.size());
                course_voters.erase(kick_choice);
            }

            get<1>(list_of_courses_and_max_members[choice]) = get<1>(list_of_courses_and_max_members[choice]) - course_voters.size();

            foreach (int voter, course_voters) {
                matchlist[voter] = get<0>(list_of_courses_and_max_members[choice]);

                int position_of_voter = 0;
                for (list<int>::iterator voter_id_pointer = list_of_voter_ids.begin(); *(voter_id_pointer) != voter || voter_id_pointer == list_of_voter_ids.end(); ++voter_id_pointer) {
                    ++position_of_voter;
                }
                list_of_voter_ids.remove(voter);
                foreach (list<QString> votelist, list_of_votelists) {
                    list<QString>::iterator delete_this = votelist.begin();
                    advance(delete_this, position_of_voter);
                    votelist.erase(delete_this);
                }
            }
        }
    }
}

vector<QString> Algorithm::getMatchlist(){
    return matchlist;
}
