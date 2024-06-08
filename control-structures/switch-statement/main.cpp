//switch statement

#include<iostream>
using namespace std;

int main(){

	char grade{};
	cout << "Enter the grade you expect on the exam: ";
	cin >> grade;

	switch(grade){
		case 'a':
		case 'A':
			cout << "You need 90+, Good luck and study hard!" << endl;
			break;
		case 'b':
		case 'B':
			cout << " You need 80 - 89 for this grade, Good luck!" << endl;
			break;
		case 'c':
		case 'C':
			cout << "You need 70 - 79 for an average grade" << endl;
			break;
		case 'd':
		case 'D':
			cout << "Hum!, you should strive for higher grade!, all you need is 60 - 69" << endl;
			break;
		case 'f':
		case 'F':
			{
				char check{};
				cout << "Are you sure (Y/N)? ";
				cin >> check;
				if (check == 'Y' || check == 'y')
					cout << "OK, I guess you are not ready for the test..." << endl;
				else if (check == 'N' || check == 'n')
					cout << "Sure, you have 1 extra day to be ready, Go study!" << endl;
				else
					cout << "Invalid entry, (Y/N) only" << endl;
				break;
			}
		default:
			cout << "Sorry, not a valid grade." << endl;
	}
	cout << endl;
	return 0;
}
