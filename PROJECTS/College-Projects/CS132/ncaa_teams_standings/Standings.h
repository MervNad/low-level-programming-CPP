/////////////////////////////////  standings.h  ///////////////////////
//
// File name         : standings.h
//
// Description: This header file defines the Standings class,
//				which is used for managing NCAA team standings. 
//				The class includes various member functions for adding,removing, editing,
//				and displaying teams' information, as well as saving data to a file.
//  
// 
//
// Programmer        : Merveilles Biende Katumba
//
// Date created      : 3/27/2024
//
// Date last revised : 04/04/2024
//
///////////////////////////////////////////////////////////////////////////////

#ifndef STANDINGS_H
#define STANDINGS_H

#include <list>
#include "team.h"

class Standings:protected Team
{
public:
	Standings(int Rnk = 0, std::string Nam = " ", int W = 0, int L = 0, int Vot = 0, std::string STRlWRnk = "", int INTlWRnk = -1); //constructor
	Standings(Standings& initStanding); //copy constructor
	~Standings(); //destructor

	void orderByVotes(std::list<Team>& l); //orders the list of teams by votes
	std::string Date(); //takes a date from the user and save it to be used as file name.
	//std::string getTeam(); // get a team name from the user
	void addTeam(std::list<Team>& l, Team& addTeam); //adds a team to the list
	void removeTeam(std::list<Team>& l, std::string TobeRemovedTeam); //removes a team from the list by name
	void editTeam(std::list<Team>& l, Team editTeam); //allows a user to edit a team's info

	void retrieve_Standing(std::istream& input, std::list<Team>& l); //takes teams info from a tsv file and into our list
	void displayTopTeams(std::list<Team>& l); //prints the top 25 teams in the console
	void displayAllTeams(std::list<Team>& l); //prints all teams in the console
	void saveStanding(std::ostream& out, /*std::string& date,*/ std::list<Team>& l); //saves teams info in a tsv file

	void validateInput(int input); //ensures that user's input is an int when needed

private:
	Team teamInfo; //holds the info of a single team
	std::list<Team> collegeTeams;
};

#endif