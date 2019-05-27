#include "ship.h"

Ship::Ship(int startX, int startY) {
  setSprite("ship");
  center.x = floor(getSpriteSize().w / 2);
  center.y = floor(getSpriteSize().h / 2);
  x = startX;
  y = startY;
}

Ship::~Ship() {}

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

  int minX = ENGINE.camera.x;
  int maxX = minX + ENGINE.getScreenSize().w;
  int minY = ENGINE.camera.y;
  int maxY = minY + ENGINE.getScreenSize().h;

	if (x - center.x > maxX && xSpeed > 0) {
		x = minX - center.x;
	} else if (x + center.x < minX && xSpeed < 0) {
		x = maxX + center.x;
	}
	if (y - center.y > maxY && ySpeed > 0) {
		y = minX - center.y;
	} else if (y + center.y < minY && ySpeed < 0) {
		y = maxY + center.y;
	}
}

void Ship::keyDown(int k) {
  switch(k) {
    case SDLK_RIGHT:
      dir += dirAmount;
      break;
    case SDLK_LEFT:
      dir -= dirAmount;
      break;
    case SDLK_UP:
      thrust = true;
      break;
  }
}

void Ship::keyUp(int k) {
  switch(k) {
    case SDLK_RIGHT:
      dir -= dirAmount;
      break;
    case SDLK_LEFT:
      dir += dirAmount;
      break;
    case SDLK_UP:
      thrust = false;
  }
}