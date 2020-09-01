#pragma once

#ifndef CAR_H
#define CAR_H

class Car {
public:
	void getSpeed(int);
	int setSpeed();
	void setGear(int);
	void speedUp();

private:
	int speed;
	int gear;
};

#endif // !CAR_H