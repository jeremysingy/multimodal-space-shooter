#ifndef INGAMESCENE_H
#define INGAMESCENE_H

#include "scenes/IScene.h"
#include "managers/EventListener.h"
#include "managers/MultimodalListener.h"
#include "utils/PausableClock.h"
#include "utils/Background.h"
#include "loaders/LevelManager.h"
#include "gui/ProgressBar.h"
#include "entities/Spaceship.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

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
        virtual void onMultimodalEvent(Multimodal::Event event);

    private:
        void drawFps(sf::RenderTarget& window) const;
        void endGame();

        LevelManager  myLevelManager;
        PausableClock myGameClock;

        mutable sf::Clock myFpsClock;
        mutable int       myFrameCount;

        Background       myBackground;
        ProgressBar      myLifeBar;
        ProgressBar      myVolumeBar;
        mutable sf::Text myFpsText;
        float            myEndTime;

        std::shared_ptr<Spaceship> mySpaceship;
};

#endif // INGAMESCENE_H