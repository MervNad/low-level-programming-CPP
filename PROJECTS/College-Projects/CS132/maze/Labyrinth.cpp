/////////////////////////////////////////////////////////////////////////////////////////////
// File name         : Labyrinth.cpp
// This file contains the implementation of the class Labyrinth and its member functions.
// Programmer        : Merveilles Katumba Biende
// Date created      : 4-22-2024
// Date last revised : 5-03-2024
/////////////////////////////////////////////////////////////////////////////////////////////

#include "Labyrinth.h"

/////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: openFile
// Purpose: Opens a file stream for reading the maze file provided by the user.
// Input Parameters: Reference to an ifstream object.
// Output Parameters: None.
// Return Value: None.
/////////////////////////////////////////////////////////////////////////////////////////////

void Labyrinth::openFile(ifstream& in) {
    // Function implementation
    string fName;

    while (true)
    {
        cin >> std::ws; // Consume any leading white space
        getline(cin, fName);

        // Attempt to open the file
        in.open(fName);
        if (!in.good() || !in.is_open())
            cout << "\nCould not open the file. Please try again.\n";
        else
            break;
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: validate
// Purpose: Validates the user's choice to ensure it is within the acceptable range.
// Input Parameters: Integer representing the user's choice.
// Output Parameters: None.
// Return Value: None.
/////////////////////////////////////////////////////////////////////////////////////////////

int Labyrinth::validate(int choice) {
    // Function implementation
   choice = 0;
   cout << "Enter your choice: ";
   cin >> choice;
    while (!(choice <= 3 && choice >= 1) || !cin.good() || cin.peek() != '\n')
    {
        cout << "Invalid choice! Please enter a number between 1 and 3: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> choice;
        cout << std::endl;
    }
    return choice;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: displayMenu
// Purpose: Displays a menu of options for the user to choose from.
// Input Parameters: None.
// Output Parameters: None.
// Return Value: None.
/////////////////////////////////////////////////////////////////////////////////////////////

void Labyrinth::displayMenu() {
    // Function implementation
    std::cout << "\n====== MENU ======\n"
        << "1. Restart the game\n"
        << "2. Play with a different maze\n"
        << "3. Exit the program\n"
        << "==================\n"
        << "Enter your choice: ";
}


/////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Maze::Maze
// Purpose: Constructor for the Maze class, initializes member variables.
// Input Parameters: None.
// Output Parameters: None.
// Return Value: None.
/////////////////////////////////////////////////////////////////////////////////////////////

Labyrinth::Labyrinth() : mazeLayout{} {
    playerCharacter = static_cast<char>(175); // Set player character
    playerPosition = { 0, 0 }; // Set initial player position
    exitPosition = { 0, 0 }; // Set initial exit position
}

/////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Maze::~Maze
// Purpose: Destructor for the Maze class.
// Input Parameters: None.
// Output Parameters: None.
// Return Value: None.
/////////////////////////////////////////////////////////////////////////////////////////////

Labyrinth::~Labyrinth() {
    // Destructor implementation
}


/////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Maze::loadMazeFromFile
// Purpose: Reads maze data from the input stream and stores it in the maze grid array.
// Input Parameters: std::istream& in - Reference to the input stream from which maze data is read.
// Output Parameters: None.
// Return Value: None.
/////////////////////////////////////////////////////////////////////////////////////////////

void Labyrinth::loadMazeFromFile(istream& in) {
    for (int col = 0; col < 12; col++) {
        for (int row = 0; row < 12; row++) {
            if (row == 0 || row == 11) { // Ceiling and floor
                mazeLayout[col][row] = '1';
            }
            else if (col == 0 || col == 11) {
                mazeLayout[col][row] = '1';
            }
            else { // Maze cells
                in >> mazeLayout[col][row];
                if (mazeLayout[col][row] == 'E') {
                    exitPosition = { col, row }; // Record exit position
                }
            }
        }
    }
}



/////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Maze::insertPlayer
// Purpose: Inserts the player character into the maze grid at the specified position.
//          Handles user input to select a valid starting position for the player.
// Input Parameters: int col - The column index where the player will be inserted.
//                   int row - The row index where the player will be inserted.
// Output Parameters: None.
// Return Value: None.
/////////////////////////////////////////////////////////////////////////////////////////////

void Labyrinth::setPlayerPosition(int col, int row) {
    bool inserted = false; // Flag to track whether the player was successfully inserted

    // Continue until the player is successfully inserted
    while (true) {
        // Check if the provided coordinates are within the bounds of the maze
        if ((col >= 0 && col <= 11) && (row >= 0 && row <= 11)) {
            switch (mazeLayout[col][row]) {
            case '1': // Wall
                std::cout << "\nYou cannot start here, because there is a wall\n";
                break;
            case '0': // Clear path
                mazeLayout[col][row] = playerCharacter; // Insert the player into the maze
                playerPosition = { col, row }; // Store player's position
                inserted = true;
                break;
            case 'E': // Exit
                std::cout << "\nCongratulations!!!\n"
                    << "You have found the gate to success!\n";

                mazeLayout[col][row - 1] = playerCharacter; // Insert the player before the exit
                //playerPosition = { col, row - 1 }; // Store player's position
                inserted = true;
            }
        }
        else { // Invalid coordinates
            std::cout << "\nRow: " << row
                << ", Column: " << col
                << " is not a valid position!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // If player is successfully inserted, exit the loop
        if (inserted) {
            break;
        }
        else { // Ask for new coordinates
            std::cout << "\nEnter your starting position:\n"
                << "Enter a new row: ";
            std::cin >> row;

            std::cout << "Enter a new column: ";
            std::cin >> col;
            std::cout << '\n';
        }
    } // End of while loop
}


/////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Maze::trapped
// Purpose: Checks if the player is trapped in the maze by examining the surrounding cells.
// Input Parameters: None.
// Output Parameters: None.
// Return Value: bool - true if the player is trapped, false otherwise.
/////////////////////////////////////////////////////////////////////////////////////////////

bool Labyrinth::isPlayerTrapped() {
    // Check if the neighboring cells are blocked or visited
    return ((mazeLayout[playerPosition.column - 1][playerPosition.row] == '*' || mazeLayout[playerPosition.column - 1][playerPosition.row] == '1') && // North is blocked
        (mazeLayout[playerPosition.column][playerPosition.row -1] == '*' || mazeLayout[playerPosition.column][playerPosition.row - 1] == '1') && // West is blocked
        (mazeLayout[playerPosition.column + 1][playerPosition.row] == '*' || mazeLayout[playerPosition.column + 1][playerPosition.row] == '1') && // South is blocked
        (mazeLayout[playerPosition.column][playerPosition.row + 1] == '*' || mazeLayout[playerPosition.column][playerPosition.row + 1] == '1')); // East is blocked
}

/////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Maze::traverseMaze
// Purpose: Guides the player through the maze until they reach the exit or get trapped.
// Input Parameters: None.
// Output Parameters: None.
// Return Value: None.
/////////////////////////////////////////////////////////////////////////////////////////////

void Labyrinth::traverseMaze() {
    Coordinates startPos = playerPosition; // Save the starting position
    //stack<Coordinates> visisted;
    adjacentPositions.push(playerPosition); // Push the starting position onto the stack
    //mazeLayout[startPos.column][startPos.row] = '!'; // Marking the start

    while (!adjacentPositions.empty()) {
        adjacentPositions.pop(); // Clear the stack

        // Mark the start position
        if (startPos == playerPosition) {
            mazeLayout[startPos.column][startPos.row] = static_cast<char>(167); // Marking the start
        }
        else {
            mazeLayout[playerPosition.column][playerPosition.row] = '*'; // Mark as visited
        }

        pushAdjacentPositions(); // Push positions surrounding the player onto the stack

        // Update player's position to the top of the stack
        if (!adjacentPositions.empty()) {
            playerPosition = adjacentPositions.top();
        }
        // Check if the player is trapped in a box
        if (playerPosition == startPos && isPlayerTrapped() && adjacentPositions.empty()) {
            std::cout << "\nFREE ME!, I'M IN PRISON!\n";
            mazeLayout[playerPosition.column][playerPosition.row] = playerCharacter; // Restore player position

            while (!adjacentPositions.empty()) {
                adjacentPositions.pop(); // Clear the stack
            }
        }
        else if (playerPosition == exitPosition) { // Player found the exit
            std::cout << "\nI HOORAY LIBERTY! I AM FREE!!!\n";

            while (!adjacentPositions.empty()) {
                adjacentPositions.pop(); // Clear the stack
            }
        }
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Maze::pushSurrounds
// Purpose: Pushes neighboring positions onto the stack if they are not walls or already visited.
// Input Parameters: None.
// Output Parameters: None.
// Return Value: None.
/////////////////////////////////////////////////////////////////////////////////////////////

void Labyrinth::pushAdjacentPositions() {
    Coordinates newPosition = playerPosition; // Start at the player's position

    // Check and push neighboring positions if they are not walls or already visited
    // North
    if (mazeLayout[playerPosition.column - 1][playerPosition.row] != '1'
        && mazeLayout[playerPosition.column - 1][playerPosition.row] != '*') {
        newPosition.column = playerPosition.column - 1;
        adjacentPositions.push(newPosition); // Push the position to the stack
        newPosition.column++;
    }

    // West
    if (mazeLayout[playerPosition.column][playerPosition.row - 1] != '1'
        && mazeLayout[playerPosition.column][playerPosition.row - 1] != '*') {
        newPosition.row = playerPosition.row - 1;
        adjacentPositions.push(newPosition); // Push the position to the stack
        newPosition.row++;
    }

    // South
    if (mazeLayout[playerPosition.column + 1][playerPosition.row] != '1'
        && mazeLayout[playerPosition.column + 1][playerPosition.row] != '*') {
        newPosition.column = playerPosition.column + 1;
        adjacentPositions.push(newPosition); // Push the position to the stack
        newPosition.column--;
    }

    // East
    if (mazeLayout[playerPosition.column][playerPosition.row + 1] != '1'
        && mazeLayout[playerPosition.column][playerPosition.row + 1] != '*') {
        newPosition.row = playerPosition.row + 1;
        adjacentPositions.push(newPosition); // Push the position to the stack
        newPosition.row--;
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Maze::printMaze
// Purpose: Prints the maze grid with the current player position and exit marked.
//          Also provides information about the player character, starting position, and exit.
// Input Parameters: None.
// Output Parameters: None.
// Return Value: None.
/////////////////////////////////////////////////////////////////////////////////////////////

void Labyrinth::displayMaze() {
    // Modify the appearance of the maze before printing
    changeMazeAppearance();

    // Print the maze grid
    for (int col = 0; col < 12; ++col) {
        std::cout << std::right << std::setw(15); // Set the output alignment and width

        for (int row = 0; row < 12; ++row) {
            std::cout << mazeLayout[col][row]; // Print each cell of the maze
        }
        std::cout << std::endl; // Move to the next line after printing each row
    }

    // Print additional information about the maze
    std::cout << "Your character is '" << playerCharacter << '\''
        << "\nYour starting position is marked by " << static_cast<char>(167)
        << "\n'E' marks the exit\n\n";

    // Restore the appearance of the maze after printing
    clearMazePath();
}



/////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Maze::changeMazeLook
// Purpose: Modifies the appearance of the maze grid, replacing wall and clear path characters
//          with user-selected ASCII characters.
// Input Parameters: None.
// Output Parameters: None.
// Return Value: None.
/////////////////////////////////////////////////////////////////////////////////////////////

void Labyrinth::changeMazeAppearance() {
    // Loop through each cell of the maze grid
    for (int col = 0; col < 12; ++col) {
        for (int row = 0; row < 12; ++row) {
            // Change the appearance of walls ('1') to a different character
            if (mazeLayout[col][row] == '1') {
                mazeLayout[col][row] = static_cast<char>(219); // ASCII character 177 (block)
            }
            // Change the appearance of clear paths ('0') to a space character
            else if (mazeLayout[col][row] == '0') {
                mazeLayout[col][row] = ' ';
            }
        }
    }
}



/////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Maze::cleanMaze
// Purpose: Resets the maze grid by removing player path, starting position markers,
//          and visited path markers, and restores original wall and exit positions.
// Input Parameters: None.
// Output Parameters: None.
// Return Value: None.
/////////////////////////////////////////////////////////////////////////////////////////////

void Labyrinth::clearMazePath() {
    // Loop through each cell of the maze grid
    for (int col = 0; col < 12; ++col) {
        for (int row = 0; row < 12; ++row) {
            // Check if the cell contains a character that needs to be cleaned
            if (mazeLayout[col][row] == '*'  // Visited path
                || mazeLayout[col][row] == '!' // Starting position marker
                || mazeLayout[col][row] == playerCharacter // Player character
                || mazeLayout[col][row] == ' ') // Clear path
            {
                mazeLayout[col][row] = '0'; // Restore the original empty path character
            }
            // Check if the cell is the exit position
            else if (col == exitPosition.column && row == exitPosition.row) {
                mazeLayout[col][row] = 'E'; // Restore the original exit character
            }
            else {
                mazeLayout[col][row] = '1'; // Restore the original wall character
            }
        }
    }
}




