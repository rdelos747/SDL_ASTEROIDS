#ifndef ASTEROID_H
#define ASTEROID_H

#include "../../SDL_LIBRARY/FUNCTIONS/FUNCTIONS.h"

class Asteroid: public Object {
public:
	Asteroid(int startX, int startY);
	~Asteroid();
	void update();

	void gotHit();

private:
	int asteroidSpeed;
	float xSpeed;
	float ySpeed;
};

#endif