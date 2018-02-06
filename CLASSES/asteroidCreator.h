#ifndef ASTEROIDCREATOR_H
#define ASTEROIDCREATOR_H

#include "../../SDL_LIBRARY/FUNCTIONS/FUNCTIONS.h"
#include "asteroid.h"

class AsteroidCreator: public Object {
public:
	AsteroidCreator();
	~AsteroidCreator();
	void update();

private:
	int currentTime;
	int maxTime;
};

#endif