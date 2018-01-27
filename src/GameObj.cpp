#include "GameObj.hpp"
#include "Engine.hpp"
#include "SpriteSheet.hpp"

GameObj::GameObj(SpriteSheet &sp) : spriteSheet(sp)
{
  this->sprite.setTexture(this->spriteSheet.getTexture());
}

GameObj::GameObj(SpriteSheet &sp, unsigned int id) : spriteSheet(sp)
{
    this->sprite.setTexture(this->spriteSheet.getTexture());
    this->sprite.setTextureRect(this->spriteSheet.getId(id));
}

void GameObj::draw() const
{
    Engine::current->getWindow().draw(this->sprite);
}

bool GameObj::update()
{
  return (true);
}

void GameObj::move(sf::Vector2f pos)
{
    this->sprite.setPosition(pos);
}

