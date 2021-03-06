#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "core/AudioEngine.h"
#include "input/EventManager.h"
#include "input/MultimodalManager.h"
#include "scenes/SceneManager.h"
#include "entities/EntityManager.h"
#include "loaders/ImageManager.h"
#include "loaders/SoundManager.h"
#include "loaders/LevelManager.h"

//////////////////////////////////////////////////
/// Game skeleton that manages the game loop
//////////////////////////////////////////////////
class Game
{
    public:
        static Game& instance();

        const sf::Vector2i& getScreenSize();
        void run();
        void quit();

    private:
        Game();

        sf::Vector2i     myScreenSize;
        sf::RenderWindow myWindow;

        ImageManager      myImageManager;
        SoundManager	  mySoundManager;

        AudioEngine		  myAudioEngine;
        EventManager      myEventManager;
        MultimodalManager myMultimodalManager;

        EntityManager     myEntityManager;
        SceneManager      mySceneManager;

        // Declare managers as friends of the game main class
        friend ImageManager& imageManager();
        friend SoundManager& soundManager();

        friend AudioEngine& audioEngine();

        friend EventManager& eventManager();
        friend MultimodalManager& multimodalManager();

        friend EntityManager& entityManager();
        friend SceneManager& sceneManager();
};

#endif // GAME_H