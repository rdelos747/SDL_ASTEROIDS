#ifndef SHIP_H
#define SHIP_H

#include "../../../SDL_LIBRARY/FUNCTIONS/ENGINE.h"

class Ship: public Object {
public:
  Ship(int startX, int startY);
  ~Ship();
  void update();
  void keyDown(int k);
  void keyUp(int k);

private:
  int dirAmount = 5;
  int dir = 0;
  bool thrust = false;
  float xSpeed = 0;
	float ySpeed = 0;
	float accel = 0.05;
	int maxSpeed = 3;
};

#endif