#include <iostream>
#include <string>

using namespace std;



int main() {
	int year;
	int anchor;
	int doomsday;
	string laborDay = "Monday, September", memorialDay = "Monday, May", thanksgivingDay = "Thursday, November", electionDay = "Tuesday, November";
	string daysOfTheWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	int thanksgivingAdds[7] = { 3, 2, 1, 0, 6, 5, 4 };

	cout << "Please enter a year to see the date of some of that years holidays(YYYY): ";
	cin >> year;
	
	anchor = (5 * (year / 100)) % 4 % 7 + 2;
	cout << "The anchor day is " << daysOfTheWeek[anchor] << endl;

	doomsday = 2 + 5 * (year % 4) + 4 * (year % 100) + 6 * (year % 400);
	doomsday %= 7;

	cout << "That years doomsday is " << daysOfTheWeek[doomsday] << endl;
	
	//labor day: first monday in september
	if (doomsday == 0 || doomsday == 6) {
		cout << "Labor day in the year " << year << " is " << laborDay << " " << (5 + (doomsday + 1)%5) << endl;
	}
	else {
		
		cout << "Labor day in the year " << year << " is " << laborDay << " " << (5 - (doomsday - 1)) << endl;
	}

	//memorial day: last monday in may
	cout << "Memorial day in the year " << year << " is " << memorialDay << " " << (31 - doomsday) << endl;

	//thanksgiving day: 4th thursday in november
	cout << "Thanksgiving day in the year " << year << " is " << thanksgivingDay << " " << (22 + thanksgivingAdds[doomsday]) << endl;

	//Election day: 1st Tuesday after 1st Monday in November
	if (doomsday == 0) {
		cout << "Election day in the year " << year << " is " << electionDay << " " << 2 << endl;
	}
	else {

		cout << "Labor day in the year " << year << " is " << electionDay << " " << (8 - (doomsday - 1)) << endl;
	}
	system("pause");

}