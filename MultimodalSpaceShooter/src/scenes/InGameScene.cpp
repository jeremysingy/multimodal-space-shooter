#include "scenes/InGameScene.h"
#include "entities/Spaceship.h"
#include "entities/Planet.h"
#include "managers/Managers.h"

InGameScene::InGameScene()
{
    // Preload images
    imageManager().load("spaceship.png");
    imageManager().load("explosion.png");
    imageManager().load("planet1.png");

    // Create some entities
    // TODO: this is just a test!
    levelManager().loadFromFile("worlds/sample.xml");
    std::shared_ptr<PlayableEntity> spaceship(new Spaceship);
    entityManager().addPlayableEntity(spaceship);

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

void InGameScene::draw(sf::RenderTarget& window) const
{
    graphicsEngine().drawScene(window);
}

void InGameScene::onEvent(const sf::Event& event)
{
    if(event.Type == sf::Event::KeyPressed)
    {
        if(event.Key.Code == sf::Key::Escape)
            sceneManager().changeCurrentScene(SceneManager::SceneInPause);

        entityManager().onEvent(event);
    }
}

void InGameScene::onMultimodalEvent(MultimodalEvent event)
{
    entityManager().onMultimodalEvent(event);
}
