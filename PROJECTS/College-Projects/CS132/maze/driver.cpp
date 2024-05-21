/////////////////////////////////////////////////////////////////////////////////////////////
// File name         : driver.cpp
// This file contains the program flow of execution.
// Programmer        : Merveilles Katumba Biende
// Date created      : 4-22-2024
// Date last revised : 5-03-2024
/////////////////////////////////////////////////////////////////////////////////////////////

#include "Labyrinth.h"
/////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: main
// Purpose: Entry point of the program, manages the main game loop and user interactions.
// Input Parameters: None.
// Output Parameters: None.
// Return Value: Integer indicating the exit status of the program.
/////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    // Function implementation
    ifstream inFile;
    Labyrinth labyrinth;
    int col = 0,
        row = 0,
        option = 0,
        valid = 0
        ;
    bool Recplay = true;

    cout << "Welcome to the Maze Game!\n";
    // Open the maze file
    cout << "\nEnter labyrinth file: ";
    labyrinth.openFile(inFile);
    labyrinth.loadMazeFromFile(inFile);
    while (Recplay)
    {
        // Ask the user for starting position
        cout << "Enter current coordinates: \n";
        cout << "Enter the row: ";
        cin >> row;
        cout << "Enter the column: ";
        cin >> col;
        cout << '\n';

        // Insert player into maze
        labyrinth.setPlayerPosition(col, row);
        // Traverse the maze
        labyrinth.traverseMaze();
        // Print the maze
        labyrinth.displayMaze();
        // Display menu and get user choice
        labyrinth.displayMenu();
        
        valid = labyrinth.validate(option);

        switch (valid)
        {
        case 2:
            // Play with a different maze
            inFile.close();
            cout << "Enter the new labyrinth file: ";
            labyrinth.openFile(inFile);
            break;
        case 3:
            // Exit the program
            cout << "Exiting the program.\n";
            return 0;
        }
    }

    return 0;
}
