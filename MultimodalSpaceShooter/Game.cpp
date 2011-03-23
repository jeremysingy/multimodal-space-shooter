#include "Game.h"
#include "Spaceship.h"
#include "Planet.h"

#include <iostream>
#include "AnimatedSprite.h"

Game& Game::instance()
{
    static Game game;
    return game;
}

Game::Game() :
myWindow(sf::VideoMode(800, 600, 32), "Multimodal Space Shooter"),
myEventManager(myWindow.GetInput()),
myImageManager("./images/"),
mySoundManager("./sounds/")
{

}

void Game::run()
{
    while(myWindow.IsOpened())
    {
        // Dispatch events to the event manager
        myEventManager.update(myWindow);

        // Update the multimodal events (gesture and voice)
        myMultimodalManager.update();

        // Update the current scene
        mySceneManager.updateScene(myWindow.GetFrameTime());

        // Clear screen
        myWindow.Clear();

        // Draw the current scene
        mySceneManager.drawScene(myWindow);

        // Display content
        myWindow.Display();
    }
}

void Game::quit()
{
    myWindow.Close();
}
