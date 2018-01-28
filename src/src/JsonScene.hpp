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
    JsonScene(Engine& engine, std::string const& name)
    : Scene(engine)
    , room(utils::getRoomInformations(name))
    {
    }
    
    virtual void init();
private:
    nlohmann::json const& room;
};

#endif /* JsonScene_hpp */

