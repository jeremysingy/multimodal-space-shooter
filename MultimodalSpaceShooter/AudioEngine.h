#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include <vector>
#include <SFML/Audio.hpp>
#include <string>

class AudioEngine
{
    public:
		void playSound(const std::string& name, float volume=75.f);
    
    private:
        AudioEngine();
        ~AudioEngine();
		
		std::vector<sf::Sound> mySounds;

        friend class Game;
};

#endif // AUDIOENGINE_H