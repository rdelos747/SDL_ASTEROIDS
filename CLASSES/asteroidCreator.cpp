#include "asteroidCreator.h"

AsteroidCreator::AsteroidCreator() {
	//printf("ac construct\n");
	currentTime = 400;
	maxTime = 500;
}

AsteroidCreator::~AsteroidCreator() {
	//printf("ac destruct\n");
}

void AsteroidCreator::update() {
	currentTime++;
	if (currentTime >= maxTime) {
		currentTime = 0;

		int randX = RAND_INT(SCREEN_WIDTH);
		int randY = RAND_INT(SCREEN_HEIGHT);

		//printf("make asteroid at %d, %d\n", randX, randY);

		Asteroid* a = new Asteroid(randX, randY);
		OBJECTS.push_back(a);
	}
}