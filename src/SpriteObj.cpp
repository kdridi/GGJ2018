#include <iostream>

#include "SpriteObj.hpp"
#include "Engine.hpp"
#include "SpriteSheet.hpp"
#include "Collider.hpp"
#include "ColliderMap.hpp"

SpriteObj::SpriteObj(SpriteSheet &sp) : spriteSheet(sp)
{
  this->sprite.setTexture(this->spriteSheet.getTexture());
}

SpriteObj::SpriteObj(SpriteSheet &sp, unsigned int id) : spriteSheet(sp)
{
    this->sprite.setTexture(this->spriteSheet.getTexture());
    this->sprite.setTextureRect(this->spriteSheet.getId(id));
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
  std::cout << "coucou" << std::endl;
  this->collider = new Collider(rect, this);
  ColliderMap::current->addCollider(this->collider);
}
