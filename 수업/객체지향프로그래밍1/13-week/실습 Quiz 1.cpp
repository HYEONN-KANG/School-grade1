#include <iostream>
#include "Car.h"

using std::cout;
using std::endl;

void Car::getSpeed(int speed_) {
	if (speed_ > 0) {
		Car::speed = speed_;
	}
}

int Car::setSpeed() {
	return speed;
}

void Car::setGear(int gear_) {
	gear = gear_;
}
void Car::speedUp() {
	speed = speed + gear;
}

#include <Windows.h>

int main() {
	Car myCar, yourCar;
	myCar.getSpeed(20); myCar.setGear(2);
	yourCar.getSpeed(15); yourCar.setGear(3);

	cout << "myCar의 초기 속도는 20이고, 기어는 2입니다."
		<< "\nyourCar의 초기 속도는 15이고, 기어는 3입니다." << endl;

	int wheremyCar = myCar.setSpeed();
	int whereyourCar = yourCar.setSpeed();

	int time = 0;

	while (true) {
		if (wheremyCar <= whereyourCar) {
			break;
		}

		Sleep(1000);
		time++;
		myCar.speedUp();
		yourCar.speedUp();


		wheremyCar += myCar.setSpeed();
		whereyourCar += yourCar.setSpeed();
	}

	cout << "yourCar이 myCar을 따라 잡은 시간은 " << time << " 초 입니다.\n"
		<< "myCar의 이동 거리는 " << wheremyCar
		<< "\nyourCar의 이동 거리는 " << whereyourCar << endl;
 }