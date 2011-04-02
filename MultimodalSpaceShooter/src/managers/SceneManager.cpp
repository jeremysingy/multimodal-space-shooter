#include "managers/SceneManager.h"
#include "entities/Entity.h"
#include "scenes/IntroScene.h"
#include "scenes/TrackingScene.h"
#include "scenes/InGameScene.h"
#include "scenes/InPauseScene.h"
#include <algorithm>

SceneManager::SceneManager()
{
    ScenePtr introScene(new IntroScene);
    ScenePtr trackingScene(new TrackingScene);
    ScenePtr inGameScene(new InGameScene);
    ScenePtr inPauseScene(new InPauseScene);

    myScenes[SceneIntro]  = introScene;
    myScenes[SceneTracking]  = trackingScene;
    myScenes[SceneInGame] = inGameScene;
    myScenes[SceneInPause] = inPauseScene;

    myCrtScene = introScene;
}

void SceneManager::onEvent(const sf::Event& event)
{
    myCrtScene->onEvent(event);
}

void SceneManager::onMultimodalEvent(MultimodalEvent event)
{
    myCrtScene->onMultimodalEvent(event);
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
    myCrtScene = myScenes[newScene];
}
