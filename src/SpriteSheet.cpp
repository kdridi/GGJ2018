#include "SpriteSheet.hpp"

SpriteSheet::SpriteSheet(const std::string &img)
{
    this->img.loadFromFile(img);
}

sf::IntRect SpriteSheet::getId(unsigned int id) const
{
    sf::IntRect rect(0, 0, 32, 32);
    
    return (this->getId(id, rect));
}

sf::IntRect SpriteSheet::getId(unsigned int id, const sf::IntRect &rect) const
{
    return (rect);
}

