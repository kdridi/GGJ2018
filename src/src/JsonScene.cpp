//
//  JsonScene.cpp
//  myproject
//
//  Created by Karim DRIDI on 27/01/2018.
//

#include "JsonScene.hpp"
#include "SpriteObj.hpp"
#include "Engine.hpp"
#include "ColliderMap.hpp"
#include "MainObj.hpp"

#include <iostream>

void JsonScene::init()
{
#ifdef NDEBUG
#else
    std::cout << std::setw(4) << room << std::endl;
#endif
    
    for (auto const& layer : room.at("layers"))
    {
        auto const& name { layer.value("name", "") };
        
        if (name.compare("objects") == 0)
        {
            auto const& objects{ layer["objects"] };
            
            for (auto const& object : objects)
            {
                auto const& type { object.value("type", "") };
                
                if (type.compare("spawn") == 0)
                {
                    auto const& name { object.value("name", "") };
                    if (name.compare("player") == 0)
                    {
                        auto const& size = object["properties"].value("size", "unmodified");
                        uint64_t id = object["properties"]["id"];
                        uint64_t w = object["width"];
                        uint64_t h = object["height"];
                        uint64_t x = object["x"];
                        uint64_t y = object["y"];
                        
                        uint64_t px = x + w / 2;
                        uint64_t py = y + h / 2;
                        bool big = size.compare("big") == 0;
                        bool* big_ptr = size.compare("unmodified") == 0 ? nullptr : &big;
                        
                        MainObj::updatePlayer(id, px, py, big_ptr);
                        push_back(2, id == 0 ? MainObj::PA : MainObj::PB);
                    }
                    else if (name.compare("enemyClose") == 0)
                    {
                        double damage = object["properties"]["damage"];
                        double hp = object["properties"]["hp"];
                        uint64_t x = object["x"];
                        uint64_t y = object["y"];
                        
                        pushEnemyCloseObj(x, y, damage, hp);
                    }
                    else if (name.compare("enemyAway") == 0)
                    {
                        double damage = object["properties"]["damage"];
                        double hp = object["properties"]["hp"];
                        uint64_t x = object["x"];
                        uint64_t y = object["y"];
                        
                        pushEnemyAwayObj(x, y, damage, hp);
                    }
                    else if (name.compare("enemyBoss") == 0)
                    {
                        double damage = object["properties"]["damage"];
                        double hp = object["properties"]["hp"];
                        uint64_t x = object["x"];
                        uint64_t y = object["y"];
                        
                        pushEnemyBossObj(x, y, damage, hp);
                    }
                    else if (name.compare("item") == 0)
                    {
                        std::string typeName = object["properties"]["type"];
                        Spells::Type type = Spells::SPELL_NONE;
                        
                        if (typeName.compare("bow") == 0)
                            type = Spells::SPELL_BOW;
                        else
                            throw "unknown item type";

                        uint64_t w = object["width"];
                        uint64_t h = object["height"];
                        uint64_t x = object["x"];
                        uint64_t y = object["y"];
                        
                        pushItemObj(x, y, w, h, type);
                    }
                    else
                    {
                        std::stringstream ss;
                        ss << "unknown spawn type: \"" << name << "\"";
                        std::string message{ss.str()};
                        throw message;
                    }
                }
                else if (type.compare("exit") == 0)
                {
                    auto const& name { object.value("name", "") };
                    uint64_t w = object["width"];
                    uint64_t h = object["height"];
                    uint64_t x = object["x"];
                    uint64_t y = object["y"];
                    
                    uint64_t enemyLock = 0;
                    uint64_t pressureLock = 0;
                    if (object.find("properties") != object.end())
                    {
                        if (object["properties"].find("pressureLock") != object["properties"].end())
                            pressureLock = object["properties"]["pressureLock"];

                        if (object["properties"].find("enemyLock") != object["properties"].end())
                            enemyLock = object["properties"]["enemyLock"];
                    }

                    pushExitObj(name, x, y, w, h, enemyLock, pressureLock);
                }
                else if (type.compare("pressure") == 0)
                {
                    PressureType type = PRESSURE_OPEN_DOOR;
                    
                    bool kid = true;
                    bool adult = true;
                    
                    std::string size = "";
                    std::string target = "";

                    if (object.find("properties") != object.end())
                    {
                        if (object["properties"].find("size") != object["properties"].end())
                            size = object["properties"]["size"];
                        
                        if (object["properties"].find("target") != object["properties"].end())
                            target = object["properties"]["target"];
                    }
                    
                    if (size.compare("") == 0)
                    {
                        kid = true;
                        adult = true;
                    }
                    else if (size.compare("kid") == 0)
                    {
                        kid = true;
                        adult = false;
                    }
                    else if (size.compare("adult") == 0)
                    {
                        kid = false;
                        adult = true;
                    }
                    else
                    {
                        std::stringstream ss;
                        ss << "unknown pressure.size: \"" << size << "\"";
                        std::string message{ss.str()};
                        std::cout << message << std::endl;
                        
                        throw message;
                    }
                        
                    auto const& pressureName { object.value("name", "") };
                    if (pressureName.compare("openDoor") == 0)
                    {
                        type = PRESSURE_OPEN_DOOR;
                    } else if (pressureName.compare("toogle") == 0)
                    {
                        type = PRESSURE_TOOGLE;
                    }
                    else
                    {
                        std::stringstream ss;
                        ss << "unknown pressureName: \"" << pressureName << "\"";
                        std::string message{ss.str()};
                        std::cout << message << std::endl;
                        
                        throw message;
                    }
                    
                    uint64_t x = object["x"];
                    uint64_t y = object["y"];
                    
                    pushPressureObj(type, x, y, kid, adult, target);
                }
                else if (type.compare("toogle") == 0)
                {
                    auto const& name { object.value("name", "") };
                    uint64_t x = object["x"];
                    uint64_t y = object["y"];
                    
                    SpriteType type = object["properties"]["type"];
                    pushToogleObj(name, x, y, type);
                }
                else
                {
                    std::stringstream ss;
                    ss << "unknown type: \"" << type << "\"";
                    std::string message{ss.str()};
                    std::cout << message << std::endl;
                    
                    throw message;
                }
            }
        }
        else if (name.compare("env") == 0)
        {
            uint64_t const& width{layer["width"]};
            uint64_t const& height{layer["height"]};
            
            auto const& data{ layer["data"] };
            
            for (uint64_t y = 0; y < height; ++y)
            {
                for (uint64_t x = 0; x < width; ++x)
                {
                    uint64_t id = data.at(y * width + x);
                    
                    switch (id) {
                        case SPRITE_NONE:
                            break;
                        case SPRITE_WALL:
                            pushWallObj(x, y);
                            break;
                        case SPRITE_STATIC:
                            pushStaticObj(x, y);
                            break;
                        case SPRITE_MOBILE:
                            pushMobileObj(x, y);
                            break;
                        case SPRITE_LINKED:
                            pushLinkedObj(x, y);
                            break;
                        case SPRITE_DOOR0:
                        case SPRITE_DOOR1:
                            pushDoorObj(x, y);
                            break;
                        case SPRITE_DOOR_SMALL:
                            pushDoorSmallObj(x, y);
                            break;
                        default:
                            throw "unknown object type";
                            break;
                    }
                }
            }
        }
        else
        {
            std::stringstream ss;
            ss << "unknown layer name: \"" << name << "\"";
            std::string message{ss.str()};
            throw message;
        }
    }
}

