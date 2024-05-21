
/////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : turtle.h
//
// This is the header file for the turtle class
//
// Programmer        : B.J. Streller
//
// Date created      :
//
// Date last revised :
//
/////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TURTLE_H
#define TURTLE_H

#include "position.h"
#include "direction.h"





class Turtle
{
private:
    Position  myPosition;                                       //position object
    Direction myHeading;                                        //direction object
    bool penUp;                                                 //state of pen


public:
    Turtle(bool pen);                                           //constructor
    ~Turtle();                                                  //destructor
    void jump();
    void forward();
    void turn();
    void changePenStatus();
    void changeBrush();
    void turtleStatus();
    void erase();
    void print() const;
};


#endif