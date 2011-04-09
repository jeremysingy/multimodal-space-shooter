#include "scenes/InGameScene.h"
#include "scenes/SceneManager.h"
#include "core/Game.h"
#include "entities/Spaceship.h"
#include "entities/Planet.h"
#include "core/Managers.h"

#include <sstream>
#include <iomanip>

InGameScene::InGameScene(SceneManager& sceneManager) :
IScene(sceneManager),
myGameClock(true),
myFrameCount(0),
myLifeBar(sf::Vector2f(10.f, 10.f), sf::Color::Green),
myVolumeBar(sf::Vector2f(Game::instance().getScreenSize().x - 150.f, 10.f), sf::Color::Red),
myFpsText("", sf::Font::GetDefaultFont(), 16),
myShowFps(false),
myEndTime(-1.f)
{
    myFpsText.SetPosition(5.f, 20.f);

    // Preload images
    imageManager().get("background.png");
    imageManager().get("spaceship.png");
    imageManager().get("explosion.png");
    imageManager().get("bullet.png");
    imageManager().get("superbullet.png");
    imageManager().get("fire.png");

    reset();
}

void InGameScene::reset()
{
    myGameClock.reset();
    entityManager().reset();

    // Add the playable spaceship
    std::shared_ptr<PlayableEntity> spaceship(new Spaceship);
    entityManager().addPlayableEntity(spaceship);

    // Load the world
    myLevelManager.load("worlds/sample.xml");
    myBackground = myLevelManager.getBackground();
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

    myBackground->update(frameTime);
    entityManager().updateEntities(frameTime);
    entityManager().checkDestroyedEntities();

    int spaceshipLife = entityManager().getPlayableEntities()[0]->getLife();

    myLifeBar.setLevel(spaceshipLife / static_cast<float>(Spaceship::MAX_LIFE) * 100.f);
    myVolumeBar.setLevel(multimodalManager().getMicroVolume());

    checkEndGame();
}

void InGameScene::draw(sf::RenderTarget& window) const
{
    // Draw the background
    myBackground->draw(window);

    // Draw the objects of the scene
    entityManager().drawEntities(window);

    // Draw the UI controls
    myLifeBar.draw(window);
    myVolumeBar.draw(window);

    // Draw the FPS
    if(myShowFps)
        drawFps(window);
}

void InGameScene::onEvent(const sf::Event& event)
{
    if(event.Type == sf::Event::KeyPressed)
    {
        if(event.Key.Code == sf::Key::Escape)
            mySceneManager.changeCurrentScene(Scene::InPause);

        entityManager().onEvent(event);
    }

    if(event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::F)
        myShowFps = !myShowFps;
}

void InGameScene::onMultimodalEvent(Multimodal::Event event)
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

void InGameScene::checkEndGame()
{
    // If spaceship is destroyed, game over
    if(entityManager().getPlayableEntities()[0]->isDestroyed())
    {
        mySceneManager.changeCurrentScene(Scene::GameOver);
        reset();
    }

    // If no more destructive entities, will end game
    if(myLevelManager.isWorldEnded() && !entityManager().hasEntityWithType(Object::DESTRUCTIVE) && myEndTime < 0.f)
        myEndTime = myGameClock.getElapsedTime();
    
    // Really end game 2 seconds later
    if(myEndTime > 0.f && myGameClock.getElapsedTime() > myEndTime + 2.f)
    {
        mySceneManager.changeCurrentScene(Scene::EndGame);
        reset();
    }
}
