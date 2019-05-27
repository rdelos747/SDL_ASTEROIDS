#include <iostream>
#include "../SDL_LIBRARY/FUNCTIONS/ENGINE.h"
#include "./classes/ship/ship.h"

void addSprites() {
	ENGINE.addSprite("ship", "./assets/ship.png");
}

void setup() {
	addSprites();

	Ship* ship = new Ship(100, 100);
	ENGINE.addObject(ship);
}

int main(int argc, char* args[]) {
	if (!ENGINE.init()) {
		printf("Failed to init\n");
	} else {
		setup();
		bool runGame = true;
		while(runGame) {
			runGame = ENGINE.update();
		}
	}

	ENGINE.close();
	return 0;
}