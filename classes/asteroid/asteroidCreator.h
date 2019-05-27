#ifndef ASTEROID_CREATOR_H
#define ASTEROID_CREATOR_H

#include "../../../SDL_LIBRARY/FUNCTIONS/ENGINE.h"
#include "asteroid.h"

class AsteroidCreator {

public:
	AsteroidCreator();
	void update();

private:
	Timer* timer = new Timer;
	int spawnTime = 1000;
};

#endif