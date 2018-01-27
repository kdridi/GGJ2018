//
//  JsonScene.hpp
//  myproject
//
//  Created by Karim DRIDI on 27/01/2018.
//

#ifndef JsonScene_hpp
#define JsonScene_hpp

#include "Scene.hpp"
#include "Utils.hpp"

class JsonScene : public Scene
{
public:
    JsonScene(std::string const& name)
    : Scene()
    , room(utils::getRoomInformations(name))
    {
    }
    
    virtual void init(Engine& engine);
private:
    nlohmann::json const& room;
};

#endif /* JsonScene_hpp */

