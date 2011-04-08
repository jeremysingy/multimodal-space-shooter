#ifndef ENDGAMESCENE_H
#define ENDGAMESCENE_H

#include <SFML/Graphics/Text.hpp>
#include "scenes/IScene.h"
#include "managers/EventListener.h"
#include "managers/MultimodalListener.h"
#include "gui/Menu.h"
#include "gui/ButtonListener.h"

class EndGameScene : public IScene, public ButtonListener
{
    public:
        EndGameScene(SceneManager& sceneManager);

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;

        virtual void onEvent(const sf::Event& event);
        virtual void onMultimodalEvent(MultimodalEvent event);
        virtual void onButtonPress(const std::string& buttonId);

    private:
        sf::Sprite myCursor;
        Menu       myMenu;
};

#endif // ENDGAMESCENE_H