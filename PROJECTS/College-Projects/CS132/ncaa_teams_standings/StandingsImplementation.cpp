/////////////////////////////////  StandingsImplementation.cpp  ///////////////////////
//
// File name         : StandingsImplementation.cpp
//
// Description: The StandingsImplementation.cpp file implements the member functions of the Standings class,
//				which is responsible for managing NCAA team standings.
//				It includes constructors, destructors,
//				and various member functions for retrieving standings from a file,
//				ordering teams by votes, adding/removing/editing teams, displaying teams' information,
//				saving standings to a file, and validating user input.
//  
// 
//
// Programmer        : Merveilles Biende Katumba
//
// Date created      : 3/27/2024
//
// Date last revised : 4/04/2024
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "Standings.h"

//constructor
Standings::Standings(int Rnk, std::string Nam, int W, int L, int Vot, std::string Unrnk, int prevWeekrnk)
{
	teamInfo.Rank = Rnk;
	teamInfo.Name = Nam;
	teamInfo.Wins = W;
	teamInfo.Loses = L;
	teamInfo.Votes = Vot;
	teamInfo.Unranked = Unrnk;
	teamInfo.previousWeekRank = prevWeekrnk;
}

//copy constructor
Standings::Standings(Standings& initStanding)
{
	this->Rank = initStanding.Rank;
	this->Name = initStanding.Name;
	this->Wins = initStanding.Wins;
	this->Loses = initStanding.Loses;
	this->Votes = initStanding.Votes;
	this->Unranked = initStanding.Unranked;
	this->previousWeekRank = initStanding.previousWeekRank;
}

//destructor
Standings::~Standings(){}

//takes teams info from a tsv file and into our list
void Standings::retrieve_Standing(std::istream& input, std::list<Team>& l)
{
	Team takeFromFile;

	int count = 0;
	while (input >> takeFromFile)
	{
		l.push_back(takeFromFile);

		if (input.fail())
			std::cout << "\ninput failed\n";

		count++;
	}
	std::cout << "All teams have been retrieved from the file!\n" << std::endl;
}

//orders the list of teams by votes
void Standings::orderByVotes(std::list<Team>& l)
{
	int newRank = 1; //rank the teams based on votes (1 is the highest rank)

	//sort the teams by vote count in descending order
	l.sort([this](const Team& team1, const Team& team2) {return team1.Votes > team2.Votes;});

	for (std::list<Team>::iterator i = l.begin(); i != l.end(); )
	{
		if (i->Votes == 0) //if a team has no votes, remove it
		{
			i = l.erase(i); //remove the element and move to the next one
			continue;
		}
		else //give the team its new rank and update it's pervious rank
		{
			//if the team was not ranked in recent standing.
			if (i->Unranked == "" && i->previousWeekRank == -1)
				i->Unranked = "NR";
			else { // Update previous rank
				i->Unranked = "";
				i->previousWeekRank = i->Rank;
			}
			//update current rank
			i->Rank = newRank;
		}

		newRank++; //descend to the next rank
		++i;
	}
}

//adds a team to the list
void Standings::addTeam(std::list<Team>& l, Team& addTeam)
{
	std::cout << "\nEnter the name of the team\n";
	std::cin >> addTeam.Name;

	 //if a name has more than 1 word,
    //take the other word and combine it with the first one
	while (std::cin.peek() == ' ')
	{
		std::cin.ignore(1, ' ');
		std::string name2;

		std::cin >> name2;

		addTeam.Name = addTeam.Name + ' ' + name2;
	}

	std::cout << "\nHow many wins does the team have?\n";
	std::cin >> addTeam.Wins;
	validateInput(addTeam.Wins);

	std::cout << "\nHow many loses does the team have?\n";
	std::cin >> addTeam.Loses;
	validateInput(addTeam.Loses);

	std::cout << "\nHow many votes does the team have?\n";
	std::cin >> addTeam.Votes;
	validateInput(addTeam.Votes);

	//addTeam.Unranked = "NR"; //new team has no previous rank

	l.push_back(addTeam); //add the team to the list

	orderByVotes(l); //reorder the list
}

