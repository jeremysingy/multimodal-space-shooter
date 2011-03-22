#include "InGameScene.h"
#include "Spaceship.h"
#include "Planet.h"
#include "Managers.h"
#include <iostream>

InGameScene::InGameScene()
{
    // Preload images
    imageManager().load("spaceship.png");
    imageManager().load("explosion.png");
    imageManager().load("planete1.png");

    // Create some entities
    // TODO: this is just a test!
    std::shared_ptr<Entity> spaceship(new Spaceship);
    entityManager().addEntity(spaceship);

    std::shared_ptr<Entity> planet1(new Planet(sf::Vector2f(100, 200)));
    entityManager().addEntity(planet1);

    std::shared_ptr<Entity> planet2(new Planet(sf::Vector2f(300, 15)));
    entityManager().addEntity(planet2);

    std::shared_ptr<Entity> planet3(new Planet(sf::Vector2f(700, 120)));
    entityManager().addEntity(planet3);
}

InGameScene::~InGameScene()
{

}

void InGameScene::update(float frameTime)
{
    physicsEngine().updateScene(frameTime);
    entityManager().checkDestroyedEntities();
}

void InGameScene::draw(sf::RenderTarget& window)
{
    graphicsEngine().drawScene(window);
}
