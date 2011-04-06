#include "scenes/IScene.h"

IScene::IScene(SceneManager& sceneManager) :
mySceneManager(sceneManager)
{

}

IScene::~IScene()
{

}

void IScene::onShow()
{

}

void IScene::onExit()
{

}

void IScene::onTrackingStateChanged(Tracking::State newState)
{

}
