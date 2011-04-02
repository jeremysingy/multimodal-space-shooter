#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <string>
#include <iostream>
#include <queue>
#include <vector>
#include <memory>
#include "ResourceManager.h"
#include "entities/EntityModel.h"
#include "entities/Entity.h"

class LevelManager
{
    public:
        LevelManager();

        int load(const std::string& name);
        std::shared_ptr<Entity> getNextEntity(float gameTime);

        bool hasEntitiesForNow(float gameTime);
        bool isWorldEnded();
        
    private:
        std::priority_queue<EntityModel, std::vector<EntityModel>, CompareTime> myEntityModels;
};

#endif // LEVELMANAGER_H