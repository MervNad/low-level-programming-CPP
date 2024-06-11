//Range based for loop

#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int main() {
	//int scores[] {10,20,30};
	//for (auto score: scores)
	//	cout << score << endl;
	
	//vector<double> temperatures {87.9,77.9,80.0,72.5};
	//double average{};
	//double total{};

	//for(auto temp: temperatures){
	//	total += temp;
	//}

	//if(temperatures.size() != 0)
	//	average = total / temperatures.size();
	//cout << fixed << setprecision(1);
	//cout << "The average temperature is: " << average << endl;
	
	//for(auto values: {1,2,3,4,5,6,7,8,9})
	//	cout << values << endl;

	//for(auto str: "This is a string of characters")
	//	if(str != ' ')
	//		cout << str;
	
	for(auto c: "This is a string of characters."){
		if(c == ' ')
			cout << "\t";
		else
			cout << c;
	}
	cout << endl;
	return 0;
}
