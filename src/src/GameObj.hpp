#pragma once

#include <SFML/Graphics.hpp>

#include "Collider.hpp"

// class SpriteSheet;

class GameObj
{
public:
    GameObj();
    virtual ~GameObj() = default;
    
    virtual void draw() const;
    virtual bool update();
    virtual void event(sf::Event &);
    virtual void move(sf::Vector2f pos);

    virtual void addCollider(const sf::IntRect &);

    virtual int getY() const;
  bool	live;
protected:
  Collider *collider;
};

