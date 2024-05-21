/////////////////////////////////////////////////////////////////////////////////////////////
// File name         : employee.h
// Description		 : Represents an employee with attributes such as last name, SSN,
//					   employee code, and hours worked.
// Programmer        : Merveilles Katumba Biende
// Date created      : 5-03-2024
// Date last revised : 12-03-2024
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

struct employee
{
	string lastName;
	char SSN[12],
	     EmployeeCode;
	int hoursWorked;

	//constructor
	employee(char* S = nullptr, string lN = "",
		char eCode = ' ', int hrs = 0) {
		lastName = lN;

		if (S == nullptr)
			for (char& i : SSN)
				i = '\0';
		else
			for (int i = 0; i < 11; i++)
				SSN[i] = *(S + i);
		SSN[11] = '\0'; //marks the end of the array

		EmployeeCode = eCode;
		hoursWorked = hrs;
	}

	//overloaded logical LESS THAN operator
	bool operator < (const employee& worker) const;

	//overloaded logical MORE THAN OR EQUAL TO operator
	bool operator >= (const employee& worker) const;

	//overloaded logical MORE THAN operator
	bool operator > (const employee& worker) const;

	//overloaded logical NOT EQUAL TO operator
	bool operator != (const employee& worker) const;

	//overloaded logical EQUAL TO operator
	bool operator == (const employee& worker) const;

	//overloaded insertion operator
	friend istream& operator >> (istream& in, employee& worker)
	{
		in >> worker.lastName;

		for (int i = 0; i < 11; i++)
			in >> worker.SSN[i];
		worker.SSN[11] = '\0'; //marks the end of the array

		in >> worker.EmployeeCode;
		in >> worker.hoursWorked;

		return in;
	}

	//overloaded extraction operator
	friend ostream& operator << (ostream& out, const employee& worker)
	{
		out << worker.lastName << '\n';

		for (char i : worker.SSN)
			if (i != '\0')
				out << i;
		out << '\n';

		out	<< worker.EmployeeCode << '\n'
			<< worker.hoursWorked << "\n";

		return out;
	}
};

#endif 