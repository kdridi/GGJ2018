#include <iostream>

#include "AttackObj.hpp"
#include "Collider.hpp"
#include "MonsterObj.hpp"
#include "MainObj.hpp"

AttackObj::AttackObj(int frame, bool friendly, MainObj *obj)
{
  this->frame = frame;
  this->friendly = friendly;
  this->obj = obj;
  this->collider = new Collider(sf::IntRect(0, 0, 30, 30), this);
}

bool AttackObj::update()
{
  Collider *test = this->collider->getTest(sf::Vector2f(0, 0));

  if (test != NULL)
    {
      if (this->friendly == true)
	{
	  MonsterObj *obj = dynamic_cast<MonsterObj *>(test->obj);

	  if (obj != NULL)
	    obj->live = false;
	}
      else
	{
	  MainObj *obj = dynamic_cast<MainObj *>(test->obj);

	  if (obj != NULL);
	  //TODO
	}
	
    }
  this->frame -= 1;
  if (this->frame <= 0)
    {
      if (this->obj != NULL)
	this->obj->setActive(true);
      return (false);
    }
  return (true);
}

void AttackObj::move(sf::Vector2f pos)
{
  this->collider->rect.left = pos.x;
  this->collider->rect.top = pos.y;
}
