#ifndef INPAUSESCENE_H
#define INPAUSESCENE_H

#include <SFML/Graphics/Text.hpp>
#include "scenes/IScene.h"
#include "input/EventListener.h"
#include "input/MultimodalListener.h"
#include "gui/Menu.h"
#include "gui/ButtonListener.h"

//////////////////////////////////////////////////
/// Scene when the game is in pause
//////////////////////////////////////////////////
class InPauseScene : public IScene, public ButtonListener
{
    public:
        InPauseScene(SceneManager& sceneManager);

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;

        virtual void onEvent(const sf::Event& event);
        virtual void onMultimodalEvent(Multimodal::Event event);
        virtual void onButtonPress(const std::string& buttonId);

    private:
        sf::Sprite myCursor;
        Menu       myMenu;
};

#endif // INPAUSESCENE_H