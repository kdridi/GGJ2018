#include "MoveObj.hpp"
#include "SpriteObj.hpp"
#include "Engine.hpp"
#include "SpriteSheet.hpp"
#include "Collider.hpp"
#include "ColliderMap.hpp"
#include "MainObj.hpp"

MoveObj::MoveObj(SpriteSheet &sp) : SpriteObj(sp)
{
  this->obj = NULL;
  this->addCollider(sf::IntRect(0, 0, 64, 64));
  this->step = 0;
  this->state = 0;
}

MoveObj::MoveObj(SpriteSheet &sp, unsigned int id) : SpriteObj(sp, id)
{
  this->obj = NULL;
  this->addCollider(sf::IntRect(0, 0, 64, 64));
  this->step = 0;
  this->state = 0;
}

bool MoveObj::update()
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
      this->obj->setActive(true);
      this->state = 0;
      obj = NULL;
    }
  return (true);
}

void MoveObj::lauch(MainObj *obj, sf::Vector2f v)
{
  if (this->state != 0)
    return;
  this->state = 1;
  this->obj = obj;
  this->obj->setActive(false);
  this->v = v;
  this->step = 64;
}