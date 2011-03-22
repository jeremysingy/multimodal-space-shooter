#include "EntityManager.h"
#include <iostream>

EntityManager::EntityManager()
{

}

EntityManager::~EntityManager()
{

}

void EntityManager::addEntity(std::shared_ptr<Entity> entity)
{
    myEntities.push_back(entity);
}

/*void EntityManager::removeEntity(std::shared_ptr<Entity> entity)
{
    myEntities.erase(entity);
}*/

void EntityManager::checkDestroyedEntities()
{
    myEntities.erase(std::remove_if(myEntities.begin(), myEntities.end(), CheckDestroyed()), myEntities.end());
}
