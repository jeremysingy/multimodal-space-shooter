#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>
#include <memory>

#include "Entity.h"
#include "IScene.h"
#include "EventListener.h"

#include <map>

class SceneManager : public EventListener
{
    public:
        SceneManager();

        enum SceneType
        {
            SceneIntro,
            SceneInGame,
            SceneInPause
        };

        void updateScene(float frameTime);
        void drawScene(sf::RenderTarget& window);
        void changeCurrentScene(SceneType scene);

        virtual void onEvent(const sf::Event& event);

    private:
        typedef std::shared_ptr<IScene> ScenePtr;
        typedef std::map<SceneType, ScenePtr> MapScenes;

        MapScenes myScenes;
        ScenePtr myCrtScene;
};

#endif // SCENEMANAGER_H