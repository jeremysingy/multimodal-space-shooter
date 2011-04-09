#ifndef INGAMESCENE_H
#define INGAMESCENE_H

#include "scenes/IScene.h"
#include "input/EventListener.h"
#include "input/MultimodalListener.h"
#include "utils/PausableClock.h"
#include "utils/Background.h"
#include "loaders/LevelManager.h"
#include "gui/ProgressBar.h"
#include "entities/Spaceship.h"

#include <SFML/Graphics.hpp>
#include <memory>

//////////////////////////////////////////////////
/// Scene in game when the user is playing
//////////////////////////////////////////////////
class InGameScene : public IScene
{
    public:
        InGameScene(SceneManager& sceneManager);

        void reset();
        virtual void onShow();
        virtual void onExit();

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;

        virtual void onEvent(const sf::Event& event);
        virtual void onMultimodalEvent(Multimodal::Event event);

    private:
        void drawFps(sf::RenderTarget& window) const;
        void checkEndGame();

        LevelManager  myLevelManager;
        PausableClock myGameClock;

        mutable sf::Clock myFpsClock;
        mutable int       myFrameCount;

        std::shared_ptr<Background> myBackground;
        ProgressBar      myLifeBar;
        ProgressBar      myVolumeBar;
        mutable sf::Text myFpsText;
        bool             myShowFps;
        float            myEndTime;
};

#endif // INGAMESCENE_H