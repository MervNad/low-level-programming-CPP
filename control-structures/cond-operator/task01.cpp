/*
 * file: task01.cpp
 * comparing two integers using the conditional statement
 */

#include<iostream>
using namespace std;

int main(){
	
	int num1{}, num2{};

	cout << "Enter two intergers separated by a space: ";
	cin >> num1 >> num2;

	if(num1 != num2) {
		cout << "Largest " << ((num1 > num2) ? num1 : num2) << endl;
		cout << "Smallest " << ((num1 < num2) ? num1 : num2) << endl;
	}

	else {
		cout << "The numbers are equal" << endl;
	}
	cout << endl;
	return 0;
}
