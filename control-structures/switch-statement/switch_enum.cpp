//switch statement with enumeration

#include<iostream>
using namespace std;

int main() {
	enum Direction {
		left, right, up, down
	};

	Direction heading{left};

	switch(heading) {
		case left:
			cout << "Turn left" << endl;
			break;
		case right:
			cout << "Turn right" << endl;
			break;
	}
	cout << endl;
	return 0;
}
