#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include <vector>
#include <string>
#include <SFML/Audio.hpp>

//////////////////////////////////////////////////
/// Manage sound playing in the game
//////////////////////////////////////////////////
class AudioEngine
{
    public:
        void playSound(const std::string& name, float volume = 100.f);

    private:

        AudioEngine();
        ~AudioEngine();

        std::vector<sf::Sound> mySounds;
        unsigned int           myNextSoundId;

        static const int MAX_SOUNDS = 64;

        friend class Game;
};

#endif // AUDIOENGINE_H