#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main() {
	int day, month, year;
	int yearCode, monthCode, centuryCode, leapYearCode = 0;
	string weekday;
	string daysOfTheWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int centuryCodeList[4] = { 6, 4 , 2, 0 };

	cout << "Please enter a date in the format MM DD YYYY: ";
	cin >> month >> day >> year;
	
	yearCode = (year % 100 + ((year % 100) / 4)) % 7;

	switch (month) {
	case 1:
		monthCode = 0;
		break;
	case 2:
		monthCode = 3;
		break;
	case 3:
		monthCode = 3;
		break;
	case 4:
		monthCode = 6;
		break;
	case 5:
		monthCode = 1;
		break;
	case 6:
		monthCode = 4;
		break;
	case 7:
		monthCode = 6;
		break;
	case 8:
		monthCode = 2;
		break;
	case 9:
		monthCode = 5;
		break;
	case 10:
		monthCode = 0;
		break;
	case 11:
		monthCode = 3;
		break;
	case 12:
		monthCode = 5;
		break;
	}

	centuryCode = floor((double)(year % 400) * pow(10, -2));
	centuryCode = centuryCodeList[centuryCode];

	if ((year % 4) == 0) {
		if ((year % 100) == 0) {
			if ((year % 400) == 0) {
				if (month == 1 || month == 2) {
					leapYearCode = -1;
				}
			}
		}
	}

	cout << "Year code: " << yearCode << endl;
	cout << "Month code: " << monthCode << endl;
	cout << "Century code: " << centuryCode << endl;
	cout << "Day: " << day << endl;
	cout << "Leap year code: " << leapYearCode << endl;


	weekday = daysOfTheWeek[(yearCode + monthCode + centuryCode + day + leapYearCode) % 7];

	cout << "That day is a " << weekday << endl;
	system("pause");
}