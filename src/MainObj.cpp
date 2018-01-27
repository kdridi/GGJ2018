#include <iostream>

#include "MainObj.hpp"
#include "ColliderMap.hpp"
#include "SpriteSheet.hpp"

MainObj::MainObj(int idJ, SpriteSheet &s, unsigned int id) : SpriteObj(s, id)
{
    this->idJ = idJ;
    this->v = sf::Vector2f(0, 0);
    this->addCollider(sf::IntRect(0, 0, 50, 50));
    this->sprite.setTextureRect(this->spriteSheet.getId(id, sf::IntRect(0, 0, 50, 80)));
}

void MainObj::draw() const
{
    SpriteObj::draw();
}

void MainObj::event(sf::Event &e)
{
  float f = 5.5;
  
    if (this->idJ == 1)
    {
        if (e.type == sf::Event::KeyPressed)
        {
            if (e.key.code == sf::Keyboard::Up)
            {
	        this->sprite.setTextureRect(this->spriteSheet.getId(1, sf::IntRect(0, 0, 50, 80)));
                this->v = sf::Vector2f(0, -f);
                this->idK = 0;
            }
            if (e.key.code == sf::Keyboard::Down)
            {
	        this->sprite.setTextureRect(this->spriteSheet.getId(0, sf::IntRect(0, 0, 50, 80)));
                this->v = sf::Vector2f(0, f);
                this->idK = 1;
            }
            if (e.key.code == sf::Keyboard::Left)
            {
	        this->sprite.setTextureRect(this->spriteSheet.getId(2, sf::IntRect(0, 0, 50, 80)));
                this->v = sf::Vector2f(-f, 0);
                this->idK = 2;
            }
            if (e.key.code == sf::Keyboard::Right)
            {
	        this->sprite.setTextureRect(this->spriteSheet.getId(3, sf::IntRect(0, 0, 50, 80)));
                this->v = sf::Vector2f(f, 0);
                this->idK = 3;
            }
        }
        else if (e.type == sf::Event::KeyReleased)
        {
            if (e.key.code == sf::Keyboard::Up && this->idK == 0)
                this->v = sf::Vector2f(0, 0);
            if (e.key.code == sf::Keyboard::Down && this->idK == 1)
                this->v = sf::Vector2f(0, 0);
            if (e.key.code == sf::Keyboard::Left && this->idK == 2)
                this->v = sf::Vector2f(0, 0);
            if (e.key.code == sf::Keyboard::Right && this->idK == 3)
                this->v = sf::Vector2f(0, 0);
        }
    }
    else if (this->idJ == 2)
    {
        if (e.type == sf::Event::KeyPressed)
        {
            if (e.key.code == sf::Keyboard::Z)
            {
	        this->sprite.setTextureRect(this->spriteSheet.getId(1, sf::IntRect(0, 0, 50, 80)));
                this->v = sf::Vector2f(0, -f);
                this->idK = 0;
            }
            if (e.key.code == sf::Keyboard::S)
            {
	        this->sprite.setTextureRect(this->spriteSheet.getId(0, sf::IntRect(0, 0, 50, 80)));
                this->v = sf::Vector2f(0, f);
                this->idK = 1;
            }
            if (e.key.code == sf::Keyboard::Q)
            {
	        this->sprite.setTextureRect(this->spriteSheet.getId(2, sf::IntRect(0, 0, 50, 80)));
                this->v = sf::Vector2f(-f, 0);
                this->idK = 2;
            }
            if (e.key.code == sf::Keyboard::D)
            {
	        this->sprite.setTextureRect(this->spriteSheet.getId(3, sf::IntRect(0, 0, 50, 80)));
                this->v = sf::Vector2f(f, 0);
                this->idK = 3;
            }
        }
        else if (e.type == sf::Event::KeyReleased)
        {
            if (e.key.code == sf::Keyboard::Z && this->idK == 0)
                this->v = sf::Vector2f(0, 0);
            if (e.key.code == sf::Keyboard::S && this->idK == 1)
                this->v = sf::Vector2f(0, 0);
            if (e.key.code == sf::Keyboard::Q && this->idK == 2)
                this->v = sf::Vector2f(0, 0);
            if (e.key.code == sf::Keyboard::D && this->idK == 3)
                this->v = sf::Vector2f(0, 0);
        }
    }
}

bool MainObj::update()
{
    sf::Vector2f pos = this->sprite.getPosition();
    
    pos.y += 30;
    ColliderMap::test = this->collider;
    if (ColliderMap::current->isCollide({pos.x + v.x, pos.y + v.y}) == false)
        if (ColliderMap::current->isCollide({pos.x + 50 + v.x, pos.y + v.y}) == false)
            if (ColliderMap::current->isCollide({pos.x + v.x, pos.y + 50 + v.y}) == false)
                if (ColliderMap::current->isCollide({pos.x + 50 + v.x, pos.y + 50 + v.y}) == false)
                    this->move(v);
    
    return (SpriteObj::update());
}

void MainObj::move(sf::Vector2f pos)
{
    SpriteObj::move(pos);
}

