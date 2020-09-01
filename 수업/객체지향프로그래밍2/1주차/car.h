#pragma once
class car
{
public:
	int getSpeed();
	void setSpeed(int);
	void setGear(int);
	void speedUp();		// 가속하는 함수, speed+gear
	void setDistance(int);
	int getDistance();

private:
	int speed;
	int gear;
	int distance = 0;
};