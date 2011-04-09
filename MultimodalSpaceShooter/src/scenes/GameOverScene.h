#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

#include "scenes/IScene.h"
#include "input/EventListener.h"
#include "input/MultimodalListener.h"
#include "gui/Menu.h"
#include "gui/ButtonListener.h"
#include <SFML/Graphics/Text.hpp>

//////////////////////////////////////////////////
/// Game over scene when the game is missed
//////////////////////////////////////////////////
class GameOverScene : public IScene, public ButtonListener
{
    public:
        GameOverScene(SceneManager& sceneManager);

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;

        virtual void onEvent(const sf::Event& event);
        virtual void onMultimodalEvent(Multimodal::Event event);
        virtual void onButtonPress(const std::string& buttonId);

    private:
        sf::Sprite myCursor;
        Menu       myMenu;
};

#endif // GAMEOVERSCENE_H