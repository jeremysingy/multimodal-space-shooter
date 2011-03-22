#include "IntroScene.h"
#include "Managers.h"
#include <SFML/Graphics.hpp>
#include <iostream>

IntroScene::IntroScene() :
myWelcomeText("Welcome in Multimodal Space Shooter"),
myChooseText("Press enter to start the game")

{
    myWelcomeText.Move(200, 50);
    myChooseText.Move(200, 100);
}

void IntroScene::onEvent(const sf::Event& event)
{
    if(event.Type == sf::Event::KeyPressed)
    {
        if(event.Key.Code == sf::Key::Return)
            sceneManager().changeCurrentScene(SceneManager::SceneInGame);
    }
}

void IntroScene::update(float frameTime)
{
    // Nothing to update for now
}

void IntroScene::draw(sf::RenderTarget& window)
{
    window.Draw(myWelcomeText);
    window.Draw(myChooseText);
}
