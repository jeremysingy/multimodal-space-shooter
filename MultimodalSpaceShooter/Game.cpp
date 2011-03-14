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

Game::Game(/*const std::string& world*/) :
myWindow(sf::VideoMode(800, 600, 32), "Multimodal Space Shooter"),
myEventManager(myWindow.GetInput()),
myImageManager("./images/")
{
    // Preload images
    myImageManager.load("spaceship.png");
    myImageManager.load("explosion.png");

    // Create some entities
    // TODO: this is just a test!
    std::shared_ptr<Entity> spaceship(new Spaceship);
    mySceneManager.addEntity(spaceship);

    std::shared_ptr<Entity> planet1(new Planet(sf::Vector2f(100, 200)));
    mySceneManager.addEntity(planet1);

    std::shared_ptr<Entity> planet2(new Planet(sf::Vector2f(300, 15)));
    mySceneManager.addEntity(planet2);

    std::shared_ptr<Entity> planet3(new Planet(sf::Vector2f(700, 120)));
    mySceneManager.addEntity(planet3);
}

void Game::run()
{
    while(myWindow.IsOpened())
    {
        // Dispatch events to the event manager
        myEventManager.update(myWindow);

        // Update the objects
        myPhysicsEngine.updateScene(myWindow.GetFrameTime());

        // Destroy dead entities
        mySceneManager.checkDestroyedEntities();
        
        // Clear screen
        myWindow.Clear();

        // Let the graphics engine draw the scene
        myGraphicsEngine.drawScene(myWindow);

        // Display content
        myWindow.Display();
    }
}
