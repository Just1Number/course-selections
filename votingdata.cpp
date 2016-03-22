#include "votingdata.h"

VotingData::VotingData()
{

}

vector<list<QString> > VotingData::listOfVotelists(){
    return this->list_of_votelists;
}

vector<tuple<QString, unsigned> > VotingData::listOfCoursesAndMaxMembers(){
    return this->list_of_courses_and_max_members;
}

list<int> VotingData::listOfVoterIds(){
    return this->list_of_voter_ids;
}

vector<QString> VotingData::getMatchlist(){
    return this->matchlist;
}

void VotingData::setListOfVotelists(vector<list<QString> > list_of_votelists){
    this->list_of_votelists = list_of_votelists;
}

void VotingData::setListOfCoursesAndMaxMembers(vector<tuple<QString, unsigned> > list_of_courses_and_max_members){
    this->list_of_courses_and_max_members = list_of_courses_and_max_members;
}

void VotingData::setListOfVoterIds(list<int> list_of_voter_ids){
    this->list_of_voter_ids = list_of_voter_ids;
}

void VotingData::setMatchlist(vector<QString> matchlist){
    this->matchlist = matchlist;
}
