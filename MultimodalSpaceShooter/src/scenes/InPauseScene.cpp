#include "scenes/InPauseScene.h"
#include "managers/Managers.h"
#include "core/Game.h"

#include <SFML/Graphics.hpp>

InPauseScene::InPauseScene() :
myCursor(*imageManager().get("cursor.png")),
myMenu("Pause Menu", *imageManager().get("menu_test.png"))
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
            sceneManager().changeCurrentScene(SceneManager::SceneInGame);

        if(event.Key.Code == sf::Key::Q)
            Game::instance().quit();
    }

    myMenu.onEvent(event);
}

void InPauseScene::onMultimodalEvent(MultimodalEvent event)
{
    myMenu.onMultimodalEvent(event);
}

void InPauseScene::onButtonPress(const std::string& buttonId)
{
    if(buttonId == "but_pause_continue")
        sceneManager().changeCurrentScene(SceneManager::SceneInGame);
    else if(buttonId == "but_pause_quit")
        Game::instance().quit();
}
