#include <iostream>
#include "../SDL_LIBRARY/FUNCTIONS/ENGINE.h"
#include "./classes/asteroid/asteroid.h"
#include "./classes/asteroid/asteroidCreator.h"
#include "./classes/ship/ship.h"

void addSprites() {
	ENGINE.addSprite("ship", "./assets/ship.png");
	ENGINE.addSprite("a1", "./ASSETS/asteroid_large01.png");
}

AsteroidCreator* ac;
void setup() {
	addSprites();

	Ship* ship = new Ship(100, 100);
	ENGINE.addObject(ship);

	ac = new AsteroidCreator;
}

void update() {
	ac->update();
}

int main(int argc, char* args[]) {
	if (!ENGINE.init()) {
		printf("Failed to init\n");
	} else {
		setup();
		bool runGame = true;
		while(runGame) {
			update();
			runGame = ENGINE.update();
		}
	}

	ENGINE.close();
	return 0;
}