//removes a team from the list by name
void Standings::removeTeam(std::list<Team>& l, std::string TobeRemovedTeam)
{
	bool foundTeam = false; //does the team exist in our list?

	std::cout << "Enter the name of the team that you would like to remove\n";
	std::cin >> TobeRemovedTeam;
	while (std::cin.peek() == ' ' || std::cin.peek() == '\t') {
		std::cin.ignore(1, ' ');

		if (std::cin.peek() == ' ' || std::cin.peek() == '\t')
			continue;
		std::string name2;
		std::cin >> name2;
		TobeRemovedTeam = TobeRemovedTeam + ' ' + name2;
	}
	/*std::getline(std::cin, TobeRemovedTeam);
	std::cout << std::endl;
	*/
	std::list<Team>::iterator i;
	for (i = l.begin(); i != l.end(); i++)
	{
		if (i->Name == TobeRemovedTeam) //the name exists in our list
		{
			std::cout << i->Name << " has been removed from the list\n";
			foundTeam = true;

			l.remove(*i);
			orderByVotes(l); //reorder the list
			break;
		}
	}

	if (!foundTeam) //the name does not exist in our list
		std::cout << TobeRemovedTeam << " is not in our list\n";
}

//allows a user to edit a team's info
void Standings::editTeam(std::list<Team>& l, Team editTeam)
{
	std::string teamName, //what team are we looking for?
		        changeName; //new name for a team
	Team Change; //user's Changes
	int choice = 0; 
	bool foundName = false;

	std::cout << "Enter the name of the team: ";

	while (!foundName) //look for a team as long as the user wants to
	{
		std::cin >> teamName;

		 //if a name has more than 1 word,
        //take the other word and combine it with the first one
		while (std::cin.peek() == ' ')
		{
			std::cin.ignore(1, ' ');
			std::string name2;

			std::cin >> name2;

			teamName = teamName + ' ' + name2;
		}

		std::cout << std::endl;

		std::list<Team>::iterator i;
		for (i = l.begin(); i != l.end(); i++)
		{
			if (i->Name == teamName)
			{
				foundName = true; //the team is in our list

				std::cout << "What change would you like to make?"
					      << "\n\t1. the team's name?"
					      << "\n\t2. the team's win count?"
					      << "\n\t3. the team's loss count?"
					      << "\n\t4. the amount of votes?"
					      << std::endl;
				std::cin >> choice;

				//validate user's choice
				while (choice > 6 || choice < 1 || std::cin.fail() || std::cin.peek() != '\n')
				{
					std::cout << "\nInvalid!\n"
						      << choice << " is not an option\n"
						      << "try again: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					std::cin >> choice;
				}
				std::cout << std::endl;

				switch (choice)
				{
				case 1: //edit the team's name
					std::cout << "Give the team a new name\n";
					std::cin >> Change.Name;

					 //if a name has more than 1 word,
                    //take the other word and combine it with the first one
					while (std::cin.peek() == ' ')
					{
						std::cin.ignore(1, ' ');
						std::string name2;

						std::cin >> name2;

						Change.Name = Change.Name + ' ' + name2;
					}

					i->Name.erase(); //empty the string before taking new input
					i->Name = Change.Name;
					break;

				case 2: //edit the team's win count
					std::cout << "How many wins?\n";
					std::cin >> Change.Wins;

					validateInput(Change.Wins);

					i->Wins = Change.Wins;
					break;

				case 3: //edit the team's loss count
					std::cout << "How many loss?\n";
					std::cin >> Change.Loses;

					validateInput(Change.Loses);

					i->Loses = Change.Loses;
					break;

				case 4: //edit the team's vote count
					std::cout << "How many votes?\n";
					std::cin >> Change.Votes;

					validateInput(Change.Votes);

					i->Votes = Change.Votes;

					//reorder the list to update the team's current rank
					orderByVotes(l); 
				}//end of switch statement

				break; //get out of the for loop

			} //end of if statement

		}//end of for loop

		if (!foundName)
		{
			std::string tryAgain; //does the user want to attempt to find the team again?

			std::cout << "The team that you're looking for is not on the list\n"
				      << "Check for spelling mistakes\n\n"
				      << "would you like to try again? yes or no\n";
			std::cin >> tryAgain;

			//making "yes" or "no" valid regardless of capitalization
			for (int i = 0; i < tryAgain.size(); i++)
				tryAgain[i] = tolower(tryAgain[i]);

			while (tryAgain != "yes" && tryAgain != "no") //invalid input
			{
				std::cout << "\nit's a yes or no question\n"
					      << "try again\n";
				std::cin >> tryAgain;
			}
			std::cout << std::endl;

			if (tryAgain == "no")
				foundName = true;
			else
				std::cout << "Enter another name: ";
		}//end of if statement

	}//end of while loop
}

