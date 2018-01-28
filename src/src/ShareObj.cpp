#include <iostream>

#include "ShareObj.hpp"
#include "MoveObj.hpp"
#include "SpriteObj.hpp"
#include "Engine.hpp"
#include "SpriteSheet.hpp"
#include "Collider.hpp"
#include "ColliderMap.hpp"
#include "MainObj.hpp"

std::list<ShareObj *>	ShareObj::objList;

void ShareObj::lauchAll(MainObj *obj, sf::Vector2f v)
{
  for (auto s : ShareObj::objList)
    s->lauch(obj, v);
}

ShareObj::ShareObj(SpriteSheet &sp, unsigned int id) : MoveObj(sp, id)
{
  ShareObj::objList.push_back(this);
} 

ShareObj::~ShareObj()
{
  ShareObj::objList.remove(this);
}

bool ShareObj::update()
{
  if (this->step > 0)
    {
      if (this->collider != NULL && this->collider->test(this->v) == false)
	{
	  this->move(v);
	}
      else if (this->state == 1)
	{
	  this->step = 64 - this->step;
	  this->step += 1;
	  this->v = sf::Vector2f(this->v.x * -1, this->v.y * -1);
	  this->state = 2;
	}
      this->step -= 1;
    }
  else if (obj != NULL)
    {
      MainObj::PA->setActive(true);
      MainObj::PB->setActive(true);

      this->state = 0;
      obj = NULL;
    }
  return (true);
} 

void ShareObj::lauch(MainObj *obj, sf::Vector2f v)
{
  if (this->state != 0)
    return;
  this->state = 1;
  MainObj::PA->setActive(false);
  MainObj::PB->setActive(false);

  this->obj = obj;
  this->v = v;
  this->step = 64;
  ShareObj::lauchAll(obj, v);
}
