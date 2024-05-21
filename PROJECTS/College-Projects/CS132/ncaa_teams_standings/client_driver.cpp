/////////////////////////////////  client_driver.cpp  ///////////////////////
//
// File name         : client_driver.cpp
//
// Description: The client_driver.cpp file is a C++ source file
//				responsible for implementing the driver program that manages NCAA team standings.
//				It includes functionalities for adding, removing, editing,
//				and displaying team information, as well as saving changes to a file.
//				The program interacts with the Standings class
//				and its associated member functions defined in other files.
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


#include <iostream>
#include <fstream>
#include "Standings.h"
#include <string>

void openFile(std::ifstream& in); //receive a file from user, open and read
void Validate(int& choice); //ensures that user's choice is an int

int main()
{
	std::ifstream inFile; //handle for input file(read)
	std::ofstream outFile; //handle for output file(write)
	std::string fileName; //name of the output file

	Standings info; //info of teams
	std::list<Team> AllTeams; //list of all teams
	Team aTeam; //a single team
	int choice = 0; // user's choice of action, initialised to 0
	std::string ToRemove, //name of the a team with 0 vote
		        date; //today's date, taken from the user

	//get info from file
	openFile(inFile);
	info.retrieve_Standing(inFile, AllTeams);

	std::cout << "What would you like to do?"
		      << "\n\t1. add a new team to the list?"
		      << "\n\t2. remove a team from the list?"
		      << "\n\t3. edit the information of a team?"
		      << "\n\t4. print the top 25 teams to the screen?"
		      << "\n\t5. print all teams to the screen?"
		      << "\n\t6. save changes in a new file?"
		      << "\n\t7. exit the program"
		      << std::endl;

	std::cin >> choice;
	Validate(choice);

	bool ExitProgram = false;

	while (!ExitProgram)
	{
		switch (choice)
		{
		case 1: //add a team to the list
			info.addTeam(AllTeams, aTeam);
			break;

		case 2: //remove a team from the list			
			info.removeTeam(AllTeams, ToRemove);
			break;

		case 3: //edit a team's info
			info.editTeam(AllTeams, aTeam);
			break;

		case 4: //display top 25 teams
			info.displayTopTeams(AllTeams);
			break;

		case 5: //display all teams
			info.displayAllTeams(AllTeams);
			break;

		case 6: //save teams in a new list
			date = info.Date(); //today's date, correctly formatted

			fileName = "ncaa_standings_" + date + ".tsv";
			outFile.open(fileName, std::ios::trunc);

			info.saveStanding(outFile, /*date,*/ AllTeams);
			outFile.close();
			break;

		case 7: //the user wants to leave the program
			ExitProgram = true;
		}

		if (!ExitProgram)
		{
			std::cout << "What else would you like to do?"
				      << "\n\t1. add a new team to the list?"
				      << "\n\t2. remove a team from the list?"
				      << "\n\t3. edit the information of a team?"
				      << "\n\t4. print the top 25 teams to the screen?"
				      << "\n\t5. print all teams to the screen?"
				      << "\n\t6. save changes in a new file?"
				      << "\n\t7. exit the program"
				      << std::endl;

			std::cin >> choice;
			Validate(choice);
		}
	}

	inFile.close();
	outFile.close();

	return 0;
}

//takes a file's name or its path from the user
void openFile(std::ifstream& in)
{
	std::string fPath; //user specified file
	std::cout << "Please Enter filename (i.e. including the path): ";
	std::cin >> fPath;

	in.open(fPath);

	while (!in.good() || !in.is_open()) //input validation
	{
		std::cout << "The file was not found, try again\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cin >> fPath;
		in.open(fPath);
	}
	std::cout << std::endl;
}

//ensures that user's choice is an int
void Validate(int& choice)
{
	while (choice < 1 || choice > 7 || std::cin.fail() || std::cin.peek() != '\n')
	{
		std::cout << "\nInvalid!\n"
			      << choice << " is not an option\n"
			      << "try again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cin >> choice;
	}
	std::cout << std::endl;
}