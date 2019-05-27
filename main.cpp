#include <iostream>
#include "../SDL_LIBRARY/FUNCTIONS/ENGINE.h"

//Engine* engine = new Engine();

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
			case SDLK_UP: moving = false; break;
		}
	}

	void keyUp(int k) {
		switch(k) {
			case SDLK_UP: moving = true; break;
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
	Sprite* testSprite = engine.addSprite("./ASSETS/asteroid_large01.png");
	TTF_Font* testFont = engine.addFont("./ShareTechMono-Regular.ttf", 10);

	Test* test = new Test(0);
	test->linkSprite(testSprite);
	engine.addObject(test);

	Test* test2 = new Test(100);
	test2->linkSprite(testSprite);
	engine.addObject(test2);

	
	TextTest* tt = new TextTest(testFont);
	engine.addObject(tt);
}

int main(int argc, char* args[]) {
	if (!engine.init()) {
		printf("Failed to init\n");
	} else {
		setup();
		bool runGame = true;
		while(runGame) {
			runGame = engine.update();
		}
	}

	engine.close();
	return 0;
}