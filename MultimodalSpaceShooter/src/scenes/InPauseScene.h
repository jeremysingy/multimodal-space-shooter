#ifndef INPAUSESCENE_H
#define INPAUSESCENE_H

#include <SFML/Graphics/Text.hpp>
#include "scenes/IScene.h"
#include "managers/EventListener.h"
#include "gui/Button.h"

class InPauseScene : public IScene
{
    public:
        InPauseScene();

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;

        virtual void onEvent(const sf::Event& event);

    private:
        sf::Text myPauseText;
        Button   myTestButton;
        
};

#endif // INPAUSESCENE_H