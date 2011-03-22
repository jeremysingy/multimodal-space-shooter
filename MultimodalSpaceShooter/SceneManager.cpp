#include "SceneManager.h"
#include "Entity.h"
#include "IntroScene.h"
#include "InGameScene.h"
#include <algorithm>

SceneManager::SceneManager()
{
    ScenePtr introScene(new IntroScene);
    ScenePtr inGameScene(new InGameScene);

    myScenes[SceneIntro]  = introScene;
    myScenes[SceneInGame] = inGameScene;

    myCrtScene = introScene;
}

void SceneManager::changeCurrentScene(SceneType newScene)
{
    myCrtScene = myScenes[newScene];
}

void SceneManager::updateScene(float frameTime)
{
    myCrtScene->update(frameTime);
}

void SceneManager::drawScene(sf::RenderTarget& window)
{
    myCrtScene->draw(window);
}
