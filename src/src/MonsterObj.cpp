#include <cstdlib>
#include "MonsterObj.hpp"
#include "SpriteSheet.hpp"
#include "SpriteObj.hpp"
#include "MainObj.hpp"

MonsterObj::MonsterObj(SpriteSheet &sp, unsigned int id) : SpriteObj(sp, id)
{
    this->rect = sf::IntRect(0, 0, 50, 122);
    this->addCollider(sf::IntRect(0, 0, 50, 50));
    this->sprite.setTextureRect(this->spriteSheet.getId(id, this->rect));
    this->randFrame = 0;
}

float s(float f)
{
    if (f < 0)
        return (-1);
    return (1);
}

bool MonsterObj::update()
{
  sf::Vector2f vec = MainObj::PA->getPos() - this->getPos();
    
  // if (abs(vec.x) < abs(vec.y))
  if (this->randFrame == 0 && std::rand() % 150 == 0)
    {
      this->randFrame = 20 + std::rand() % 100;
      this->v = sf::Vector2f((std::rand() % 3) - 1,
  			     (std::rand() % 3) - 1);
    }
  else if (randFrame == 0)
    this->v = sf::Vector2f(s(vec.x), s(vec.y));
  else
    this->randFrame -= 1;
  // else
  //   this->v = sf::Vector2f(0, -s(vec.y));
    
  if (this->collider != nullptr)
    {
      if (this->collider->test(this->v) == false)
	move(this->v);
      else
	{
	  Collider *c = this->collider->getTest(this->v);
	  if (c != nullptr)
	    {
	      MainObj *m = dynamic_cast<MainObj *>(c->obj);

	      if (m != NULL)
		m->takeDmg();
	    }
	}
    }
  return (GameObj::update());
}

void MonsterObj::move(sf::Vector2f pos)
{
    sf::Vector2f v = this->sprite.getPosition();
    sf::Vector2f size = sf::Vector2f(this->sprite.getTextureRect().width,
                                     this->sprite.getTextureRect().height);

    // pos.y -= size.y;
    if (this->collider != NULL)
    {
        this->collider->rect.top = v.y + pos.y + (size.y - size.x);
        this->collider->rect.left = v.x + pos.x;
    }
    this->sprite.setPosition(v.x + pos.x, v.y + pos.y);
}

void MonsterObj::moveAt(sf::Vector2f pos)
{
    sf::Vector2f size = sf::Vector2f(this->sprite.getTextureRect().width,
                                     this->sprite.getTextureRect().height);
    
    if (this->collider != NULL)
    {
        this->collider->rect.top = pos.y + (size.y - size.x);
        this->collider->rect.left = pos.x;
    }
    this->sprite.setPosition(pos.x, pos.y);
}

