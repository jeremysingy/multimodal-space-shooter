#include "SoundManager.h"

SoundManager::SoundManager(const std::string& resourcePath) :
ResourceManager(resourcePath)
{
    
}

SoundManager::~SoundManager()
{
    
}

std::shared_ptr<sf::SoundBuffer> SoundManager::load(const std::string& name)
{
	std::shared_ptr<sf::SoundBuffer> soundPtr(new sf::SoundBuffer);

	if(!soundPtr->LoadFromFile(myPath + name))
        throw std::invalid_argument(name + ": couldn't load sound");

    put(name, soundPtr);

    return soundPtr;
}