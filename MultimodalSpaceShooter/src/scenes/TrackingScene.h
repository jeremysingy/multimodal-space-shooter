#ifndef TRACKINGSCENE_H
#define TRACKINGSCENE_H

#include <SFML/Graphics/Text.hpp>
#include "scenes/IScene.h"
#include "managers/EventListener.h"
#include "managers/MultimodalListener.h"
#include "gui/Button.h"
#include "gui/ButtonListener.h"

class TrackingScene : public IScene, public ButtonListener
{
    public:
        TrackingScene(SceneManager& sceneManager);

        virtual void onShow();
        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;

        virtual void onEvent(const sf::Event& event);
        virtual void onMultimodalEvent(Multimodal::Event event);
        virtual void onTrackingStateChanged(Tracking::State newState);
        virtual void onButtonPress(const std::string& buttonId);

    private:
        sf::Text   myTextIntro;
        sf::Text   myTextInfo;
        sf::Sprite myCursor;
        sf::Sprite myPoseSprite;
        Button     myStartButton;
        bool       myShowButton;
};

#endif // TRACKINGSCENE_H