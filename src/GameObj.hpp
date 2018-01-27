#pragma once

#include <SFML/Graphics.hpp>


// class SpriteSheet;

class GameObj
{
public:
    virtual ~GameObj() = default;
    
    virtual void draw() const;
    virtual bool update();
    virtual void move(sf::Vector2f pos);
};

