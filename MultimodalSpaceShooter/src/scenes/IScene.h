#ifndef ISCENE_H
#define ISCENE_H

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include "input/MultimodalListener.h"

//////////////////////////////////////////////////
/// Abstract base class for every scenes of the game
//////////////////////////////////////////////////
class SceneManager;

class IScene
{
    public:
        IScene(SceneManager& sceneManager);
        virtual ~IScene();

        virtual void onShow();
        virtual void onExit();

        virtual void update(float frameTime) = 0;
        virtual void draw(sf::RenderTarget& window) const = 0;

        virtual void onEvent(const sf::Event& event) = 0;
        virtual void onMultimodalEvent(Multimodal::Event event) = 0;
        virtual void onTrackingStateChanged(Tracking::State newState);
    
    protected:
        SceneManager& mySceneManager;
};

#endif // ISCENE_H