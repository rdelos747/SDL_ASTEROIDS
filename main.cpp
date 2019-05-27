#include <iostream>
#include "../SDL_LIBRARY/FUNCTIONS/ENGINE.h"

void setup() {
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