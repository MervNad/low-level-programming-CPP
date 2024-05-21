/////////////////////////////////////////////////////////////////////////////////////////////
// File name         : driver.cpp
// Description       : This is the main function of the program.
// Programmer        : Merveilles Katumba Biende
// Date created      : 5-03-2024
// Date last revised : 12-03-2024
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <limits>
#include "oxy.h"

using namespace std;

// Function to open a file
void openFile(ifstream& in);

int main() {
    ifstream inFile;
    ofstream outFile;
    string newFName;
    oxy emp;
    char choice;
    static int newFile = 0;

    cout << "Welcome to Employee Record Management System!" << endl;

    while (true) {
        // Display menu options
        cout << "\nWhat would you like to do?" << endl
            << "\n\tG. Get the record of all employees from a text file?"
            << "\n\tI. Insert the record of a new employee?"
            << "\n\tU. Update the record of an employee?"
            << "\n\tR. Retrieve and display the record of an employee?"
            << "\n\tL. List all/some records on the screen?"
            << "\n\tS. Save the record in a new file?"
            << "\n\tD. Delete an employee's record?"
            << "\n\tE. Exit the program?\n\n";

        // Get user choice
        cin >> choice;
        choice = toupper(choice);

        // Validate user input
        while ((choice != 'G' && choice != 'I'
            && choice != 'U' && choice != 'R'
            && choice != 'L' && choice != 'S'
            && choice != 'D' && choice != 'E')
            || cin.peek() != '\n') {
            cout << "\nInvalid choice! Please try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
            choice = toupper(choice);
        }

        // Check if a file is required but not opened yet
        if (!inFile.is_open() && choice != 'G') {
            cout << "\nYou must have an open file first!"
                << "\nPlease choose 'G' to open a text file.\n";
            continue;
        }

        switch (choice) {
        case 'G':
            cout << "\nEnter the file name and its path: ";
            if (newFile) inFile.close();
            openFile(inFile);
            emp.retrieveRecord(inFile);
            break;
        case 'I':
            emp.addWorker();
            break;
        case 'U':
            emp.editWorkerInfo();
            break;
        case 'R':
            emp.findSpecificEmployee();
            break;
        case 'L':
            emp.printRecord();
            break;
        case 'S':
            if (!newFile) {
                cout << "\nEnter the name of the new file: ";
                cin >> newFName; //Prompt user for new file name
                newFName += ".txt"; //Append .txt extention
                outFile.open(newFName);
                newFile++;
                cout << "\nA new file has been saved under the name: " << newFName << " successfully!\n";
            }
            else {
                size_t txtPos = newFName.find_last_of('.');
                newFName.erase(txtPos);
                newFName = newFName + '(' + to_string(newFile) + ')' + ".txt";
                outFile.open(newFName);
                cout << "\nA new file has been saved under the name: " << newFName << " successfully!\n";
                size_t leftParanPos = newFName.find_first_of('(');
                size_t rightParanPos = newFName.find_last_of(')');
                size_t fromLeftToRight = rightParanPos - leftParanPos + 1;
                newFName.erase(leftParanPos, fromLeftToRight);
                newFile++;
            }
            emp.saveRecord(outFile);
            outFile.close();
            break;
        case 'D':
            emp.removeWorker();
            break;
        case 'E':
            inFile.close();
            cout << "Exiting the program. Goodbye!" << endl;
            return 0;
        }
    }

    return 0;
}

void openFile(ifstream& in) {
    string fName;
    cin >> ws;
    getline(cin, fName);
    in.open(fName);

    while (!in.good() || !in.is_open()) {
        cout << "\nCould not find the file. Please try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, fName);
        in.open(fName);
    }
}
