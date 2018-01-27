#include "SpriteSheet.hpp"

SpriteSheet::SpriteSheet(const std::string &img)
{
    this->img.loadFromFile(img);
}

sf::IntRect SpriteSheet::getId(unsigned int id) const
{
    sf::IntRect rect(0, 0, 64, 64);
    
    return (this->getId(id, rect));
}

sf::IntRect SpriteSheet::getId(unsigned int id, const sf::IntRect &rect) const
{
    sf::IntRect r;
    
    sf::Vector2u size = this->img.getSize();
    int l = (id * rect.width) / size.x;
    
    r.left = (id * rect.width) % size.x;
    r.top = (l) % size.y;
    r.width = rect.width;
    r.height = rect.height;
    return (rect);
}

