#include "managers/SceneManager.h"
#include "entities/Entity.h"
#include "scenes/IntroScene.h"
#include "scenes/TrackingScene.h"
#include "scenes/InGameScene.h"
#include "scenes/InPauseScene.h"
#include "scenes/GameOverScene.h"
#include "scenes/EndGameScene.h"
#include <algorithm>

SceneManager::SceneManager()
{
    ScenePtr introScene(new IntroScene(*this));
    ScenePtr trackingScene(new TrackingScene(*this));
    ScenePtr inGameScene(new InGameScene(*this));
    ScenePtr inPauseScene(new InPauseScene(*this));
    ScenePtr gameOverScene(new GameOverScene(*this));
    ScenePtr endGameScene(new EndGameScene(*this));

    myScenes[Scene::Intro]  = introScene;
    myScenes[Scene::Tracking]  = trackingScene;
    myScenes[Scene::InGame] = inGameScene;
    myScenes[Scene::InPause] = inPauseScene;
    myScenes[Scene::GameOver] = gameOverScene;
    myScenes[Scene::EndGame] = endGameScene;

    myCrtScene = introScene;
    myCrtScene->onShow();
}

void SceneManager::onEvent(const sf::Event& event)
{
    myCrtScene->onEvent(event);
}

void SceneManager::onMultimodalEvent(MultimodalEvent event)
{
    myCrtScene->onMultimodalEvent(event);
}

void SceneManager::onTrackingStateChanged(Tracking::State newState)
{
    myCrtScene->onTrackingStateChanged(newState);
}

void SceneManager::updateScene(float frameTime)
{
    myCrtScene->update(frameTime);
}

void SceneManager::drawScene(sf::RenderTarget& window)
{
    myCrtScene->draw(window);
}

void SceneManager::changeCurrentScene(Scene::Type newScene)
{
    myCrtScene->onExit();
    myCrtScene = myScenes[newScene];
    myCrtScene->onShow();
}
