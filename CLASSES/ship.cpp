#include "ship.h"
#include "bullet.h"

Ship::Ship() {
	printf(" --SHIP CONSTRUCTOR\n");
	x = floor(SCREEN_WIDTH / 2);
	y = floor(SCREEN_HEIGHT / 2);
	center.x = 20;
	center.y = 20;
	dir = 0;
	dirAmount = 5;
	xSpeed = 0;
	ySpeed = 0;
	accel = 0.05;
	maxSpeed = 3;
	thrust = false;
	shoot = false;
	addSprite("ASSETS/ship.png");
}

Ship::~Ship() {
	printf(" --SHIP DESTRUCTOR\n");
}

void Ship::update() {
	direction += dir;

	if (thrust) {
		if (xSpeed > maxSpeed) {
			xSpeed = maxSpeed;
		} else if (xSpeed < -maxSpeed) {
			xSpeed = -maxSpeed;
		} else {
			xSpeed += (cos(direction * (PI / 180)) * accel);
		}

		if (ySpeed > maxSpeed) {
			ySpeed = maxSpeed;
		} else if (ySpeed < -maxSpeed) {
			ySpeed = -maxSpeed;
		} else {
			ySpeed += (sin(direction * (PI / 180)) * accel);
		}
	}

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

	if (shoot) {
		shoot = false;
		Bullet* b = new Bullet(x, y, direction);
		//b->Object::addSprite("ASSETS/bullet.png");
		OBJECTS.push_back(b);
	}
}

void Ship::keyDown(int k) {
	switch(k) {
		case SDLK_RIGHT: dir += dirAmount; break;
		case SDLK_LEFT: dir -= dirAmount; break;
		case SDLK_UP: thrust = true; break;
		case SDLK_SPACE: shoot = true;
	}
}

void Ship::keyUp(int k) {
	switch(k) {
		case SDLK_RIGHT: dir -= dirAmount; break;
		case SDLK_LEFT: dir += dirAmount; break;
		case SDLK_UP: thrust = false; break;
	}
}