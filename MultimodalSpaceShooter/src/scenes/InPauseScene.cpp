#include "scenes/InPauseScene.h"
#include "managers/Managers.h"
#include "core/Game.h"

#include <SFML/Graphics.hpp>

InPauseScene::InPauseScene() :
myCursor(*imageManager().get("cursor.png")),
myMenu("Pause Menu", *imageManager().get("menu_test.png"))
{
    myMenu.addButton("blabla");
    myMenu.addButton("blibli");
    myMenu.addButton("bloblo");
}

void InPauseScene::update(float frameTime)
{
    myCursor.SetPosition(multimodalManager().getRightHandPosition());
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
}

void InPauseScene::onMultimodalEvent(MultimodalEvent event)
{

}
