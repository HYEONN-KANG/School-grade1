#include "car.h"

#include <iostream>
using namespace std;

int car::getSpeed() {
	return speed;
}

void car::setSpeed(int input) {
	if (input < 0) {
		cout << "speed �� �Է� ���� �߻�\n";
	}
	else {
		speed = input;
	}
}

void car::setGear(int input) {
	if (input < 0) {
		cout << "gear �� �Է� ���� �߻�\n";
	}
	else {
		gear = input;
	}
}

void car::speedUp() {
	speed = speed + gear;
}

void car::setDistance(int input) {
	if (input < 0) {
		cout << "distance �� �Է� ���� �߻�\n";
	}
	else {
		distance = input;
	}
}

int car::getDistance() {
	return distance;
}