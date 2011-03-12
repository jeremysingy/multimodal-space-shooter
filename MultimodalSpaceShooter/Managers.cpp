#include "Managers.h"
#include "Game.h"

GraphicsEngine& graphicsEngine()
{
    return Game::instance().myGraphicsEngine;
}

PhysicsEngine& physicsEngine()
{
    return Game::instance().myPhysicsEngine;
}

EventManager& eventManager()
{
    return Game::instance().myEventManager;
}

SceneManager& sceneManager()
{
    return Game::instance().mySceneManager;
}

ImageManager& imageManager()
{
    return Game::instance().myImageManager;
}