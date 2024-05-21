

/////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : direction.cpp
//
// This file is the implementation file for the direction class which is used by
// the turtle class
//
// Programmer        : B.J. Streller AND Merveilles Katumba Biende
//
// Date created      : 2/29/2024
//
// Date last revised : 2/29/2024
//
/////////////////////////////////////////////////////////////////////////////////////////////



#include<iostream>
#include "direction.h"
using namespace std;

/////////////////////////////////// Direction() //////////////////////////////////////////////
//
// function name      : Direction()
//
// purpose            : class constructor initializes the heading to the default direction
//                      of east
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


Direction::Direction()                                           //constructor
{
    static int initHeading = 0;

    cout << " Direction headings are: E for east, W for west, N for north and S for south\n";

    //making sure that the floor does not get reset to E everytime the constructor is used
    if (initHeading < 1)
    {
        cout << " My starting direction is East" << endl;
        heading = 'E';
    }
    else
        cout << " I am currently heading " << getHeading() << endl;

    initHeading++;
}


/////////////////////////////////// ~Direction() ////////////////////////////////////////////
//
// function name      : ~Destructor()
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


Direction::~Direction()										//destructor
{}


/////////////////////////////////// resetDirection() ////////////////////////////////////////
//
// function name      : resetDirection()
//
// purpose            : sets the direction to the default direction of E for east
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Direction::resetDirection()
{
    heading = 'E';
}


/////////////////////////////////// getHeading() ////////////////////////////////////////////
//
// function name      : getHeading()
//
// purpose            : return the heading direction
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


char Direction::getHeading() const
{
    return heading;
}


/////////////////////////////////// setTurnLeftHeading(char) ////////////////////////////////
//
// function name      : setTurnLeftHeading
//
// purpose            : given an input heading, determine the new heading after turning left
//
// input parameters   : the current heading char c
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Direction::setTurnLeftHeading(char c)					//calculates new heading
{
    switch (c)
    {
    case 'E':
        std::cout << " I am now heading North\n";
        heading = 'N';
        break;

    case 'N':
        std::cout << " I am now heading West\n";
        heading = 'W';
        break;

    case 'W':
        std::cout << " I am now heading South\n";
        heading = 'S';
        break;

    case 'S':
        std::cout << " I am now heading East\n";
        heading = 'E';
    }
}


/////////////////////////////////// setTurnRightHeading(char) ///////////////////////////////
//
// function name      : setTurnRightHeading
//
// purpose            : given an input heading, determine the new heading after turning right
//
// input parameters   : the current heading char c
//
// output parameters  : none
//
// return value       : none
//
/////////////////////////////////////////////////////////////////////////////////////////////


void Direction::setTurnRightHeading(char c)                 //calculates new heading
{
    switch (c)
    {
    case 'E':
        cout << " I am now heading South\n";
        heading = 'S';
        break;

    case 'S':
        cout << " I am now heading West\n";
        heading = 'W';
        break;

    case 'W':
        cout << " I am now heading North\n";
        heading = 'N';
        break;

    case 'N':
        cout << " I am now heading East\n";
        heading = 'E';
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////