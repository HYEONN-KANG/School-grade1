#include <iostream>

using std::cout;
using std::endl;

#include <iomanip>

using std::setfill;
using std::setw;

class Time {

public:
	Time();
	void setTime(int, int, int);
	void printUniversal();
	void printStandard();
	int gethour();
	int getmin();
	int getsec();

private:
	int hour;
	int minute;
	int second;
};

Time::Time() {
	hour = minute = second = 0;
}

void Time::setTime(int h, int m, int s) {
	hour = (h >= 0 && h < 24) ? h : 0;
	minute = (m >= 0 && m < 60) ? m : 0;
	second = (s >= 0 && s < 60) ? s : 0;
}

void Time::printUniversal() {
	cout << setfill('0') << setw(2) << hour << ":"
		<< setw(2) << minute << ":"
		<< setw(2) << second;
}

void Time::printStandard() {
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
		<< ":" << setfill('0') << setw(2) << minute
		<< ":" << setw(2) << second
		<< (hour < 12 ? " AM" : " PM");
}

int Time::gethour() {
	return hour;
}
int Time::getmin() {
	return minute;
}
int Time::getsec() {
	return second;
}

int main() {
	Time t2;
	t2.setTime(16, 45, 10);

	cout << setfill('0') << setw(2) << t2.gethour() << ":"
		<< setw(2) << t2.getmin() << ":"
		<< setw(2) << t2.getsec() << endl;
}