//
//  Sound.hpp
//  myproject
//
//  Created by Karim DRIDI on 28/01/2018.
//

#ifndef Sound_hpp
#define Sound_hpp

#include <stdio.h>
#include <array>

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>

class Sound
{
public:
    Sound();
    
    enum Sound_Type
    {
        ELECTRIC_BOW = 0,
        ADULT_GETS_HURT = 1,
        CHILDREN_GETS_HURT = 2,
        ARROW_IN_BODY = 3,
        ARROW_IN_WALL = 4,
        GAIN_SKILL = 5,
        LOOT_COIN = 6,
        LOSE_INVENTORY = 7,
        GO_SMALL = 8,
    };
    
    enum Music_Type
    {
        MUSIC_MONSTER,
        MUSIC_PUZZLE,
    };
    
    void play_sound(Sound_Type id);
    void stop_sound(Sound_Type id);
    void play_music(Music_Type id);
    void stop_music(Music_Type id);

    
private:
    std::array<sf::SoundBuffer, 50> _sounds;
    sf::Sound sound;
    sf::Music music;
};

#endif /* Sound_hpp */
