#include "scenes/InGameScene.h"
#include "managers/SceneManager.h"
#include "core/Game.h"
#include "entities/Spaceship.h"
#include "entities/Planet.h"
#include "managers/Managers.h"

#include <sstream>
#include <iomanip>

InGameScene::InGameScene(SceneManager& sceneManager) :
IScene(sceneManager),
myGameClock(true),
myFrameCount(0),
myBackground(*imageManager().get("background.png"), 0.01f, 1985),
myVolumeBar(sf::Vector2f(Game::instance().getScreenSize().x - 150.f, 10.f), sf::Color::Red),
myFpsText("", sf::Font::GetDefaultFont(), 16)
{
    // Preload images
    imageManager().load("background.png");
    imageManager().load("spaceship.png");
    imageManager().load("explosion.png");
    imageManager().load("bullet.png");
    imageManager().load("superbullet.png");
    imageManager().load("fire.png");

    // Load the world
    myLevelManager.load("worlds/sample.xml");

    // Create the playable spaceship
    std::shared_ptr<PlayableEntity> spaceship(new Spaceship);
    entityManager().addPlayableEntity(spaceship);

    myBackground.setImage(*imageManager().get("background.png"));
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

    myBackground.update();
    entityManager().updateEntities(frameTime);
    entityManager().checkDestroyedEntities();

    myVolumeBar.setLevel(multimodalManager().getMicroVolume());
}

void InGameScene::draw(sf::RenderTarget& window) const
{
    // Draw the background
    myBackground.draw(window);

    // Draw the objects of the scene
    entityManager().drawEntities(window);

    // Draw the UI controls
    myVolumeBar.draw(window);
    drawFps(window);
}

void InGameScene::onEvent(const sf::Event& event)
{
    if(event.Type == sf::Event::KeyPressed)
    {
        if(event.Key.Code == sf::Key::Escape)
            mySceneManager.changeCurrentScene(SceneManager::SceneInPause);

        entityManager().onEvent(event);
    }
}

void InGameScene::onMultimodalEvent(MultimodalEvent event)
{
    entityManager().onMultimodalEvent(event);
}

void InGameScene::drawFps(sf::RenderTarget& window) const
{
    float crtTime = myFpsClock.GetElapsedTime();

    if(crtTime >= 1.f)
    {
        float fpsAvg = myFrameCount / crtTime;

        std::ostringstream oss;
        oss << "fps: " << std::setprecision(0) << std::fixed << fpsAvg;
        myFpsText.SetString(oss.str());

        myFrameCount = 0;
        myFpsClock.Reset();
    }

    ++myFrameCount;

    window.Draw(myFpsText);
}
