#include <iostream>

#include "SpriteObj.hpp"
#include "Engine.hpp"
#include "SpriteSheet.hpp"
#include "Collider.hpp"
#include "ColliderMap.hpp"

SpriteObj::SpriteObj(SpriteSheet &sp)
: spriteSheet(sp)
{
  this->sprite.setTexture(this->spriteSheet.getTexture());
  this->collider = NULL;
}

SpriteObj::SpriteObj(SpriteSheet &sp, unsigned int id)
: spriteSheet(sp)
{
    this->sprite.setTexture(this->spriteSheet.getTexture());
    this->sprite.setTextureRect(this->spriteSheet.getId(id));
    this->collider = NULL;
}

void SpriteObj::draw() const
{
    Engine::current->getWindow().draw(this->sprite);
}

bool SpriteObj::update()
{
  return (GameObj::update());
}

void SpriteObj::move(sf::Vector2f pos)
{
  sf::Vector2f v = this->sprite.getPosition();
  if (this->collider != NULL)
    {
      this->collider->rect.top = v.y + pos.y;
      this->collider->rect.left = v.x + pos.x;
    }
  this->sprite.setPosition(v.x + pos.x, v.y + pos.y);
}

void SpriteObj::addCollider(const sf::IntRect &rect)
{
  if (this->collider != NULL)
    {
      ColliderMap::current->delleteCollider(this->collider);
      std::cout << "delete" << std::endl;
      delete this->collider;
    }
  this->collider = new Collider(rect, this);
  ColliderMap::current->addCollider(this->collider);
}

int SpriteObj::getY() const
{
  sf::Vector2f pos = this->sprite.getPosition();

  pos.y += this->sprite.getTextureRect().top;
  return (pos.y);
}
