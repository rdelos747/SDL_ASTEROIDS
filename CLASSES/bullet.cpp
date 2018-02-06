#include "bullet.h"

Bullet::Bullet(float newX, float newY, int newDir) {
	x = newX;
	y = newY;
	direction = newDir;
	//printf(" --Bullet CONSTRUCTOR\n");
	xSpeed = (cos(direction * (PI / 180)) * bulletSpeed);
	ySpeed = (sin(direction * (PI / 180)) * bulletSpeed);
	addSprite("ASSETS/bullet.png");
}

Bullet::~Bullet() {
	//printf(" --Bullet DESTRUCTOR\n");
}

void Bullet::update() {
	x += xSpeed;
	y += ySpeed;

	if (x > SCREEN_WIDTH || x < 0 || y > SCREEN_HEIGHT || y < 0) {
		selfDestroy();
	}

	// check collisions with asteroids (collison layer 1)
	Object* foundOBJ = COLLISION_AT_POINT(x, y, 1);
	if (foundOBJ != NULL) {
		Asteroid* a = (Asteroid *)foundOBJ->gotHit
		foundOBJ->selfDestroy();
		selfDestroy();
	}
}