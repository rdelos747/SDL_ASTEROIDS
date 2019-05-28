#ifndef ASTEROID_CREATOR_H
#define ASTEROID_CREATOR_H

#include <vector>

#include "../../../SDL_LIBRARY/FUNCTIONS/ENGINE.h"
#include "asteroid.h"

class Asteroid;

class AsteroidCreator {

public:
	AsteroidCreator();
	void update();
	void removeAsteroid(Asteroid* a);

	std::vector<Asteroid*> asteroids;

private:
	Timer* timer = new Timer;
	int spawnTime = 1000;
};

#endif