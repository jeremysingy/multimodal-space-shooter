#ifndef TRACKINGSCENE_H
#define TRACKINGSCENE_H

#include <SFML/Graphics/Text.hpp>
#include "scenes/IScene.h"
#include "managers/EventListener.h"
#include "managers/MultimodalListener.h"
#include "gui/Menu.h"
#include "gui/ButtonListener.h"

class TrackingScene : public IScene, public ButtonListener
{
    public:
        TrackingScene();

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;

        virtual void onEvent(const sf::Event& event);
        virtual void onMultimodalEvent(MultimodalEvent event);
        virtual void onButtonPress(const std::string& buttonId);

    private:
        sf::Text   myTextInfo;
        sf::Sprite myCursor;
        //Menu       myMenu;
        sf::Sprite myPoseSprite;
};

#endif // TRACKINGSCENE_H