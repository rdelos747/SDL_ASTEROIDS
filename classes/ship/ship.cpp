#include "ship.h"

Ship::Ship(int startX, int startY) {
  setSprite("ship");
  center.x = floor(getSpriteSize().w / 2);
  center.y = floor(getSpriteSize().h / 2);
  x = startX;
  y = startY;
  direction = 0;

}

Ship::~Ship() {}

void Ship::update() {
  dirAmount = dirAmount+1;
}