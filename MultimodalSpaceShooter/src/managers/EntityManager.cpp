#include "managers/EntityManager.h"

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

void EntityManager::addPlayableEntity(std::shared_ptr<PlayableEntity> playableEntity)
{
    myPlayableEntities.push_back(playableEntity);
}

/*void EntityManager::removeEntity(std::shared_ptr<Entity> entity)
{
    myEntities.erase(entity);
}*/

void EntityManager::checkDestroyedEntities()
{
    myEntities.erase(std::remove_if(myEntities.begin(), myEntities.end(), CheckDestroyed()), myEntities.end());
}

void EntityManager::onEvent(const sf::Event& event)
{
    for(std::vector<std::shared_ptr<PlayableEntity>>::iterator i = myPlayableEntities.begin(); i != myPlayableEntities.end(); ++i)
    {
        (*i)->onPlayerAction(event);
    }
}

void EntityManager::onMultimodalEvent(MultimodalEvent event)
{
    for(std::vector<std::shared_ptr<PlayableEntity>>::iterator i = myPlayableEntities.begin(); i != myPlayableEntities.end(); ++i)
    {
        (*i)->onMultimodalAction(event);
    }
}
