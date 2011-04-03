#include "scenes/InGameScene.h"
#include "entities/Spaceship.h"
#include "entities/Planet.h"
#include "managers/Managers.h"

InGameScene::InGameScene():
myBackground(*imageManager().get("background.png"),0.05f,1985)
{
    //TODO ERROR
    gameClock.Reset();
    // Preload images
    imageManager().load("spaceship.png");
    imageManager().load("explosion.png");
    imageManager().load("fire.png");
    imageManager().load("background.png");
    imageManager().load("planet1.png");

    // Create some entities
    // TODO: this is just a test!
    levelManager().loadFromFile("worlds/sample.xml");
    std::shared_ptr<PlayableEntity> spaceship(new Spaceship);
    entityManager().addPlayableEntity(spaceship);

    myBackground.SetImage(*imageManager().get("background.png"));
}

InGameScene::~InGameScene()
{

}

void InGameScene::update(float frameTime)
{
    physicsEngine().updateScene(frameTime);
    entityManager().checkDestroyedEntities();

    if(!levelManager().myEntityModels.empty()){
        EntityModel entityModel = levelManager().myEntityModels.top();
        if(entityModel.getTime()<=gameClock.GetElapsedTime()){
            levelManager().myEntityModels.pop();
            std::shared_ptr<Entity> planet(new Planet(sf::Vector2f(entityModel.getXCoordinate(), 15)));
            entityManager().addEntity(planet);
        }
    }

    myBackground.update();
}

void InGameScene::draw(sf::RenderTarget& window) const
{
    window.Draw(myBackground);
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
