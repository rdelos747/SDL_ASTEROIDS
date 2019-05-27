#include "asteroid.h"
#include <math.h>

Asteroid::Asteroid(int x, int y, int direction) {
	this->x = x;
	this->y = y;
	this->direction = direction;
	
	setSprite("a1");
}

void Asteroid::update() {
	float radians = (float)direction / 360 * 2 * M_PI;

	float dx = cos(radians);
	float dy = sin(radians);

	x += dx;
	y += dy;
}