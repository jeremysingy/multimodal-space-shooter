#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "GraphicsEngine.h"
#include "PhysicsEngine.h"
#include "EventManager.h"
#include "SceneManager.h"
#include "ImageManager.h"

//////////////////////////////////////////////////
/// Game skeleton that manages the game loop
//////////////////////////////////////////////////
class Game
{
    public:
        static Game& instance();
        void run();

    private:
        Game();

        sf::RenderWindow myWindow;

        GraphicsEngine  myGraphicsEngine;
        PhysicsEngine   myPhysicsEngine;
        EventManager    myEventManager;
        SceneManager    mySceneManager;
        ImageManager    myImageManager;

        friend GraphicsEngine& graphicsEngine();
        friend PhysicsEngine& physicsEngine();
        friend EventManager& eventManager();
        friend SceneManager& sceneManager();
        friend ImageManager& imageManager();
};

#endif // GAME_H