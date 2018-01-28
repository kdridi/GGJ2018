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
	  Collider *c = this->collider->getTest(this->v);
	  MoveObj *m;
	  
	  if (c != NULL && (m = dynamic_cast<MoveObj *>(c->obj)) != NULL)
	    {
	      m->lauch(this->obj, this->v);
	      this->step += 1;
	    }
	  else
	    {
	      this->step = 64 - this->step;
	      this->step += 1;
	      this->v = sf::Vector2f(this->v.x * -1, this->v.y * -1);
	      this->state = 2;
	    }
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

bool ShareObj::canLauch(sf::Vector2f v) const
{
  if (this->collider->test(v) == true)
    {
      Collider *c = this->collider->getTest(v);
      MoveObj *m;
      
      if (c != NULL && (m = dynamic_cast<MoveObj *>(c->obj)) != NULL)
	{
	  if (m->canLauch(v) == true)
	    return (true);
	  else
	    return (false);
	}
      else
	return (false);
    }
  return (true);
}

void ShareObj::lauch(MainObj *obj, sf::Vector2f v)
{
  if (this->state != 0)
    return;
  if (this->canLauch(v) == false)
    return;

  Collider *c = this->collider->getTest(v);
  MoveObj *m;
      
  if (c != NULL && (m = dynamic_cast<MoveObj *>(c->obj)) != NULL)
    m->lauch(obj, v);

  this->state = 1;
  MainObj::PA->setActive(false);
  MainObj::PB->setActive(false);

  this->obj = obj;
  this->v = v;
  this->step = 64;
  ShareObj::lauchAll(obj, v);
}
