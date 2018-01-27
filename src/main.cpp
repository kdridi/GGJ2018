#include "Engine.hpp"

int main()
{
  Engine e;

  if (e.init() == false)
    return (1);
  while (e.update() == true);
  return (0);
}
