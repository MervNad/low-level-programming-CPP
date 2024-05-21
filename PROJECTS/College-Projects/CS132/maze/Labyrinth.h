/////////////////////////////////////////////////////////////////////////////////////////////
// File name         : Labyrinth.h
// This file contains the class defintion and its member functions defitions.
// Programmer        : Merveilles Katumba Biende
// Date created      : 4-22-2024
// Date last revised : 5-03-2024
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stack>
using namespace std;

class Labyrinth
{
protected:
    // Structure to represent coordinates in the maze
    struct Coordinates
    {
        int column;
        int row;

        // Overloaded inequality operator
        bool operator!=(Coordinates pos)
        {
            return (pos.column != this->column && pos.row != this->row);
        }

        // Overloaded equality operator
        bool operator==(Coordinates pos)
        {
            return (pos.column == this->column && pos.row == this->row);
        }
    };

public:
    // Constructor
    Labyrinth();

    // Destructor
    ~Labyrinth();

    // Function to retrieve the Labyrinth from a text file
    void loadMazeFromFile(istream& in);

    // Function to place the player in a position specified by the user
    void setPlayerPosition(int col, int row);

    // Function to guide the player out of the maze
    void traverseMaze();

    // Function to push positions that are North, West, South, and East of the player
    void pushAdjacentPositions();

    // Function to check if the player is trapped in a box
    bool isPlayerTrapped();

    // Function to change the appearance of the maze from 1's and 0's to a block and ' '
    void changeMazeAppearance();

    // Function to output the maze to the console screen
    void displayMaze();

    // Function to clear the path for new input
    void clearMazePath();

    // Function to open a file stream for reading the maze file provided by the user.
    void openFile(std::ifstream& in);

    // Function to validate the user's choice to ensure it is within the acceptable range.
    int validate(int choice);

    // Function to display a menu of options for the user to choose from.
    void displayMenu();

private:
    char mazeLayout[12][12];
    char playerCharacter;
    Coordinates playerPosition;
    Coordinates exitPosition;
    stack<Coordinates> adjacentPositions;
};

#endif

