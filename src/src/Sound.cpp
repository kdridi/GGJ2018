//
//  Sound.cpp
//  myproject
//
//  Created by Karim DRIDI on 28/01/2018.
//

#include "Sound.hpp"

#include "Utils.hpp"

#include <iostream>

Sound::Sound()
{
    this->_sounds[0].loadFromFile(utils::getFullPath("sound/electric_bow.ogg"));
    this->_sounds[1].loadFromFile(utils::getFullPath("sound/adult_gets_hurt.ogg"));
    this->_sounds[2].loadFromFile(utils::getFullPath("sound/children_gets_hurt.ogg"));
    this->_sounds[3].loadFromFile(utils::getFullPath("sound/arrow_in_body.ogg"));
    this->_sounds[4].loadFromFile(utils::getFullPath("sound/arrow_in_wall.ogg"));
    this->_sounds[5].loadFromFile(utils::getFullPath("sound/gain_skill.ogg"));
    this->_sounds[6].loadFromFile(utils::getFullPath("sound/loot_coin.ogg"));
    this->_sounds[7].loadFromFile(utils::getFullPath("sound/lose_inventory.ogg"));
    this->_sounds[7].loadFromFile(utils::getFullPath("sound/lose_inventory.ogg"));
    
}

void    Sound::play_sound(Sound_Type id)
{
    sound.setBuffer(this->_sounds[id]);
    sound.play();
}

void    Sound::stop_sound(Sound_Type id)
{
    std::cout << "STOP" << std::endl;
    sound.stop();
}

void    Sound::play_music(Music_Type id)
{
    if (id == 0)
    {
        music.openFromFile(utils::getFullPath("sound/music_monster.ogg"));
        music.play();
    }
    else if (id == 1)
    {
        music.openFromFile(utils::getFullPath("sound/music_puzzle.ogg"));
        music.play();
    }
}

void    Sound::stop_music(Music_Type id)
{
    if (id == 0)
    {
        music.stop();
    }
    else if (id == 1)
    {
        music.stop();
    }
}
