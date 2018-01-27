#include "SpriteObj.hpp"
#include "Engine.hpp"
#include "SpriteSheet.hpp"

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
  return (true);
}

void SpriteObj::move(sf::Vector2f pos)
{
    this->sprite.setPosition(pos);
}

