#ifndef INGAMESCENE_H
#define INGAMESCENE_H

#include "scenes/IScene.h"
#include "managers/EventListener.h"
#include "managers/MultimodalListener.h"
#include "utils/PausableClock.h"
#include "loaders/LevelManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "utils/Background.h"
#include "gui/ProgressBar.h"

class InGameScene : public IScene
{
    public:
        InGameScene(SceneManager& sceneManager);
        virtual ~InGameScene();

        virtual void onShow();
        virtual void onExit();

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;

        virtual void onEvent(const sf::Event& event);
        virtual void onMultimodalEvent(MultimodalEvent event);

    private:
        void drawFps(sf::RenderTarget& window) const;

        LevelManager  myLevelManager;
        PausableClock myGameClock;

        mutable sf::Clock myFpsClock;
        mutable int       myFrameCount;

        Background       myBackground;
        ProgressBar      myVolumeBar;
        mutable sf::Text myFpsText;
};

#endif // INGAMESCENE_H