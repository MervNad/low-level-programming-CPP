// C++ while loop

#include<iostream>

using namespace std;

int main(){
	//int number{};
	//cout << "Enter a positive integer -- start the countdown: ";
	//cin >> number;

	//while(number > 0){
	//	cout << number << endl;
	//	--number;
	//}
	//cout << "Blastoff!" << endl;
	
	//int number{},start{1};
	//cout << "Enter a positive integer -- count up: ";
	//cin >> number;

	//while(number >= start){
	//	cout << start << endl;
	//	++start;
	//}
	
	//int number{};
	//cout << "Enter a number less than 100: ";
	//cin >> number;

	//while(number >= 100){
	//	cout << "Enter an integer less than 100: ";
	//	cin >> number;
	//}
	//cout << "Thanks!" << endl;
	
	bool done{false};
	int number{};

	while(!done){
		cout << "Enter a number between 1 and 5: ";
		cin >> number;
		if (number <= 1 || number >= 5){
			cout << "Out of range! Try again " << endl;
		}
		else{
			cout << "Thanks!" << endl;
			done = true;
		}
	}


	cout << endl;
	return 0;
}
