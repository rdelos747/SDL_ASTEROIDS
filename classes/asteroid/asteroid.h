#ifndef ASTEROID_H
#define ASTEROID_H

#include "../../../SDL_LIBRARY/FUNCTIONS/ENGINE.h"
#include "asteroidCreator.h"

class AsteroidCreator;

class Asteroid: public Object {

public:
	Asteroid(AsteroidCreator* ac, int x, int y, int direction);

	void update();

	AsteroidCreator* parent;
};

#endif