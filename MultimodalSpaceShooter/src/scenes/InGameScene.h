#ifndef INGAMESCENE_H
#define INGAMESCENE_H

#include "scenes/IScene.h"
#include "managers/EventListener.h"
#include "managers/MultimodalListener.h"

class InGameScene : public IScene
{
    public:
        InGameScene();
        virtual ~InGameScene();

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;

        virtual void onEvent(const sf::Event& event);
        virtual void onMultimodalEvent(MultimodalEvent event);
};

#endif // INGAMESCENE_H