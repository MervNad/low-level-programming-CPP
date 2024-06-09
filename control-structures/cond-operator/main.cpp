//Conditional operator

#include<iostream>
using namespace std;

int main() {

	int num{};

	cout << "Enter an interger: ";
	cin >> num;
	
	//using if-else statement
	
	if (num % 2 == 0)
		cout << num << " is even" << endl;
	else
		cout << num << " is odd" << endl;
	
	//using the conditional statement
	cout << num << " is" << ((num % 2 == 0) ? " even" : " odd") << endl;
	cout << endl;
	return 0;
}
