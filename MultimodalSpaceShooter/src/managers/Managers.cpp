#include "managers/Managers.h"
#include "core/Game.h"

GraphicsEngine& graphicsEngine()
{
    return Game::instance().myGraphicsEngine;
}

PhysicsEngine& physicsEngine()
{
    return Game::instance().myPhysicsEngine;
}

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

SceneManager& sceneManager()
{
    return Game::instance().mySceneManager;
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