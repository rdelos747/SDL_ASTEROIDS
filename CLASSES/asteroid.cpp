#include "asteroid.h"

Asteroid::Asteroid(int startX, int startY) {
	asteroidSpeed = 1;
	x = startX;
	y = startY;
	center.x = 20;
	center.y = 20;
	addSprite("ASSETS/asteroid_large01.png");

	collisionLayer = 1;

	direction = RAND_INT(365);
	xSpeed = (cos(direction * (PI / 180)) * asteroidSpeed);
	ySpeed = (sin(direction * (PI / 180)) * asteroidSpeed);
}

Asteroid::~Asteroid(){}

void Asteroid::update() {
	x += xSpeed;
	y += ySpeed;

	if (x - center.x > SCREEN_WIDTH && xSpeed > 0) {
		x = -center.x;
	} else if (x + center.x < 0 && xSpeed < 0) {
		x = SCREEN_WIDTH + center.x;
	}
	if (y - center.y > SCREEN_HEIGHT && ySpeed > 0) {
		y = -center.y;
	} else if (y + center.y < 0 && ySpeed < 0) {
		y = SCREEN_HEIGHT + center.y;
	}
}

void Asteroid::gotHit() {
	printf("i died\n");
}