/////////////////////////////////  team.h  ///////////////////////
//
// File name         : team.h
//
// Description: The team.h header file defines a Team struct that represents a basketball team.
//				This struct encapsulates various attributes related to the team's standing,
//				including rank, wins, losses, votes, and previous week's rank.
//				Additionally, it provides functionality through overloaded input/output operators
//				and a logical equality operator for comparison.
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

#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <iomanip>

struct Team //basketball team
{
	int Rank = 0, //team's rank
		Wins = 0, //number of wins
		Loses = 0, //number of loses
		Votes = 0, //number of votes
		previousWeekRank = -1; //team's previous rank (int)
	std::string Name, //team's name
		        Unranked = ""; //team's previous rank (string "NR")

	//overloaded insertion operator
	friend std::ostream& operator << (std::ostream& out, const Team& info)
	{
		out << std::left << std::setw(7) << info.Rank
			<< std::setw(20) << info.Name
			<< info.Wins << '-'
			<< std::setw(7) << info.Loses
			<< std::setw(9) << info.Votes;

		if (info.previousWeekRank == -1) //the team has no previous rank
			out << info.Unranked << '\t';
		else //the team has previous rank
			out << info.previousWeekRank << '\t';

		return out;
	}

	//overloaded extraction operator
	friend std::istream& operator >> (std::istream& in, Team& info)
	{
		in >> info.Rank;
		in.ignore(1, '\t');

		in >> info.Name;

		 //if a name has more than 1 word,
		//take the other word and combine it with the first one
		while (in.peek() == ' ')
		{
			in.ignore(1, ' ');
			std::string name2;

			in >> name2;

			info.Name = info.Name + ' ' + name2;
		}
		in.ignore(1, '\t');

		in >> info.Wins;
		if (in.peek() == '-') 
			in.ignore(1, '-');
		else 
			in.ignore(1, '\t');

		in >> info.Loses;
		in.ignore(1, '\t');

		in >> info.Votes;
		in.ignore(1, '\t');

		 //if a team has no pervious rank (i.e. "NR"),
		//take the input as a string,
		char previousR = std::cin.peek();
		if (isdigit(previousR))
			in >> info.previousWeekRank;
		else //take the input as an int
			in >> info.Unranked;

		in.ignore(1, '\t');

		return in;
	}

	//overloaded logical equality operator
	bool operator == (const Team& team2) const
	{
		if (this->Rank == team2.Rank
			&& this->Name == team2.Name
			&& this->Wins == team2.Wins
			&& this->Loses == team2.Loses
			&& this->Votes == team2.Votes
			&& this->Unranked == team2.Unranked
			&& this->previousWeekRank == team2.previousWeekRank)
			return true;

		return false;
	}
};

#endif
