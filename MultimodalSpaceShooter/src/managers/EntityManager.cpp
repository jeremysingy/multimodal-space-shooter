#include "managers/EntityManager.h"

EntityManager::EntityManager()
{

}

EntityManager::~EntityManager()
{

}

void EntityManager::addEntity(std::shared_ptr<Entity> entity)
{
    myNewEntities.push_back(entity);
}

void EntityManager::addPlayableEntity(std::shared_ptr<PlayableEntity> playableEntity)
{
    myPlayableEntities.push_back(playableEntity);
}

/*void EntityManager::removeEntity(std::shared_ptr<Entity> entity)
{
    myEntities.erase(entity);
}*/

void EntityManager::updateEntities(float frameTime)
{
    // Update all the objects of the scene
    for(EntityVector::iterator i = myEntities.begin(); i != myEntities.end(); ++i)
    {
        (*i)->update(frameTime);
    }

    // Update the playable objects of the scene (the spaceship)
    for(PlayableVector::iterator i = myPlayableEntities.begin(); i != myPlayableEntities.end(); ++i)
    {
        (*i)->update(frameTime);
    }

    // Check for possible collisions
    manageCollisions();

    addNewEntities();
}

void EntityManager::drawEntities(sf::RenderTarget& window)
{
    // Draw the background
    

    // Draw all the objects of the scene
    for(EntityVector::iterator i = myEntities.begin(); i != myEntities.end(); ++i)
    {
        (*i)->draw(window);
    }

    // Draw the playable objects of the scene (the spaceship)
    for(PlayableVector::iterator i = myPlayableEntities.begin(); i != myPlayableEntities.end(); ++i)
    {
        (*i)->draw(window);
    }

    // Print current fps and volume indicator
    //drawFps(window);
    //drawVolumeIndicator(window);
}

void EntityManager::checkDestroyedEntities()
{
    myEntities.erase(std::remove_if(myEntities.begin(), myEntities.end(), CheckDestroyed()), myEntities.end());
}

void EntityManager::addNewEntities()
{
    for(EntityVector::iterator i = myNewEntities.begin(); i != myNewEntities.end(); ++i)
        myEntities.push_back(*i);

    myNewEntities.clear();
}

void EntityManager::manageCollisions()
{
    for(std::size_t i = 0; i < myEntities.size(); ++i)
    {
        for(std::size_t j = i + 1; j < myEntities.size(); ++j)
        {
            sf::FloatRect collisionArea;
            
            if(isCollide(*myEntities[i], *myEntities[j], collisionArea))
            {
                 myEntities[i]->onCollision((myEntities[j])->getType(), collisionArea);
                 myEntities[j]->onCollision((myEntities[i])->getType(), collisionArea);
            }
        }
    }
}

bool EntityManager::isCollide(const Entity& entity1, const Entity& entity2, sf::FloatRect& collisionArea)
{
    return entity1.getBoundingRect().Intersects(entity2.getBoundingRect(), collisionArea);
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
