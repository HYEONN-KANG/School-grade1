#pragma once
class car
{
public:
	int getSpeed();
	void setSpeed(int);
	void setGear(int);
	void speedUp();		// �����ϴ� �Լ�, speed+gear
	void setDistance(int);
	int getDistance();

private:
	int speed;
	int gear;
	int distance = 0;
};