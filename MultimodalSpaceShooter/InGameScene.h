#ifndef INGAMESCENE_H
#define INGAMESCENE_H

#include "IScene.h"

class InGameScene : public IScene
{
    public:
        InGameScene();
        virtual ~InGameScene();

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window);
};

#endif // INGAMESCENE_H