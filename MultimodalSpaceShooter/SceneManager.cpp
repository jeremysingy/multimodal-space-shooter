#include "SceneManager.h"
#include "Entity.h"
#include "IntroScene.h"
#include "InGameScene.h"
#include "InPauseScene.h"
#include <algorithm>

SceneManager::SceneManager()
{
    ScenePtr introScene(new IntroScene);
    ScenePtr inGameScene(new InGameScene);
    ScenePtr inPauseScene(new InPauseScene);

    myScenes[SceneIntro]  = introScene;
    myScenes[SceneInGame] = inGameScene;
    myScenes[SceneInPause] = inPauseScene;

    myCrtScene = introScene;
}

void SceneManager::onEvent(const sf::Event& event)
{
    myCrtScene->onEvent(event);
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
