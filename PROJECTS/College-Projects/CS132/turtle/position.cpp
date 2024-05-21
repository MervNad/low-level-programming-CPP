

/////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : position.cpp
//
// This file is the implementation for the position class used by the turtle class
//
// Programmer        : B.J. Streller AND Merveilles Katumba Biende
//
// Date created      : 2/29/2024
//
// Date last revised : 2/29/2024
//
/////////////////////////////////////////////////////////////////////////////////////////////



#include<iostream>
#include <iomanip>
#include "position.h"
using namespace std;

const char turtleChar = char(232);                           //turtle character
char brushChar = char(249);                                 //brush/trail character



/////////////////////////////////// Position() //////////////////////////////////////////////
//
// function name      : Position()
//
// purpose            : constructor for the class; creates the floor and places turtle at (0,0)
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


Position::Position() : floor{}                                    //create a 20 x 20 floor
//with turtle at (0,0)
{
	cout << " My starting position is at row 0 and column 0" << endl;

	/*
	   used to make sure that:
	   1. the floor doesn't get cleared every time a Position object is created
	   2. the turtle's position doesn't get reset every time a position object is creatred
	*/
	static int EmptyFloor = 0;
	if (EmptyFloor < 1)
	{
		//printing the game screen [change in y][change in x]
		for (int y = 0; y < 20; y++)
			for (int x = 0; x < 20; x++)
			{
				if (x == 0 && y == 0)
					floor[y][x] = static_cast<char>(218); //top left corner

				else if (x == 19 && y == 0)
					floor[y][x] = static_cast<char>(191); //top right corner

				else if (x == 0 && y == 19)
					floor[y][x] = static_cast<char>(192); //bottom left corner

				else if (x == 19 && y == 19)
					floor[y][x] = static_cast<char>(217); //bottom right corner

				else if (x >= 1 && x <= 18 && (y == 0 || y == 19))
					floor[y][x] = static_cast<char>(196); //ceiling and floor

				else if (y >= 1 && y <= 18 && (x == 0 || x == 19))
					floor[y][x] = static_cast<char>(179); //walls
				else
					floor[y][x] = ' '; //making the content of the floor empty
			}

		floor[1][1] = static_cast<char>(232); //turtle
	}

	EmptyFloor++;
}


/////////////////////////////////// ~Position() /////////////////////////////////////////////
//
// function name      : ~Position()
//
// purpose            : class destructor
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


Position::~Position()
{}


/////////////////////////////////// resetPosition() /////////////////////////////////////////
//
// function name      : resetPosition()
//
// purpose            : return to initial state of clear floor with turtle at (0,0)
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Position::resetPosition()								//create a new 'clean' floor
{
	cout << " I'm back at my starting position of row 0 and column 0" << endl;

	for (int y = 0; y < 20; y++)
		for (int x = 0; x < 20; x++)
		{
			if (x == 0 && y == 0)
				floor[y][x] = static_cast<char>(218); //top left corner

			else if (x == 19 && y == 0)
				floor[y][x] = static_cast<char>(191); //top right corner

			else if (x == 0 && y == 19)
				floor[y][x] = static_cast<char>(192); //bottom left corner

			else if (x == 19 && y == 19)
				floor[y][x] = static_cast<char>(217); //bottom right corner

			else if (x >= 1 && x <= 18 && (y == 0 || y == 19))
				floor[y][x] = static_cast<char>(196); //ceiling and floor

			else if (y >= 1 && y <= 18 && (x == 0 || x == 19))
				floor[y][x] = static_cast<char>(179); //walls
			else
				floor[y][x] = ' '; //making the content of the floor empty
		}

	floor[1][1] = static_cast<char>(232); //turtle
}


/////////////////////////////////// print() /////////////////////////////////////////////////
//
// function name      : print()
//
// purpose            : prints the floor( and anything else that has been put on the floor )
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Position::print() const								//print current floor
{
	for (int y = 0; y < 20; y++)
	{
		cout << right << setw(20); //pushing the floor 20 spaces to the right
		for (int x = 0; x < 20; x++)
			cout << floor[y][x];

		cout << endl;
	}
}


/////////////////////////////////// getCurrentRowPosition() /////////////////////////////////
//
// function name      : getCurrentRowPosition()
//
// purpose            : finds the row where the turtle currently is
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : itemp  which is an int
//
/////////////////////////////////////////////////////////////////////////////////////////////


int Position::getCurrentRowPosition() const                 //finds the current row of turtle
{
	for (int y = 1; y < 20; y++)
		for (int x = 1; x < 20; x++)
		{
			if (floor[y][x] == static_cast<char>(232))
				return y; //return current row
		}

	//Could not find the current row position
	return 1;
}


/////////////////////////////////// getCurrentColPosition() /////////////////////////////////
//
// function name      : getCurrentColPosition()
//
// purpose            : finds the column where the turtle currently is
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : jtemp which is an int type
//
/////////////////////////////////////////////////////////////////////////////////////////////


int Position::getCurrentColPosition() const            //finds the current column of turtle
{
	for (int y = 1; y < 20; y++)
		for (int x = 1; x < 20; x++)
		{
			if (floor[y][x] == static_cast<char>(232))
				return x; //return current column
		}

	//Could not find the current column position
	return 1;
}


