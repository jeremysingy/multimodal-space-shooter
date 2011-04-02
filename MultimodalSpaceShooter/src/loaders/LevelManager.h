#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <string>
#include <iostream>
#include <queue>
#include "ResourceManager.h"
#include "entities/EntityModel.h"
#include <vector>

class LevelManager {
    public:
        int loadFromFile(const std::string& name);
        std::priority_queue<EntityModel, std::vector<EntityModel>, CompareTime>  myEntityModels;
        
    private:
        LevelManager();
        ~LevelManager();

        friend class Game;
};

#endif // LEVELMANAGER_H