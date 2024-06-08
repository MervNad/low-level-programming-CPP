//Shipping Calculator
//filename: project.cpp

#include <iostream>
using namespace std;

int main(){
	int lenght{}, width{}, height{};
	double cost{};
	const int max_length{10};
	const int max_width{10};
	const int max_height{10};
	const double base_cost{2.50};
	const double extra1{0.1};
	const double extra2{0.25};
	cout << "Enter the package dimensions in inches: ";
	cin >> lenght >> width >> height;
	int volume{lenght * width * height};
	if (lenght > max_length || width > max_width || height > max_height)
		cout << "Sorry, We cannot ship this package!\n"
			<< "Oversized, all dimensions must be 10 inches or less" << endl;
	else {
		if (volume > 500)
			cost = base_cost + (base_cost * extra2);
		else if (volume > 100 && volume < 500)
			cost = base_cost + (base_cost * extra1);
		else
			cost = base_cost;
	
		cout << "================================================\n";
		cout << "Your package volume is: " << volume << " cubic" << endl;
		cout << " The detailed dimensions are: \n";
		cout << " Length: " << lenght << " inches" << endl;
		cout << " Width: " << width << " inches" << endl;
		cout << " Height: " << height << " inches" << endl;
		cout << "=================================================\n";
		cout << "amount to pay: " << cost << "$" << endl;
	}

	cout << endl;
	return 0;
}
