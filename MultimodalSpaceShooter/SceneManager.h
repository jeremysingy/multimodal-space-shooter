#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>
#include <memory>

#include "Entity.h"
#include "IScene.h"

#include <map>

class SceneManager
{
    public:
        SceneManager();

        enum SceneType
        {
            SceneIntro,
            SceneInGame,
        };

        void updateScene(float frameTime);
        void drawScene(sf::RenderTarget& window);
        void changeCurrentScene(SceneType scene);

    private:
        typedef std::shared_ptr<IScene> ScenePtr;
        typedef std::map<SceneType, ScenePtr> MapScenes;
        //IScene* myCrtScene;

        MapScenes myScenes;
        ScenePtr myCrtScene;
};

#endif // SCENEMANAGER_H