#include "scenes/TrackingScene.h"
#include "managers/Managers.h"
#include "core/Game.h"
#include <SFML/Graphics.hpp>

TrackingScene::TrackingScene() :
myTextInfo("Please take this nice pose until your body is detected...", sf::Font::GetDefaultFont(), 25),
myCursor(*imageManager().get("cursor.png")),
myPoseSprite(*imageManager().get("pose.png"))
{
    //myMenu.addButton("but_tracking_start", "Start a new game", this);
    //myMenu.addButton("but_tracking_quit", "Quit", this);
    const sf::Vector2i screenSize = Game::instance().getScreenSize();
    const sf::FloatRect infoSize = myTextInfo.GetRect();
    const sf::Vector2f poseSize = myPoseSprite.GetSize();

    myTextInfo.SetPosition(screenSize.x / 2.f - infoSize.Width / 2.f, 50.f);
    myPoseSprite.SetPosition(screenSize.x / 2.f - poseSize.x / 2.f, 100.f);
}

void TrackingScene::update(float frameTime)
{
    if(multimodalManager().isGestureEnabled())
        myCursor.SetPosition(multimodalManager().getRightHandPosition());
    else
        myCursor.SetPosition(static_cast<float>(eventManager().getInput().GetMouseX()),
                             static_cast<float>(eventManager().getInput().GetMouseY()));

    //myMenu.update(frameTime);
}

void TrackingScene::draw(sf::RenderTarget& window) const
{
    //myMenu.draw(window);
    window.Draw(myTextInfo);
    window.Draw(myPoseSprite);
    window.Draw(myCursor);
}

void TrackingScene::onEvent(const sf::Event& event)
{
    //myMenu.onEvent(event);
}

void TrackingScene::onMultimodalEvent(MultimodalEvent event)
{
    //myMenu.onMultimodalEvent(event);
}

void TrackingScene::onButtonPress(const std::string& buttonId)
{
    if(buttonId == "but_tracking_start")
        sceneManager().changeCurrentScene(SceneManager::SceneInGame);
    else if(buttonId == "but_tracking_quit")
        Game::instance().quit();
}

