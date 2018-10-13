//Author: Steven Calvert
#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

int main() {
	char playField[20][50];
	bool boolField[20][50];
	bool boolFieldCopy[20][50];

	ifstream initialInput;
	initialInput.open("InitialConfig.txt", ios::in);

	string line;
	int generation;

	for (int i = 0; i < 20; i++) {
		getline(initialInput, line);
		for (int j = 0; j < 50; j++) {
			playField[i][j] = line[j];
		}
	}

	cout << "Welcome to Conway's game of life." << endl;
	cout << "Each cell in the grid may be alive(x) or dead(.)" << endl;
	cout << "In each successive generation cells may die or be born," << endl;
	cout << "according to the following rules: " << endl;
	cout << "1. A neighbor of a given cell has a common side or corner with that cell. \nEach cell inside the grid has 8 neighbors(except cell on borders)." << endl;
	cout << "2. An alive cell with 2 or 3 alive neighbor remains alive in the next generation. \nAn alive cell with less than two alive neighbors dies(loneliness) \n an alive cell with for or more alive neighbors also dies (overcrowding)." << endl;
	cout << "3. A dead cell becomes alive in the next generation if it has exactly three alive neighbors." << endl;
	cout << "4. All birth and death take place exactly at the same time, so that the change \nfrom one generation to the next is instantaneous.\n" << endl;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 50; j++) {
			cout << playField[i][j] << " ";
			if (playField[i][j] == 'x') {
				boolField[i][j] = true;
				boolFieldCopy[i][j] = true;
			}
			else {
				boolField[i][j] = false;
				boolFieldCopy[i][j] = false;
			}
		}
		cout << endl;
	}


	cout << "\nWith this initial configuration, which generation would you like to view? " << endl;
	cout << "input-> ";
	cin >> generation;

	for (int i = 0; i < generation; i++) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 50; j++) {
				int alive = 0;
				if ((i - 1 >= 0) && (j - 1 >= 0)) {
					if (boolField[i-1][j-1]) {
						alive++;
					}
				}
				if ((i - 1 >= 0)) {
					if (boolField[i-1][j]) {
						alive++;
					}
				}
				if ((i-1 >= 0) && (j+1 <= 49)) {
					if (boolField[i-1][j+1]) {
						alive++;
					}
				}
				if (j - 1 >= 0) {
					if (boolField[i][j - 1]) {
						alive++;
					}
				}
				if (j + 1 <= 49) {
					if (boolField[i][j + 1]) {
						alive++;
					}
				}
				if ((i + 1 <= 19) && (j - 1 >= 0)) {
					if (boolField[i + 1][j - 1]) {
						alive++;
					}
				}
				if (i + 1 <= 19) {
					if (boolField[i + 1][j]) {
						alive++;
					}
				}
				if ((i + 1 <= 19) && (j + 1 <=49)) {
					if (boolField[i + 1][j + 1]) {
						alive++;
					}
				}
				if (boolField[i][j]) {
					switch (alive) {
					case 2:
						break;
					case 3:
						break;
					default:
						boolFieldCopy[i][j] = false;
						break;
					}
				}
				else {
					switch (alive) {
					case 3:
						boolFieldCopy[i][j] = true;
						break;
					default:
						break;
					}
				}
			}
		}
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 50; j++) {
				if (boolFieldCopy[i][j]) {
					boolField[i][j] = true;
				}
				else {
					boolField[i][j] = false;
				}
			}
		}
		system("CLS");
		cout << "Generation: " << (i + 1) << endl;
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 50; j++) {
				if (boolField[i][j]) {
					cout << 'x' << " ";
				}
				else {
					cout << '.' << " ";
				}
			}
			cout << endl;
		}
		this_thread::sleep_for(chrono::milliseconds(200));
		if (i + 1 == generation) {
			int more;
			cout << "Run more generations? (0 to finish): ";
			cin >> more;
			generation += more;
		}
	}

	system("CLS");
	cout << "Final Configuration; Generation :" << generation << endl;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 50; j++) {
			if (boolField[i][j]) {
				cout << 'x' << " ";
			}
			else {
				cout << '.' << " ";
			}
		}
		cout << endl;
	}


	system("pause");
}
/*
	x.x.xxx.x.
	xx.xx.xx.x
	.xx..xx.x.
	x.xx.x.xxx
	xx.xx.x.x.
	.xx.xx.x.x
	xxx.xx.xx.
	x..xx..x.x
*/