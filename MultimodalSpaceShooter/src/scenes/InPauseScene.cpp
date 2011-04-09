#include "scenes/InPauseScene.h"
#include "scenes/SceneManager.h"
#include "core/Managers.h"
#include "core/Game.h"

#include <SFML/Graphics.hpp>

InPauseScene::InPauseScene(SceneManager& sceneManager) :
IScene(sceneManager),
myCursor(*imageManager().get("cursor.png")),
myMenu("Pause Menu", *imageManager().get("menu.png"))
{
    myMenu.addButton("but_pause_continue", "Continue", this);
    myMenu.addButton("but_pause_quit", "Quit", this);
}

void InPauseScene::update(float frameTime)
{
    if(multimodalManager().getTrackingState() == Tracking::UserTracked)
        myCursor.SetPosition(multimodalManager().getRightHandPosition());
    else
        myCursor.SetPosition(static_cast<float>(eventManager().getInput().GetMouseX()),
                             static_cast<float>(eventManager().getInput().GetMouseY()));

    myMenu.update(frameTime);
}

void InPauseScene::draw(sf::RenderTarget& window) const
{
    myMenu.draw(window);
    window.Draw(myCursor);
}

void InPauseScene::onEvent(const sf::Event& event)
{
    if(event.Type == sf::Event::KeyPressed)
    {
        if(event.Key.Code == sf::Key::Escape)
            mySceneManager.changeCurrentScene(Scene::InGame);
    }

    myMenu.onEvent(event);
}

void InPauseScene::onMultimodalEvent(Multimodal::Event event)
{
    myMenu.onMultimodalEvent(event);
}

void InPauseScene::onButtonPress(const std::string& buttonId)
{
    if(buttonId == "but_pause_continue")
        mySceneManager.changeCurrentScene(Scene::InGame);
    else if(buttonId == "but_pause_quit")
        Game::instance().quit();
}
