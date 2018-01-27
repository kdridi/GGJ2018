#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class SpriteSheet
{
public:
  SpriteSheet(const std::string &);

  sf::IntRect	getId(unsigned int id) const;
  sf::IntRect 	getId(unsigned int id, const sf::IntRect &rect) const;

  sf::Texture	&getTexture()
  {return (this->img);}
  
private:

  sf::Texture	img;
};
