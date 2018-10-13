#include <iostream>
#include <string>

using namespace std;



int main() {
	string input;
	string output = "";
	int lines;
	int count = 1;
	cout << "Please enter an input: ";
	cin >> input;
	cout << "Please enter the number of lines you would like to see: ";
	cin >> lines;
	int size = input.length();
	for (int i = 0; i < lines; i++) {
		//cout << "inside outer" << endl;
		for (int position = 0; position < size; position++) {
			//cout << "inside inner" << endl;
			if (input[position] == input[position+1]) {
				count++;
			}
			else {
				output = output + to_string(count) + input[position];
				count = 1;
			}
		}
		cout << output << endl;
		input = output;
		size = input.length();
		output = "";
	}

	system("pause");
}

