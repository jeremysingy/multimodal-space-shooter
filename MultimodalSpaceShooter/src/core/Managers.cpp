#include "core/Managers.h"
#include "core/Game.h"

AudioEngine& audioEngine()
{
    return Game::instance().myAudioEngine;
}

EventManager& eventManager()
{
    return Game::instance().myEventManager;
}

MultimodalManager& multimodalManager()
{
    return Game::instance().myMultimodalManager;
}

EntityManager& entityManager()
{
    return Game::instance().myEntityManager;
}

ImageManager& imageManager()
{
    return Game::instance().myImageManager;
}

SoundManager& soundManager()
{
    return Game::instance().mySoundManager;
}
