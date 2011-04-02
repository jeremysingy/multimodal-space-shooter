#include "scenes/TrackingScene.h"
#include "managers/Managers.h"
#include "core/Game.h"
#include "managers/Managers.h"
#include <SFML/Graphics.hpp>

TrackingScene::TrackingScene() :
myTextIntro("Please take this nice pose until your body is detected...", sf::Font::GetDefaultFont(), 25),
myTextInfo("", sf::Font::GetDefaultFont(), 15),
myCursor(*imageManager().get("cursor.png")),
myPoseSprite(*imageManager().get("pose.png"))
{
    const sf::Vector2i screenSize = Game::instance().getScreenSize();
    const sf::FloatRect infoSize = myTextIntro.GetRect();
    const sf::Vector2f poseSize = myPoseSprite.GetSize();

    myTextIntro.SetPosition(screenSize.x / 2.f - infoSize.Width / 2.f, 50.f);
    myPoseSprite.SetPosition(screenSize.x / 2.f - poseSize.x / 2.f, 100.f);

    myTextInfo.SetPosition(screenSize.x / 2.f - infoSize.Width / 2.f, 400.f);
    myTextInfo.SetColor(sf::Color::Red);
}

void TrackingScene::onShow()
{
    multimodalManager().startTracking();
}

void TrackingScene::update(float frameTime)
{
    if(multimodalManager().getTrackingState() == Tracking::UserTracked)
        myCursor.SetPosition(multimodalManager().getRightHandPosition());
    else
        myCursor.SetPosition(static_cast<float>(eventManager().getInput().GetMouseX()),
                             static_cast<float>(eventManager().getInput().GetMouseY()));

    //myMenu.update(frameTime);
}

void TrackingScene::draw(sf::RenderTarget& window) const
{
    //myMenu.draw(window);
    window.Draw(myTextIntro);
    window.Draw(myPoseSprite);
    window.Draw(myTextInfo);
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

void TrackingScene::onTrackingStateChanged(Tracking::State newState)
{
    switch(newState)
    {
        case Tracking::UserDetected:
            myTextInfo.SetString("A user is now detected!");

        case Tracking::UserTracked:
            myTextInfo.SetString(myTextInfo.GetString() + "\nA user is now detected!");
    }
}

void TrackingScene::onButtonPress(const std::string& buttonId)
{
    if(buttonId == "but_tracking_start")
        sceneManager().changeCurrentScene(SceneManager::SceneInGame);
    else if(buttonId == "but_tracking_quit")
        Game::instance().quit();
}

