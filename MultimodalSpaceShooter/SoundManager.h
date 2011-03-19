#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include "ResourceManager.h"
#include <SFML/Audio.hpp>

class SoundManager : public ResourceManager<sf::SoundBuffer>
{
    public:
        virtual std::shared_ptr<sf::SoundBuffer> load(const std::string& name);
        
    private:
        SoundManager(const std::string& resourcePath = "./");
        ~SoundManager();

        friend class Game;
};

#endif // SOUNDMANAGER_H