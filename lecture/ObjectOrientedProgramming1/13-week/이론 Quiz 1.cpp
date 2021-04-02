#include <iostream>

using std::cout;
using std::endl;

#include <iomanip>

using std::setfill;
using std::setw;

struct Time {
	int hour;
	int minute;
	int second;
};

void printUniversal(const Time&);
void printStandard(const Time&);

int main() {
	Time dinnerTime;

	dinnerTime.hour = 18;
	dinnerTime.minute = 30;
	dinnerTime.second = 0;

	cout << "Dinner will be held at ";
	printUniversal(dinnerTime);
	cout << " universal time, \nwhich is ";
	printStandard(dinnerTime);
	cout << " standard time.\n";

	dinnerTime.hour = 29;
	dinnerTime.minute = 73;

	cout << "\nTime with invalid values: ";
	printUniversal(dinnerTime);
	cout << endl;

	return 0;
}

void printUniversal(const Time& t) {
	cout << setfill('0') << setw(2) << t.hour << ":"
		<< setw(2) << t.minute << ":"
		<< setw(2) << t.second;
}

void printStandard(const Time& t) {
	cout << ((t.hour == 0 || t.hour == 12) ? 12 : t.hour % 12)
		<< ":" << setfill('0')
		<< setw(2) << t.minute << ":"
		<< setw(2) << t.second
		<< (t.hour < 12 ? " AM" : " PM");
}