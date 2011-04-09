#ifndef INTROSCENE_H
#define INTROSCENE_H

#include <SFML/Graphics/Text.hpp>
#include "scenes/IScene.h"
#include "input/EventListener.h"
#include "input/MultimodalListener.h"
#include "gui/Menu.h"
#include "gui/ButtonListener.h"

//////////////////////////////////////////////////
/// Introduction scene when the game if launched
//////////////////////////////////////////////////
class IntroScene : public IScene, public ButtonListener
{
    public:
        IntroScene(SceneManager& sceneManager);

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;

        virtual void onEvent(const sf::Event& event);
        virtual void onMultimodalEvent(Multimodal::Event event);
        virtual void onButtonPress(const std::string& buttonId);

    private:
        sf::Sprite myCursor;
        Menu       myMenu;
};

#endif // INTROSCENE_H