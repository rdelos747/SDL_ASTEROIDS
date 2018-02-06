#include "../SDL_LIBRARY/FUNCTIONS/FUNCTIONS.h"
#include "CLASSES/asteroidCreator.h"
#include "CLASSES/asteroid.h"
#include "CLASSES/bullet.h"
#include "CLASSES/ship.h"


void setup() {
	Ship* ship = new Ship();
	OBJECTS.push_back(ship);

	AsteroidCreator* ac = new AsteroidCreator();
	OBJECTS.push_back(ac);
}

int main(int argc, char* args[]) {
	if (!SDL_INIT()) {
		printf("Failed to init\n");
	} else {
		setup();
		bool runGame = true;
		while(runGame) {
			/*
				For now, all classes will be children of Object,
				but doing it this way allows for user to add their own
				items to the update.
				Maybe thats a bad idea?
			*/
			runGame = GAME_UPDATE();
		}
	}

	SDL_CLOSE();
	return 0;
}