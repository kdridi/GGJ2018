#pragma once

#include <SFML/Graphics.hpp>

class SpriteSheet;

class GameObj
{
public:
    GameObj(SpriteSheet &, unsigned int id);
    ~GameObj() = default;
    
    void draw() const;
    void move(sf::Vector2f pos);
    
private:
    sf::Sprite sprite;
    SpriteSheet& spriteSheet;
};

