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

	cout << "myCar�� �ʱ� �ӵ��� 20�̰�, ���� 2�Դϴ�."
		<< "\nyourCar�� �ʱ� �ӵ��� 15�̰�, ���� 3�Դϴ�." << endl;

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

	cout << "yourCar�� myCar�� ���� ���� �ð��� " << time << " �� �Դϴ�.\n"
		<< "myCar�� �̵� �Ÿ��� " << wheremyCar
		<< "\nyourCar�� �̵� �Ÿ��� " << whereyourCar << endl;
 }