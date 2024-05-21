/////////////////////////////////////////////////////////////////////////////////////////////
// File name         : employee.cpp
// Description		 : Implementation of overloading operators of employee struct.
// Programmer        : Merveilles Katumba Biende
// Date created      : 5-03-2024
// Date last revised : 12-03-2024
/////////////////////////////////////////////////////////////////////////////////////////////

#include "employee.h"


bool employee::operator < (const employee& worker) const {
	return (this->lastName < worker.lastName);
}

bool employee::operator >= (const employee& worker) const {
	return (this->lastName >= worker.lastName);
}

bool employee::operator > (const employee& worker) const {
	return (this->lastName > worker.lastName);
}

bool employee::operator != (const employee& worker) const {
	return (this->lastName != worker.lastName);
}

bool employee::operator == (const employee& worker) const {
	return (this->lastName == worker.lastName);
}