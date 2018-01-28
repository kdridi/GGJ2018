#pragma once

#include "GameObj.hpp"
#include "Collider.hpp"
#include "MainObj.hpp"

class AttackObj : public GameObj
{
public:
  AttackObj(int frame, bool friendly, MainObj *obj);

  bool update();
  void move(sf::Vector2f pos);
  
private:
  int frame;
  bool friendly;
  Collider *collider;
  MainObj *obj;
};
