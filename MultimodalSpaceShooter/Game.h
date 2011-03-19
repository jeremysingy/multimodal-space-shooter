#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "GraphicsEngine.h"
#include "PhysicsEngine.h"
#include "AudioEngine.h"
#include "EventManager.h"
#include "MultimodalManager.h"
#include "SceneManager.h"
#include "ImageManager.h"
#include "SoundManager.h"

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

        SoundManager	  mySoundManager;
        GraphicsEngine    myGraphicsEngine;
        PhysicsEngine     myPhysicsEngine;
        AudioEngine		  myAudioEngine;
        EventManager      myEventManager;
        MultimodalManager myMultimodalManager;
        SceneManager      mySceneManager;
        ImageManager      myImageManager;

        // Declare managers as friends of the game main class
        friend GraphicsEngine& graphicsEngine();
        friend PhysicsEngine& physicsEngine();
        friend AudioEngine& audioEngine();
        friend EventManager& eventManager();
        friend MultimodalManager& multimodalManager();
        friend SceneManager& sceneManager();
        friend ImageManager& imageManager();
        friend SoundManager& soundManager();
};

#endif // GAME_H