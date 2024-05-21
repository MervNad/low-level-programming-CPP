/////////////////////////////////////////////////////////////////////////////////////////////
// File name         : oxy.cpp
// Description		 : This is the implementation of the oxy class.
// Programmer        : Merveilles Katumba Biende
// Date created      : 5-03-2024
// Date last revised : 12-03-2024
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "oxy.h"

//constructor
oxy::oxy(){}

//destructor
oxy::~oxy(){}

//take employees info from txt file
void oxy::retrieveRecord(istream& in)
{
	static bool openedOnce = false;

	if (openedOnce)
		if (!workForce.emptyTree())
			workForce.~tree();

	while (in >> worker) 
		workForce.insert(worker);

	openedOnce = true;
}

//adds an employee into the tree
void oxy::addWorker()
{
	cout << "\nEnter the last name of the new employee\n";
	cin >> worker.lastName;

	worker.lastName[0] = toupper(worker.lastName[0]);

	//ignore any potential extra input after the last name is taken
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "\nEnter the SSN of the new employee in the form of 123-45-6789\n";
	validateSSN(worker.SSN);

	cout << "\nEnter the employee code:"
		      << "\n'O' for office"
		      << "\n'F' for factory"
		      << "\n'S' for salesperson\n";
	validateEmpCode(worker.EmployeeCode);

	worker.hoursWorked = 0;

	employee Exists = workForce.onlySearch(worker.lastName);
	if (Exists == worker)
	{
		cout << Exists.lastName << " already exists in the record\n";
		return;
	}

	workForce.insert(worker);
}

//removes an employee from the tree
void oxy::removeWorker()
{
	string lName;
	cout << "\nWhat is the last name of the employee that you would like to remove?\n";
	cin >> lName;

	lName[0] = toupper(lName[0]);

	//ignore any potential extra input after the last name is taken
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	worker = workForce.onlySearch(lName);
	workForce.SearchAndDestroy(worker);
}

//edits an employee's info
void oxy::editWorkerInfo()
{
	string lName,
		        newInfo;
	char newSSN[12]{},
		 newCode;
	int newHrsWorked = 0,
		choice;

	cout << "\nWho's information would you like to edit?\n"
		      << "Enter last name: ";
	cin >> lName;
	cout << '\n';

	//ignore any potential extra input after the last name is taken
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	worker = workForce.onlySearch(lName);
	workForce.SearchAndDestroy(worker);

	cout << "What information would you like to edit?\n"
		      << "\n1. Last name?"
		      << "\n2. Social Security Number?"
			  << "\n3. Employee Code?"
		      << "\n4. Hours worked?\n";
	cin >> choice;

	while (!(choice >= 1 && choice <= 4) || !cin.good() || cin.peek() != '\n')
	{
		cout << "Invalid choice! try again\n";

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cin >> choice;
	}

	switch (choice)
	{
	case 1:
		cout << "\nEnter a new last name\n";
		cin >> newInfo;

		newInfo[0] = toupper(newInfo[0]);

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		worker.lastName = newInfo;
		break;

	case 2:
		cout << "\nEnter a new SSN in the form of 123-45-6789\n";

		for (int i = 0; i < 11; i++)
		{
			cin >> newSSN[i];

			if ((!isdigit(newSSN[i]) && newSSN[i] != '-')
				|| ((i == 3 || i == 6) && newSSN[i] != '-')
				|| ((i != 3 && i != 6) && newSSN[i] == '-'))
			{
				cout << "\nInvalid!\n"
					      << "the SSN must be in the form of 123-45-6789\n"
					      << "try again\n";

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				i = -1; //resetting the loop
			}
			else
				worker.SSN[i] = newInfo[i];
		}

		break;

	case 3:
		cout << "\nEnter a new Employee Code\n"
			      << "\n'O' for office"
			      << "\n'F' for factory"
			      << "\n'S' for salesperson\n";
		cin >> newCode;
		validateEmpCode(newCode);

		worker.EmployeeCode = newCode;

	case 4:
		cout << "\nEnter the amount of hours the employee has worked\n";
		cin >> newHrsWorked;

		while (!cin.good() || cin.peek() != '\n')
		{
			cout << "\nThe number that you've entered may be too large\n"
				      << "try again\n";

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cin >> newHrsWorked;
		}

		worker.hoursWorked = newHrsWorked;
	}

	workForce.insert(worker);
}

//validates SSN input
void oxy::validateSSN(char* SSN)
{
	for (int i = 0; i < 11; i++)
	{
		cin >> SSN[i];

		if ((!isdigit(SSN[i]) && SSN[i] != '-')
			|| ((i == 3 || i == 6) && SSN[i] != '-')
			|| ((i != 3 && i != 6) && SSN[i] == '-'))
		{
			cout << "\nInvalid!\n"
				      << "the SSN must be in the form of 123-45-6789\n"
				      << "try again\n";

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			i = -1; //resetting the loop
		}
	}
}

//validates Employee Code input
void oxy::validateEmpCode(char& Code)
{
	do
	{
		cin >> Code;

		Code = toupper(Code);

		if (Code != 'O' && Code != 'F' && Code != 'S')
		{
			cout << "\nInvalid employee code! try again\n";

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

	} while (Code != 'O' && Code != 'F' && Code != 'S');
}

//looks for an employee by last name
void oxy::findSpecificEmployee()
{
	string lName;
	cout << "\nWhat is the last name of the employee that you would like to find?\n";
	cin >> lName;
	cout << '\n';

	lName[0] = toupper(lName[0]);

	//ignore any potential extra input after the last name is taken
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	worker = workForce.onlySearch(lName);
	cout << worker;
}

//prints the tree to the console
void oxy::printRecord()
{
	char Choice{};
	cout << "\nWould you like to see the:\n"
		      << "\n\tA. the entire list of employees?"
		      << "\n\tO. the office employees?"
			  << "\n\tF. the factory workers?"
		      << "\n\tS. the sales people?\n";
	cin >> Choice;
	cout << '\n';

	Choice = toupper(Choice);

	while ((Choice != 'A' && Choice != 'O'
		   && Choice != 'F' && Choice != 'S')
		   || cin.peek() != '\n')
	{
		cout << "\nInvalid employee code! try again\n";

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cin >> Choice;
		Choice = toupper(Choice);
	}

	workForce.writeTree(2, Choice);
}

//saves employees info in a txt file 
void oxy::saveRecord(ostream& out)
{
	workForce.writeTree(1,'A', out);
}