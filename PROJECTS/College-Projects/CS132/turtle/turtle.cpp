
/////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : turtle.cpp
//
// This is the implementation for the turtle class
//
// Programmer        : B.J. Streller AND Merveilles Katumba Biende
//
// Date created      : 2/29/2024
//
// Date last revised : 2/29/2024
//
/////////////////////////////////////////////////////////////////////////////////////////////



#include<iostream>
#include "turtle.h"
using namespace std;


/////////////////////////////////// Turtle()  ///////////////////////////////////////////////
//
// function name      : Turtle()
//
// purpose            : This is the class Turtle constructor
//
// input parameters   : a boolean called pen
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


Turtle::Turtle(bool pen)
{
    penUp = pen;
}


/////////////////////////////////// ~Turtle() ///////////////////////////////////////////////
//
// function name      : ~Turtle()
//
// purpose            : The class destructor
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


Turtle::~Turtle()
{}


/////////////////////////////////// erase() /////////////////////////////////////////////////
//
// function name      : erase()
//
// purpose            : clears the floor of any characters;i.e.returns floor to initial state
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Turtle::erase()
{
    myPosition.resetPosition();
}


/////////////////////////////////// ChangePenStatus() ///////////////////////////////////////
//
// function name      : changePenStatus()
//
// purpose            : changes the boolean pen from up to down and vice versa for printing
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Turtle::changePenStatus()								//changes the pen status
{
    if (penUp == true)
    {
        cout << " My pen is now down\n";
        penUp = false;
    }
    else
    {
        cout << " My pen is now up\n";
        penUp = true;
    }
}


/////////////////////////////////// jump()///////////////////////////////////////////////////
//
// function name      : jump()
//
// purpose            : "jumps" the turtle to any position on the floor
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Turtle::jump()
{
    //user's input
    int row = 0,
        column = 0,
        //current coordinates of the turtle
        currentRow = myPosition.getCurrentRowPosition(),
        currentCol = myPosition.getCurrentColPosition();

    cout << " My heading is still " << myHeading.getHeading() << endl;

    cout << " Where would you like me to jump?"
        << "\n Please enter the row: ";
    cin >> row;

    cout << " Please enter the column: ";
    cin >> column;


    ////////////////////////*input validation*////////////////////////

     //if the user makes a mistake, get them out of the function
    //to allow them to try again, or make another choice

    if (!cin) //non-numeric input
    {
        cout << " Invalid input, ("
            << row << ',' << column
            << ") is not a valid coordinate\n";

        cin.clear();
        cin.ignore(100000, '\n');

        turtleStatus();
        return;
    }

    //the user attempted to jump out of bounds
   //the condition account for zero-based indexing
    else if (row < 0 || column < 0 || row > 17 or column > 17)
    {
        cout << " I am not allowed to jump out of bounds\n";
        turtleStatus();
        return;
    }

    //////////////////////////////////////////////////////////////////

    //if the pen is down, print a trail in the current location of the turtle
    if (!penUp)
        myPosition.getColTrail(row);

    //making the turtle jump to the desired coordinates
    myPosition.setPosition(row, column);

    turtleStatus();
}


/////////////////////////////////// forward() ///////////////////////////////////////////////
//
// function name      : forward()
//
// purpose            : moves the turtle forward a given num of places
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Turtle::forward()										//moves turtle to user choice
{
    //change row or col based on current heading

    //user's input
    int stepsTaken = 0,
        //current coordinates and heading of the turtle
        currentRow = myPosition.getCurrentRowPosition(),
        currentCol = myPosition.getCurrentColPosition();
    char headingTo = myHeading.getHeading();


    cout << " How many steps forward should I take? ";
    cin >> stepsTaken;

    ////////////////////////////*input validation*////////////////////////////////

     //if the user makes a mistake, get them out of the function
    //to allow them to try again, or make another choice

    if (!cin) //non-numeric input
    {
        cout << " Invalid input, "
            << stepsTaken
            << " is not a valid number of steps\n";

        cin.clear();
        cin.ignore(100000, '\n');

        turtleStatus();
        return;
    }
    else if (stepsTaken < 0) //the user attempted to walk backwards
    {
        cout << " I cannot walk backwards without changing my direction\n";
        turtleStatus();
        return;
    }

    //////////////////////////////////////////////////////////////////////////////


    switch (headingTo)
    {
    case 'E':
        for (int x = currentCol; x < currentCol + stepsTaken; x++)
        {
            //if the turtle's pen is down, print a trail behind it
            if (!penUp)
                myPosition.getRowTrail(x);
            else
            {
                myPosition.setColPosition(currentCol + stepsTaken); //move the turtle x steps to the right
                break; //break out of the loop after the turtle has been moved
            }
        }
        break; //break out of case 'E'

    case 'W':
        for (int x = currentCol; x > currentCol - stepsTaken; x--)
        {
            if (!penUp)
                myPosition.getRowTrail(x);
            else
            {
                myPosition.setColPosition(currentCol - stepsTaken); //move the turtle x steps to the left
                break;
            }
        }
        break;

    case 'N':
        for (int y = currentRow; y > currentRow - stepsTaken; y--)
        {
            if (!penUp)
                myPosition.getColTrail(y);
            else
            {
                myPosition.setRowPosition(currentRow - stepsTaken); //move the turtle y steps to upwards
                break;
            }
        }
        break;

    case 'S':
        for (int y = currentRow; y < currentRow + stepsTaken; y++)
        {
            if (!penUp)
                myPosition.getColTrail(y);
            else
            {
                myPosition.setRowPosition(currentRow + stepsTaken); //move the turtle y steps to downwards
                break;
            }
        }
    } //end of switch statement

    turtleStatus();
}


/////////////////////////////////// turn() //////////////////////////////////////////////////
//
// function name      : turn()
//
// purpose            : repositions the turtle head either left or right from its 
//						current heading
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Turtle::turn()											//turn either left or right
{
    char turning, //user's input
        pointingTo = myHeading.getHeading();

    cout << " Would you like to turn left or right?"
        << " I am currently heading: " << pointingTo
        << "\n Enter \"r\" for right or \"l\" for left: ";
    cin >> turning;

    turning = tolower(turning); //taking into account upper case r and l


     //calculate' the turtle's new heading 
    //based on the direction provided by the user
    switch (turning)
    {
    case 'l':
        myHeading.setTurnLeftHeading(pointingTo);
        break;

    case 'r':
        myHeading.setTurnRightHeading(pointingTo);
        break;

    default:
        std::cout << " Invalid input, "
            << turning << " is not a direction\n";
    }
}


/////////////////////////////////// changeBrush() ///////////////////////////////////////////
//
// function name      : changeBrush()
//
// purpose            : changes the brush or trail character
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Turtle::changeBrush()									//change trail character
{
    myPosition.changeTrail();
}


/////////////////////////////////// turtleStatus() //////////////////////////////////////////
//
// function name      : turtleStatus()
//
// purpose            : informs the user of the position, heading and pen postion of the turtle
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Turtle::turtleStatus()									//informs of current status
{
    myPosition.getCurrentPosition(); //current location of the turtle
    cout << " I am currently heading is: " << myHeading.getHeading()
        << "\n And my pen is ";
    //current pen status
    if (penUp)
        cout << "up\n";
    else
        cout << "down\n";
}


/////////////////////////////////// print() /////////////////////////////////////////////////
//
// function name      : print()
//
// purpose            : print the floor, the turtle's position and any trail it left behind
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Turtle::print() const									//prints the floor and turtle
{
    myPosition.print();
}

/////////////////////////////////////////////////////////////////////////////////////////////