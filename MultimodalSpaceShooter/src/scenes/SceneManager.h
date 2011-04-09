#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>
#include <memory>

#include "entities/Entity.h"
#include "scenes/IScene.h"
#include "input/EventListener.h"
#include "input/MultimodalListener.h"

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

//////////////////////////////////////////////////
/// Managers of the scenes in game game
/// Handles easy switching of the scenes
//////////////////////////////////////////////////
class SceneManager : public EventListener, public MultimodalListener
{
    public:
        SceneManager();

        void updateScene(float frameTime);
        void drawScene(sf::RenderTarget& window);
        void changeCurrentScene(Scene::Type scene);

        virtual void onEvent(const sf::Event& event);
        virtual void onMultimodalEvent(Multimodal::Event event);
        virtual void onTrackingStateChanged(Tracking::State newState);

    private:
        typedef std::shared_ptr<IScene> ScenePtr;
        typedef std::map<Scene::Type, ScenePtr> MapScenes;

        MapScenes myScenes;
        ScenePtr myCrtScene;
};

#endif // SCENEMANAGER_H