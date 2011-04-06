#include "managers/SceneManager.h"
#include "entities/Entity.h"
#include "scenes/IntroScene.h"
#include "scenes/TrackingScene.h"
#include "scenes/InGameScene.h"
#include "scenes/InPauseScene.h"
#include <algorithm>

SceneManager::SceneManager()
{
    ScenePtr introScene(new IntroScene(*this));
    ScenePtr trackingScene(new TrackingScene(*this));
    ScenePtr inGameScene(new InGameScene(*this));
    ScenePtr inPauseScene(new InPauseScene(*this));

    myScenes[SceneIntro]  = introScene;
    myScenes[SceneTracking]  = trackingScene;
    myScenes[SceneInGame] = inGameScene;
    myScenes[SceneInPause] = inPauseScene;

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

void SceneManager::changeCurrentScene(SceneType newScene)
{
    myCrtScene->onExit();
    myCrtScene = myScenes[newScene];
    myCrtScene->onShow();
}
