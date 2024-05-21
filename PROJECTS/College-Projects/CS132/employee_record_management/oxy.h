/////////////////////////////////////////////////////////////////////////////////////////////
// File name         : oxy.h
// Description		 : Represents a management system for employees at Oxy Corporation.
// Programmer        : Merveilles Katumba Biende
// Date created      : 5-03-2024
// Date last revised : 12-03-2024
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef OXYCOOKIE_H
#define OXYCOOKIE_H
#include <iostream>
#include "tree.h"
#include "employee.h"

class oxy:protected tree<employee>
{
public:
	oxy(); //constructor
	~oxy(); //destructor
	void retrieveRecord(istream& in); //take employees info from txt file
	void printRecord(); //prints the tree to the console
	void findSpecificEmployee(); //looks for an employee by last name

	void addWorker(); //adds an employee into the tree
	void removeWorker(); //removes an employee from the tree
	void editWorkerInfo(); //edits an employee's info

	void validateSSN(char* SSN); //validates SSN input
	void validateEmpCode(char& Code); //validates Employee Code input

	void saveRecord(ostream& out); //saves employees info in a txt file 

private:
	tree<employee> workForce; //tree of Oxy employees
	employee worker; //an Oxy employee
};

#endif