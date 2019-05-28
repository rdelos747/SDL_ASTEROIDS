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
		
		Asteroid* a = new Asteroid(this, x, y, direction);
		asteroids.push_back(a);
		ENGINE.addObject(a);
	}

	for (int i = 0; i < asteroids.size(); i++) {
		asteroids[i]->update();
	}
}

void AsteroidCreator::removeAsteroid(Asteroid* a) {
	for (int i = 0; i < asteroids.size(); i++) {
			if (asteroids[i] == a) {
				asteroids.erase(asteroids.begin() + i);
			}
		}
}