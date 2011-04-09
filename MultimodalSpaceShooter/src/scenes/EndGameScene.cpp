#include "scenes/EndGameScene.h"
#include "scenes/SceneManager.h"
#include "core/Managers.h"
#include "core/Game.h"

#include <SFML/Graphics.hpp>

EndGameScene::EndGameScene(SceneManager& sceneManager) :
IScene(sceneManager),
myCursor(*imageManager().get("cursor.png")),
myMenu("Congratulations, you finished the game", *imageManager().get("menu.png"), sf::Color(70, 140, 0))
{
    myMenu.addButton("but_endgame_continue", "Restart the game", this);
    myMenu.addButton("but_endgame_quit", "Quit", this);
}

void EndGameScene::update(float frameTime)
{
    if(multimodalManager().getTrackingState() == Tracking::UserTracked)
        myCursor.SetPosition(multimodalManager().getRightHandPosition());
    else
        myCursor.SetPosition(static_cast<float>(eventManager().getInput().GetMouseX()),
                             static_cast<float>(eventManager().getInput().GetMouseY()));

    myMenu.update(frameTime);
}

void EndGameScene::draw(sf::RenderTarget& window) const
{
    myMenu.draw(window);
    window.Draw(myCursor);
}

void EndGameScene::onEvent(const sf::Event& event)
{
    if(event.Type == sf::Event::KeyPressed)
    {
        if(event.Key.Code == sf::Key::Escape)
            mySceneManager.changeCurrentScene(Scene::InGame);
    }

    myMenu.onEvent(event);
}

void EndGameScene::onMultimodalEvent(Multimodal::Event event)
{
    myMenu.onMultimodalEvent(event);
}

void EndGameScene::onButtonPress(const std::string& buttonId)
{
    if(buttonId == "but_endgame_continue")
        mySceneManager.changeCurrentScene(Scene::InGame);
    else if(buttonId == "but_endgame_quit")
        Game::instance().quit();
}
