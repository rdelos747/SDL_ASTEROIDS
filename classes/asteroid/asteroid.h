#ifndef ASTEROID_H
#define ASTEROID_H

#include "../../../SDL_LIBRARY/FUNCTIONS/ENGINE.h"

class Asteroid: public Object {

public:
	Asteroid(int x, int y, int direction);

	void update();
};

#endif