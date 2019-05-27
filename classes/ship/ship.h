#ifndef SHIP_H
#define SHIP_H

#include "../../../SDL_LIBRARY/FUNCTIONS/ENGINE.h"

class Ship: public Object {
public:
  Ship(int startX, int startY);
  ~Ship();
  void update();
  //void keyDown(int k);
  //void keyUp(int k);

private:
  int dirAmount = 5;
};

#endif