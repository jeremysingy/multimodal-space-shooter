#include "scenes/TrackingScene.h"
#include "managers/SceneManager.h"
#include "managers/Managers.h"
#include "core/Game.h"
#include <SFML/Graphics.hpp>

TrackingScene::TrackingScene(SceneManager& sceneManager) :
IScene(sceneManager),
myTextIntro("Please take this nice pose until your body is detected...", sf::Font::GetDefaultFont(), 25),
myTextInfo("", sf::Font::GetDefaultFont(), 20),
myCursor(*imageManager().get("cursor.png")),
myPoseSprite(*imageManager().get("pose.png")),
myStartButton("but_tracking_start", sf::Vector2f(200.f, 400.f), "Start game", *imageManager().get("button.png"), *imageManager().get("button_sel.png")),
myShowButton(false)
{
    const sf::Vector2i screenSize = Game::instance().getScreenSize();
    const sf::FloatRect infoSize = myTextIntro.GetRect();
    const sf::Vector2f poseSize = myPoseSprite.GetSize();

    myTextIntro.SetPosition(screenSize.x / 2.f - infoSize.Width / 2.f, 50.f);
    myPoseSprite.SetPosition(screenSize.x / 2.f - poseSize.x / 2.f, 100.f);

    myTextInfo.SetPosition(20.f, 600.f);
    myTextInfo.SetColor(sf::Color::Red);

    myStartButton.addListener(this);
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

    myStartButton.update(frameTime);
}

void TrackingScene::draw(sf::RenderTarget& window) const
{
    window.Draw(myTextIntro);
    window.Draw(myPoseSprite);
    window.Draw(myTextInfo);

    if(myShowButton)
        myStartButton.draw(window);

    window.Draw(myCursor);
}

void TrackingScene::onEvent(const sf::Event& event)
{
    myStartButton.onEvent(event);
}

void TrackingScene::onMultimodalEvent(MultimodalEvent event)
{
    myStartButton.onMultimodalEvent(event);
}

void TrackingScene::onTrackingStateChanged(Tracking::State newState)
{
    switch(newState)
    {
        case Tracking::UserDetected:
            myTextInfo.SetString("A user is now detected...");
            break;

        case Tracking::UserTracked:
            myTextInfo.SetString(myTextInfo.GetString() + "\nThe user is now tracked");
            myShowButton = true;
            break;
    }
}

void TrackingScene::onButtonPress(const std::string& buttonId)
{
    if(buttonId == "but_tracking_start")
        mySceneManager.changeCurrentScene(Scene::InGame);
}