/////////////////////////////////// setRowPosition(int row) /////////////////////////////////
//
// function name      : setRowPosition(int row)
//
// purpose            : place turtle in the correct row
//
// input parameters   : row an int type
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Position::setRowPosition(int row)					   //places turtle in correct row
{
	int currentCol = getCurrentColPosition(),
		currentRow = getCurrentRowPosition();

	floor[currentRow][currentCol] = ' '; //clearing the turtle's previous location

	//preventing the user from getting inside the walls
	if (row > 18)
	{
		std::cout << " I have reached a dead end\n";
		row = 18;
	}

	else if (row < 1)
	{
		std::cout << " I have reached a dead end\n";
		row = 1;
	}

	//moving the turtle to the desired coordinates
	floor[row][currentCol] = static_cast<char>(232);
}


/////////////////////////////////// setColPosition(int col) /////////////////////////////////
//
// function name      : setColPosition(int col)
//
// purpose            : place turtle in correct column
//
// input parameters   : col an int type
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Position::setColPosition(int col)					   //places turtle in correct col
{
	int currentCol = getCurrentColPosition(),
		currentRow = getCurrentRowPosition();

	floor[currentRow][currentCol] = ' '; //clearing the turtle's previous location

	//preventing the user from getting inside the walls
	if (col > 18)
	{
		std::cout << " I have reached a dead end\n";
		col = 18;
	}

	else if (col < 1)
	{
		std::cout << " I have reached a dead end\n";
		col = 1;
	}

	//moving the turtle to the desired coordinates
	floor[currentRow][col] = static_cast<char>(232);
}


/////////////////////////////////// setPosition(int row, int col) ///////////////////////////
//
// function name      : setPosition(int row, int col)
//
// purpose            : places the turtle in the correct position
//
// input parameters   : two, row and col both of type int
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Position::setPosition(int row, int col)	    //place turtle in correct position
{
	int currentRow = getCurrentRowPosition(),
		currentCol = getCurrentColPosition();

	/*
	   because arrays use zero-based indexing,
	   the turtle will jump row - 1, col - 1.
	   to fix that, I added 1 to the row and col
	*/
	row += 1;
	col += 1;

	floor[currentRow][currentCol] = ' '; //clearing the turtle's previous location

	//moving the turtle to the desired coordinates
	floor[row][col] = static_cast<char>(232);
}


/////////////////////////////////// getCurrentPosition() ////////////////////////////////////
//
// function name      : getCurrentPosition()
//
// purpose            : finds the current position of the turtle to output to the screen
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Position::getCurrentPosition() const
{
	//the -1 adjusts to zero-based indexing for user display
	cout << "\n My current position is row " << getCurrentRowPosition() - 1
		<< " and column " << getCurrentColPosition() - 1 << endl;
}


/////////////////////////////////// getRowTrail(int col) ////////////////////////////////////
//
// function name      : getRowTrail(int col)
//
// purpose            : places trail char in the column where turtle was
//
// input parameters   : col an int
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Position::getRowTrail(int col)						   //place trail after turtle
{
	int currentRow = getCurrentRowPosition(),
		currentCol = getCurrentColPosition();

	floor[currentRow][currentCol] = brushChar; //printing trail behind the turtle

	//preventing the user from getting inside the walls
	if (col > 18)
	{
		cout << " I have reached a dead end\n";
		col = 18;
	}

	else if (col < 1)
	{
		cout << " I have reached a dead end\n";
		col = 1;
	}

	//moving the turtle to the desired coordinates
   //and adding 1 to row to account for zero-based indexing
	floor[currentRow][col + 1] = static_cast<char>(232);
}


/////////////////////////////////// getColTrail( int row) ///////////////////////////////////
//
// function name      : getColTrail( int row)
//
// purpose            : places trail char in the row where turtle was
//
// input parameters   : row an int type
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Position::getColTrail(int row)						   //place trail after turtle
{
	int currentRow = getCurrentRowPosition(),
		currentCol = getCurrentColPosition();

	floor[currentRow][currentCol] = brushChar; //printing trail behind the turtle

	//preventing the user from getting inside the walls
	if (row > 18)
	{
		cout << " I have reached a dead end\n";
		row = 18;
	}

	else if (row < 1)
	{
		cout << " I have reached a dead end\n";
		row = 1;
	}

	//moving the turtle to the desired coordinates
   //and adding 1 to row to account for zero-based indexing
	floor[row + 1][currentCol] = static_cast<char>(232);
}


/////////////////////////////////// changeTrail() ///////////////////////////////////////////
//
// function name      : changeTrail()
//
// purpose            : changes the character available for the trail
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Position::changeTrail()								//change trail pattern
{
	int choice = 0;

	cout << " The following options are available for you to choose from:"
		<< "\n 1. " << static_cast<char>(3) //heart suit
		<< "\n 2. " << static_cast<char>(4) //diamond suit
		<< "\n 3. " << static_cast<char>(5) //club suit
		<< "\n 4. " << static_cast<char>(14) //eighth note
		<< "\n 5. " << static_cast<char>(249) << " (default brush)\n"
		<< "\n Please enter a number to select a brush stroke: ";
	std::cin >> choice;

	//change the brush based on user's choice
	switch (choice)
	{
	case 1:
		brushChar = static_cast<char>(3);
		break;
	case 2:
		brushChar = static_cast<char>(4);
		break;
	case 3:
		brushChar = static_cast<char>(5);
		break;
	case 4:
		brushChar = static_cast<char>(14);
		break;
	case 5:
		brushChar = static_cast<char>(249);
		break;
	default:
		cout << " Invalid input, "
			<< choice
			<< " is currently out of stock\n";
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////




