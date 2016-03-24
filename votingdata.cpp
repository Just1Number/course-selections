#include "votingdata.h"
#include <string>

/**
 * @brief VotingData::VotingData
 * The constructor initializes all attributes of the class, to prevent a segemtation fault
 */
VotingData::VotingData()
{
    vector<tuple<QString, unsigned> > tuple_vector;
    tuple<QString, unsigned> empty_tuple;
    tuple_vector.push_back(empty_tuple);
    this->list_of_courses_and_max_members = tuple_vector ;
    vector<list<QString> > list_vector;
    list<QString> random_list;
    list_vector.push_back(random_list);
    this->list_of_votelists = list_vector;
}

/**
 * @brief VotingData::listOfVotelists
 * @return list_of_votelists
 */
vector<list<QString> > VotingData::listOfVotelists(){
    return this->list_of_votelists;
}

/**
 * @brief VotingData::listOfCoursesAndMaxMembers
 * @return list_of_courses_and_max_members
 */
vector<tuple<QString, unsigned> > VotingData::listOfCoursesAndMaxMembers(){
    return this->list_of_courses_and_max_members;
}

/**
 * @brief VotingData::listOfVoterIds
 * @return list_of_voter_ids
 */
list<int> VotingData::listOfVoterIds(){
    return this->list_of_voter_ids;
}

/**
 * @brief VotingData::matchlist
 * @return _matchlist
 */
vector<QString> VotingData::matchlist(){
    return this->_matchlist;
}

/**
 * @brief VotingData::setListOfVotelists
 * @param list_of_votelists
 * @throw invalid_argument - if the lists don't have equal size
 */
void VotingData::setListOfVotelists(vector<list<QString> > list_of_votelists){
    // Testing if all votelist have the same size.
    unsigned size = 0;
    foreach (list<QString> votelist, list_of_votelists) {
        if (size != 0 && size != votelist.size()){
            throw invalid_argument("The votelists need to have equal size");
        }
        size = votelist.size();
    }
    this->list_of_votelists = list_of_votelists;
}

/**
 * @brief VotingData::setListOfCoursesAndMaxMembers
 * @param list_of_courses_and_max_members
 * @throw invalid_argument - if a course has an empty QString as a name
 */
void VotingData::setListOfCoursesAndMaxMembers(vector<tuple<QString, unsigned> > list_of_courses_and_max_members){
    for (unsigned course_index = 0; course_index < list_of_courses_and_max_members.size(); ++course_index) {
        tuple<QString, unsigned> course = list_of_courses_and_max_members[course_index];
        QString course_name = get<0>(course);
        if(course_name.isEmpty()){
            string exception_msg = "Course number ";
            exception_msg.append(to_string(course_index));
            exception_msg.append(" has no name");
            throw invalid_argument(exception_msg);
        }
    }

    this->list_of_courses_and_max_members = list_of_courses_and_max_members;
}

/**
 * @brief VotingData::setListOfVoterIds
 * @param list_of_voter_ids
 */
void VotingData::setListOfVoterIds(list<int> list_of_voter_ids){
    this->list_of_voter_ids = list_of_voter_ids;
}

/**
 * @brief VotingData::setMatchlist
 * @param matchlist
 */
void VotingData::setMatchlist(vector<QString> matchlist){
    this->_matchlist = matchlist;
}

/**
 * @brief VotingData::matchCourses
 * @return true if successful - false if not
 * Whenever the function fails a MessageBox opens with an appropriate error message. At the end courses_matched is set true.
 */
bool VotingData::matchCourses(){

    if(courses_matched){
        msgbox.setText("Courses are already matched");
        msgbox.setWindowTitle("Error matching Courses");
        msgbox.exec();
        return false;
    }

    if(list_of_votelists[0].empty()) {
        msgbox.setText("The votelists are empty");
        msgbox.setWindowTitle("Error matching Courses");
        msgbox.exec();
        return false;
    }

    // Fill list_of_voter_ids
    for (unsigned id = 0; id < list_of_votelists[0].size(); ++id) {
            this->list_of_voter_ids.push_back(id);
    }

    for (unsigned vote_round = 0; vote_round < list_of_votelists.size(); ++vote_round) {

        for (unsigned course_index = 0; course_index < list_of_courses_and_max_members.size(); ++course_index) {

            list<int> course_voters;
            list<int>::iterator voter_id = list_of_voter_ids.begin();
            for (list<QString>::iterator vote = list_of_votelists[vote_round].begin(); vote != list_of_votelists[vote_round].end(); ++vote) {
                // check every vote whether it matches the currently covered course and put it in course_voters if it does
                if (*vote == get<0>(list_of_courses_and_max_members[course_index] ) ) {
                    course_voters.push_back(*(voter_id) );
                }
                ++voter_id;
            }

            // kick random votes from course_voters if there are more votes than allowed members
            while (course_voters.size() > get<1>(list_of_courses_and_max_members[course_index] ) ) {
                list<int>::iterator kick_choice = course_voters.begin();
                srand (time(NULL));
                advance(kick_choice, rand() % course_voters.size());
                course_voters.erase(kick_choice);
            }

            // subtract the number of assigned votes from the max members
            get<1>(list_of_courses_and_max_members[course_index]) = get<1>(list_of_courses_and_max_members[course_index]) - course_voters.size();

            // save assigned votes in _matchlist and delete voters from other lists
            foreach (int voter, course_voters) {
                _matchlist[voter] = get<0>(list_of_courses_and_max_members[course_index]);

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
    courses_matched = true;
    return true;
}

