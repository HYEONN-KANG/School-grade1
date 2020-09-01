#include <iostream>
#include <Windows.h>
#include "car.h"

int main() {
	using namespace std;

	car myCar, yourCar; // ��ü ���� ����

	// set gear and speed
	myCar.setSpeed(20);
	myCar.setGear(2);

	yourCar.setSpeed(15);
	yourCar.setGear(3);

	int time = 0;
	while (true) {
		Sleep(1000);
		time++;
		myCar.setDistance(myCar.getSpeed());
		yourCar.setDistance(yourCar.getSpeed());

		myCar.speedUp();
		yourCar.speedUp();

		if (myCar.getDistance() <= yourCar.getDistance()) {
			break;
		}
	}

	cout << time << " �� �Ŀ� yourCar�� myCar�� ������ҽ��ϴ�.\n";
	cout << "myCar �̵��Ÿ�: " << myCar.getDistance() <<
		"\tyourCar �̵��Ÿ�: " << yourCar.getDistance() << "\n" <<
		"myCar speed: " << myCar.getSpeed() <<
		"\t\tyourCar speed: " << yourCar.getSpeed() << "\n";

	return 0;
}