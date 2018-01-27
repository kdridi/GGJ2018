#pragma once

#include <list>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

class GameObj;

class Scene
{
public:
  Scene();
  virtual ~Scene();

  bool			init();
  bool			draw();
  
private:

  std::list<GameObj *>	objList;
};
