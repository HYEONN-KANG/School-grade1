#include "car.h"

#include <iostream>
using namespace std;

int car::getSpeed() {
	return speed;
}

void car::setSpeed(int input) {
	if (input < 0) {
		cout << "speed 값 입력 에러 발생\n";
	}
	else {
		speed = input;
	}
}

void car::setGear(int input) {
	if (input < 0) {
		cout << "gear 값 입력 에러 발생\n";
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
		cout << "distance 값 입력 에러 발생\n";
	}
	else {
		distance = input;
	}
}

int car::getDistance() {
	return distance;
}