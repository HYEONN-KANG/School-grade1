#include <iostream>
#include <Windows.h>
#include "car.h"

int main()
{
	using namespace std;

	car myCar, yourCar; // 객체 변수 생성

	// set gear and speed
	myCar.setSpeed(20);
	myCar.setGear(2);

	yourCar.setSpeed(15);
	yourCar.setGear(3);

	int time = 0;
	while (true)
	{
		Sleep(1000);
		time++;
		myCar.setDistance(myCar.getSpeed());
		yourCar.setDistance(yourCar.getSpeed());

		myCar.speedUp();
		yourCar.speedUp();

		if (myCar.getDistance() <= yourCar.getDistance())
		{
			break;
		}
	}

	cout << time << " 초 후에 yourCar가 myCar를 따라잡았습니다.\n";
	cout << "myCar 이동거리: " << myCar.getDistance() << "\tyourCar 이동거리: " << yourCar.getDistance() << "\n"
		 << "myCar speed: " << myCar.getSpeed() << "\t\tyourCar speed: " << yourCar.getSpeed() << "\n";

	return 0;
}