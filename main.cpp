#include <iostream>
#include "../SDL_LIBRARY/FUNCTIONS/ENGINE.h"

class Test: public Object {
public:
	bool moving = true;

	Test(int startY) {
		//engine.addSprite("../SDL_ASTEROIDS/ASSETS/asteroid_large01.png");
		y = startY;
	}

	void update() {
		if (moving) {
			x += 1;
		}
	}

	void keyDown(int k) {
		switch(k) {
			case SDLK_UP: 
				moving = false; 
				setSprite("al02");
				break;
		}
	}

	void keyUp(int k) {
		switch(k) {
			case SDLK_UP:
				moving = true;
				setSprite("al01");
				break;
		}
	}
};

class TextTest: public Object {
public:
	TextTest(TTF_Font* f) {
		x = 10;
		y = 10;
		linkFont(f);
	}

	void update() {
		setText("heyo", {255,255,255});
	}
};


void setup() {
	ENGINE.addSprite("al01", "./ASSETS/asteroid_large01.png");
	ENGINE.addSprite("al02", "./ASSETS/asteroid_small01.png");
	TTF_Font* testFont = ENGINE.addFont("./ShareTechMono-Regular.ttf", 10);

	Test* test = new Test(0);
	test->setSprite("al01");
	ENGINE.addObject(test);

	Test* test2 = new Test(100);
	test2->setSprite("al01");
	ENGINE.addObject(test2);


	TextTest* tt = new TextTest(testFont);
	ENGINE.addObject(tt);
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