//prints the top 25 teams in the console
void Standings::displayTopTeams(std::list<Team>& l)
{
	int display = 0; //only print the top 25 teams
	for (std::list<Team>::iterator i = l.begin(); i != l.end() && display < 25; i++)
	{
		std::cout << *i;
		std::cout << std::endl;
		display++;
	}
	std::cout << std::endl;
}

//prints all teams in the console
void Standings::displayAllTeams(std::list<Team>& l)
{
	for (std::list<Team>::iterator i = l.begin(); i != l.end(); i++)
	{
		std::cout << *i;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//saves teams info in a tsv file
void Standings::saveStanding(std::ostream& out, /*std::string& date*/ std::list<Team>& l)
{
	//today's date, correctly formatted
	//out << date << std::endl;

	for (std::list<Team>::iterator i = l.begin(); i != l.end(); i++)
		out << *i;
	out.flush();

	if (!out.good())
	{
		std::cout << "output failed!\n";
		exit(EXIT_FAILURE);
	}
	if (out.good())
	{
		std::cout << "Successfully saved in new file!\n";
	}
}

//takes a date from the user and output's it in a file
std::string Standings::Date()
{
	std::string dateInput, //today's date
		currentDay,
		currentMonth,
		currentYear;
	//std::string Month[] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
	int intDay = 0,
		intMonth = 0; //traverses the month array
	bool validDate = false; 

	std::cout << "Enter current date:\n"
		      << "Enter in the form of MMDDYYYY\n";
	do
	{
		std::cin >> dateInput;
		std::cout << std::endl;

		//validate user's input
		if (std::cin.peek() == ' ')
		{
			std::cout << "\nEmpty spaces are not allowed\n"
				      << "try again: ";
			dateInput.erase();
			continue;
		}
		else if (dateInput.size() < 8)
		{
			if (dateInput.size() <= 2)
				std::cout << "\nYou only entered the day\n"
				          << "try again: ";
			else if (dateInput.size() <= 4)
				std::cout << "\nYou forgot to enter the year\n"
				          << "try again\n";
			else
				std::cout << "\nThe year must be 4 integers\n"
				          << "try again\n";

			dateInput.erase();
			continue;
		}

		//taking the first two elements from user's input
	   //i.e the MM part
		currentMonth = dateInput.substr(0, 2); //start at index 0, take 2 elements as subtring
		currentDay = dateInput.substr(2, 2);   //start at index 2, take the next 2 elements as substring
		currentYear = dateInput.substr(4, 4);  //start at index 4, take the next 4 elements as substring



		//converts a string to int ("02" to 02)
	   // -1 accounts for zero-based indexing of an array
		intMonth = std::stoi(currentMonth);
		intDay = std::stoi(currentDay);

		 //if the user gave a valid day and a valid month,
		//get out of the loop
		if ((intDay >= 1 && intDay <= 31)
			&& (intMonth >= 1 && intMonth <= 12))
			validDate = true;
		else
		{
			std::cout << "\nInvalid month AND/OR day\n"
				      << "try again: ";
			//prepare the strings for subsequent inputs
			dateInput.erase();
			currentDay.erase();
			currentMonth.erase();
			currentYear.erase();

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	} while (!validDate);

	//today's date, correctly formatted
	std::string dateOutput = currentMonth + currentDay + currentYear;

	return dateOutput;
}

/*std::string Standings::getTeam() {
	std::string myTeam;
	//std::cout << "Enter the name of the team that you would like to remove\n";
	std::getline(std::cin, myTeam);
	return myTeam;
}
*/
//ensures that user's input is an int when needed
void Standings::validateInput(int input)
{
	while (std::cin.fail() || std::cin.peek() != '\n')
	{
		std::cout << "Ivalid input\n"
			<< input << "is not an integer\n"
			<< "try again: ";

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cin >> input;
		std::cout << std::endl;
	}
}