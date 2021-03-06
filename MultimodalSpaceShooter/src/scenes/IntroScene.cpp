#include "scenes/IntroScene.h"
#include "scenes/SceneManager.h"
#include "core/Managers.h"
#include "core/Game.h"
#include <SFML/Graphics.hpp>

IntroScene::IntroScene(SceneManager& sceneManager) :
IScene(sceneManager),
myCursor(*imageManager().get("cursor.png")),
myMenu("Start Menu", *imageManager().get("menu.png"))
{
    if(multimodalManager().isMultimodalityAvailable())
        myMenu.addButton("but_intro_start_multi", "Start game using multimodality", this);

    myMenu.addButton("but_intro_start_norm", "Start game without multimodality", this);
    myMenu.addButton("but_intro_quit", "Quit", this);
}

void IntroScene::update(float frameTime)
{
    if(multimodalManager().getTrackingState() == Tracking::UserTracked)
        myCursor.SetPosition(multimodalManager().getRightHandPosition());
    else
        myCursor.SetPosition(static_cast<float>(eventManager().getInput().GetMouseX()),
                             static_cast<float>(eventManager().getInput().GetMouseY()));

    myMenu.update(frameTime);
}

void IntroScene::draw(sf::RenderTarget& window) const
{
    myMenu.draw(window);
    window.Draw(myCursor);
}

void IntroScene::onEvent(const sf::Event& event)
{
    myMenu.onEvent(event);
}

void IntroScene::onMultimodalEvent(Multimodal::Event event)
{
    myMenu.onMultimodalEvent(event);
}

void IntroScene::onButtonPress(const std::string& buttonId)
{
    if(buttonId == "but_intro_start_multi")
        mySceneManager.changeCurrentScene(Scene::Tracking);
    else if(buttonId == "but_intro_start_norm")
        mySceneManager.changeCurrentScene(Scene::InGame);
    else if(buttonId == "but_intro_quit")
        Game::instance().quit();
}

