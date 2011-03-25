#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "managers/GraphicsEngine.h"
#include "managers/PhysicsEngine.h"
#include "managers/AudioEngine.h"
#include "managers/EventManager.h"
#include "managers/MultimodalManager.h"
#include "managers/SceneManager.h"
#include "managers/EntityManager.h"
#include "loaders/ImageManager.h"
#include "loaders/SoundManager.h"

//////////////////////////////////////////////////
/// Game skeleton that manages the game loop
//////////////////////////////////////////////////
class Game
{
    public:
        static Game& instance();
        void run();
        void quit();

    private:
        Game();

        sf::RenderWindow myWindow;

        ImageManager      myImageManager;
        SoundManager	  mySoundManager;

        GraphicsEngine    myGraphicsEngine;
        PhysicsEngine     myPhysicsEngine;
        AudioEngine		  myAudioEngine;

        EventManager      myEventManager;
        MultimodalManager myMultimodalManager;

        EntityManager     myEntityManager;
        SceneManager      mySceneManager;

        // Declare managers as friends of the game main class
        friend ImageManager& imageManager();
        friend SoundManager& soundManager();

        friend GraphicsEngine& graphicsEngine();
        friend PhysicsEngine& physicsEngine();
        friend AudioEngine& audioEngine();

        friend EventManager& eventManager();
        friend MultimodalManager& multimodalManager();

        friend EntityManager& entityManager();
        friend SceneManager& sceneManager();
};

#endif // GAME_H