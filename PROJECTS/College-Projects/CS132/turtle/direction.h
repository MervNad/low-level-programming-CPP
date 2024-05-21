
/////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : direction.h
//
// This is the header file for the direction class direction.cpp which is used by turtle.cpp
//
// Programmer        : B.J. Streller
//
// Date created      :
//
// Date last revised :
//
/////////////////////////////////////////////////////////////////////////////////////////////



#ifndef DIRECTION_H
#define DIRECTION_H




class Direction
{
private:
    char heading;                                               //direction variable

public:
    Direction();                                                //constructor
    ~Direction();                                               //destructor
    char getHeading() const;
    void setTurnLeftHeading(char c);                            //new heading after turn
    void setTurnRightHeading(char c);                           //new heading after turn
    void resetDirection();                                      //return to default heading
};



#endif

