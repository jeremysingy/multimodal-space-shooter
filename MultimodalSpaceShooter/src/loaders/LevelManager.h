#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "loaders/ResourceManager.h"
#include "entities/EntityModel.h"
#include "entities/Entity.h"
#include "utils/Background.h"

#include <string>
#include <queue>
#include <vector>
#include <memory>

//////////////////////////////////////////////////
/// Loader of levels in XML format
//////////////////////////////////////////////////
class LevelManager
{
    public:
        LevelManager();

        void load(const std::string& name);

        std::shared_ptr<Background> getBackground();
        std::shared_ptr<Entity> getNextEntity(float gameTime);

        bool hasEntitiesForNow(float gameTime);
        bool isWorldEnded();
        
    private:
        std::priority_queue<EntityModel, std::vector<EntityModel>, CompareTime> myEntityModels;

        std::shared_ptr<Background> myBackground;
};

#endif // LEVELMANAGER_H