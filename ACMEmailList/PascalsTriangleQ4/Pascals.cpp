#include <iostream>
#include <vector>

using namespace std;

int main() {
	int rows;
	vector<vector<int>> pascals;
	cout << "Please enter the number of rows of pascal's triangle to display: ";
	cin >> rows;
	for (int i = 0; i <= rows; i++) {
		vector<int> curr;
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				curr.push_back(1);
			}
			else {
				curr.push_back(pascals[i - 1][j - 1] + pascals[i - 1][j]);
			}
		}
		pascals.push_back(curr);
	}

	for (int i = 0; i < pascals.size(); i++) {
		for (int k = rows; k >= i; k--) {
			cout << " ";
		}
		for (int j = 0; j <= i; j++) {
			if (j == i) {
				cout << pascals[i][j];
			}
			else {
				cout << pascals[i][j] << " ";
			}
			
		}
		cout << endl;
	}
	system("pause");
}