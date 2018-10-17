#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {

	vector<double> secondTimes;
	vector<double> minuteTimes;
	double secondsTotal = 21.81;
	int minuteTotal = 16;

	for (int i = 0; i <= 21; i++) {
		secondTimes.push_back(secondsTotal);
		minuteTimes.push_back(minuteTotal);
		secondsTotal += 43.6363;
		minuteTotal += 32;
	}
	
	cout << "Between 12AM and 12PM," << endl;
	cout << "The clock hands are perpendicular at the following times: " << endl;
	for (int i = 0; i < secondTimes.size(); i++) {
		int seconds, minutes, hours;
		seconds = floor(secondTimes[i]);
		minutes = minuteTimes[i];
		minutes += seconds / 60;
		seconds = seconds % 60;
		hours = minutes / 60;
		minutes = minutes % 60;
		if (hours / 10 == 0) {
			cout << "0";
		}
		cout << hours << ":";
		if (minutes / 10 == 0) {
			cout << "0";
		}
		cout << minutes << ":";
		if (seconds / 10 == 0) {
			cout << "0";
		}
		cout << seconds << " AM" << endl;
	}

	system("pause");

}