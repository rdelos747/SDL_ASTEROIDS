#include "asteroidCreator.h"

AsteroidCreator::AsteroidCreator() {
	timer->start();
}

void AsteroidCreator::update() {
	int ticks = timer->getTicks();
	if(ticks >= spawnTime) {
		timer->stop();
		timer->start();

		Size screenSize = ENGINE.getScreenSize();
		int x = rand() % screenSize.w;
		int y = rand() % screenSize.h;
		int direction = rand() % 360;
		
		Asteroid* a = new Asteroid(x, y, direction);
		ENGINE.addObject(a);
	}
}