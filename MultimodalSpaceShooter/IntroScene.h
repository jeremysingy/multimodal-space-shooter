#ifndef INTROSCENE_H
#define INTROSCENE_H

#include <SFML/Graphics/Text.hpp>
#include "IScene.h"
#include "EventListener.h"

class IntroScene : public IScene
{
    public:
        IntroScene();

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;

        virtual void onEvent(const sf::Event& event);

    private:
        sf::Text myWelcomeText;
        sf::Text myChooseText;
};

#endif // INTROSCENE_H