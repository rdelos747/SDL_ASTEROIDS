#ifndef SHIP_H
#define SHIP_H

#include "../../SDL_LIBRARY/FUNCTIONS/FUNCTIONS.h"

class Ship: public Object {
public:
	Ship();
	~Ship();
	void update();
	void keyDown(int k);
	void keyUp(int k);

private:
	int dirAmount;
	int dir;
	bool thrust;
	bool shoot;
	float xSpeed;
	float ySpeed;
	float accel;
	int maxSpeed;
};

#endif