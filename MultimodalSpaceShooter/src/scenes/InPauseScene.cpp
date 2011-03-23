#include "scenes/InPauseScene.h"
#include "managers/Managers.h"
#include "core/Game.h"

#include <SFML/Graphics.hpp>

InPauseScene::InPauseScene() :
myPauseText("Game in pause, press Q to exit"),
myTestButton(sf::Vector2f(250, 100), "Test", *imageManager().get("button_test.png"))
{
    myPauseText.Move(200, 50);
}

void InPauseScene::update(float frameTime)
{
    // Nothing to update for now
}

void InPauseScene::draw(sf::RenderTarget& window) const
{
    window.Draw(myPauseText);
    myTestButton.draw(window);
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
}
