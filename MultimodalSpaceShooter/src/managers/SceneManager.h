#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>
#include <memory>

#include "entities/Entity.h"
#include "scenes/IScene.h"
#include "managers/EventListener.h"
#include "managers/MultimodalListener.h"

#include <map>

namespace Scene
{
    enum Type
    {
        Intro,
        Tracking,
        InGame,
        InPause,
        GameOver,
        EndGame
    };
}

class SceneManager : public EventListener, public MultimodalListener
{
    public:
        SceneManager();

        void updateScene(float frameTime);
        void drawScene(sf::RenderTarget& window);
        void changeCurrentScene(Scene::Type scene);

        virtual void onEvent(const sf::Event& event);
        virtual void onMultimodalEvent(MultimodalEvent event);
        virtual void onTrackingStateChanged(Tracking::State newState);

    private:
        typedef std::shared_ptr<IScene> ScenePtr;
        typedef std::map<Scene::Type, ScenePtr> MapScenes;

        MapScenes myScenes;
        ScenePtr myCrtScene;
};

#endif // SCENEMANAGER_H