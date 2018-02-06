#ifndef BULLET_H
#define BULLET_H

#include "../../SDL_LIBRARY/FUNCTIONS/FUNCTIONS.h"

class Bullet: public Object {
public:
	Bullet(float newX, float newY, int newDir);
	~Bullet();
	void update();

private:
	int bulletSpeed = 5;
	float xSpeed;
	float ySpeed;
};

#endif