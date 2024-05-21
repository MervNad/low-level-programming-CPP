
/////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : postion.h
//
// This is the header file for the postion class position.cpp which is used by turtle.cpp
//
// Programmer        : B.J. Streller
//
// Date created      :
//
// Date last revised :
//
/////////////////////////////////////////////////////////////////////////////////////////////




#ifndef POSITION_H
#define POSITION_H



class Position
{
private:

    char floor[20][20];                                                  //floor

public:

    Position();                                                          //constructor
    ~Position();                                                         //destructor
    int  getCurrentRowPosition() const;
    int  getCurrentColPosition() const;
    void getCurrentPosition() const;
    void setRowPosition(int row);
    void setColPosition(int col);
    void setPosition(int row, int col);
    void getRowTrail(int col);
    void getColTrail(int row);
    void changeTrail();
    void resetPosition();
    void print() const;
};



#endif