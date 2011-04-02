#ifndef INGAMESCENE_H
#define INGAMESCENE_H

#include "scenes/IScene.h"
#include "managers/EventListener.h"
#include "managers/MultimodalListener.h"
#include "utils/PausableClock.h"
#include "loaders/LevelManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class InGameScene : public IScene
{
    public:
        InGameScene();
        virtual ~InGameScene();

        virtual void onShow();
        virtual void onExit();

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;

        virtual void onEvent(const sf::Event& event);
        virtual void onMultimodalEvent(MultimodalEvent event);

    private:
        LevelManager  myLevelManager;
        PausableClock myGameClock;
};

#endif // INGAMESCENE_H