#include "scenes/GameOverScene.h"
#include "managers/SceneManager.h"
#include "managers/Managers.h"
#include "core/Game.h"

#include <SFML/Graphics.hpp>

GameOverScene::GameOverScene(SceneManager& sceneManager) :
IScene(sceneManager),
myCursor(*imageManager().get("cursor.png")),
myMenu("Pause Menu", *imageManager().get("menu_test.png"))
{
    myMenu.addButton("but_gameover_continue", "Continue", this);
    myMenu.addButton("but_gameover_quit", "Quit", this);
}

void GameOverScene::update(float frameTime)
{
    if(multimodalManager().getTrackingState() == Tracking::UserTracked)
        myCursor.SetPosition(multimodalManager().getRightHandPosition());
    else
        myCursor.SetPosition(static_cast<float>(eventManager().getInput().GetMouseX()),
                             static_cast<float>(eventManager().getInput().GetMouseY()));

    myMenu.update(frameTime);
}

void GameOverScene::draw(sf::RenderTarget& window) const
{
    myMenu.draw(window);
    window.Draw(myCursor);
}

void GameOverScene::onEvent(const sf::Event& event)
{
    if(event.Type == sf::Event::KeyPressed)
    {
        if(event.Key.Code == sf::Key::Escape)
            mySceneManager.changeCurrentScene(Scene::InGame);

        if(event.Key.Code == sf::Key::Q)
            Game::instance().quit();
    }

    myMenu.onEvent(event);
}

void GameOverScene::onMultimodalEvent(MultimodalEvent event)
{
    myMenu.onMultimodalEvent(event);
}

void GameOverScene::onButtonPress(const std::string& buttonId)
{
    if(buttonId == "but_gameover_continue")
        mySceneManager.changeCurrentScene(Scene::InGame);
    else if(buttonId == "but_gameover_quit")
        Game::instance().quit();
}
