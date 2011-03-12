#include "SceneManager.h"
#include "Entity.h"
#include <algorithm>

SceneManager::SceneManager()
{

}


SceneManager::~SceneManager()
{

}

void SceneManager::addEntity(std::shared_ptr<Entity> entity)
{
    myEntities.push_back(entity);
}

/*void SceneManager::removeEntity(std::shared_ptr<Entity> entity)
{
    myEntities.erase(entity);
}*/

void SceneManager::checkDestroyedEntities()
{
    myEntities.erase(std::remove_if(myEntities.begin(), myEntities.end(), CheckDestroyed()), myEntities.end());
}
