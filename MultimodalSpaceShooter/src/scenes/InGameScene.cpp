#include "scenes/InGameScene.h"
#include "entities/Spaceship.h"
#include "entities/Planet.h"
#include "managers/Managers.h"

InGameScene::InGameScene() :
myGameClock(true)
{
    // Preload images
    imageManager().load("background.png");
    imageManager().load("spaceship.png");
    imageManager().load("explosion.png");
    imageManager().load("fire.png");

    // Load the world
    myLevelManager.load("worlds/sample.xml");

    // Create the playable spaceship
    std::shared_ptr<PlayableEntity> spaceship(new Spaceship);
    entityManager().addPlayableEntity(spaceship);
}

InGameScene::~InGameScene()
{

}

void InGameScene::onShow()
{
    myGameClock.start();
}

void InGameScene::onExit()
{
    myGameClock.pause();
}

void InGameScene::update(float frameTime)
{
    std::shared_ptr<Entity> nextEntity = myLevelManager.getNextEntity(myGameClock.getElapsedTime());

    while(nextEntity)
    {
        entityManager().addEntity(nextEntity);
        nextEntity = myLevelManager.getNextEntity(myGameClock.getElapsedTime());
    }

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
