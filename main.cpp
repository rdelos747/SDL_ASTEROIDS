#include <iostream>
#include "../SDL_LIBRARY/FUNCTIONS/ENGINE.h"
#include "./classes/asteroid/asteroid.h"
#include "./classes/asteroid/asteroidCreator.h"

AsteroidCreator* ac;
void setup() {
	ac = new AsteroidCreator;

	ENGINE.addSprite("a1", "./ASSETS/asteroid_large01.png");
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