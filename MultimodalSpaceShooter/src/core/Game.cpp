#include "core/Game.h"
#include "entities/Spaceship.h"
#include "entities/Planet.h"
#include "utils/AnimatedSprite.h"

Game& Game::instance()
{
    static Game game;
    return game;
}

Game::Game() :
myScreenSize(800, 600),
myWindow(sf::VideoMode(myScreenSize.x, myScreenSize.y, 32), "Multimodal Space Shooter"),
myEventManager(myWindow.GetInput()),
myImageManager("./images/"),
mySoundManager("./sounds/")
{
    myWindow.ShowMouseCursor(false);
}

const sf::Vector2i& Game::getScreenSize()
{
    return myScreenSize;
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
