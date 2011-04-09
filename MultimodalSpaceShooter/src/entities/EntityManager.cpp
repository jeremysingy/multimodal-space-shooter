#include "entities/EntityManager.h"

void EntityManager::reset()
{
    myEntities.clear();
    myNewEntities.clear();
    myPlayableEntities.clear();
}

void EntityManager::addEntity(std::shared_ptr<Entity> entity)
{
    myNewEntities.push_back(entity);
}

void EntityManager::addPlayableEntity(std::shared_ptr<PlayableEntity> playableEntity)
{
    myPlayableEntities.push_back(playableEntity);
}

EntityManager::PlayableVector EntityManager::getPlayableEntities()
{
    return myPlayableEntities;
}

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
}

void EntityManager::checkDestroyedEntities()
{
    myEntities.erase(std::remove_if(myEntities.begin(), myEntities.end(), CheckDestroyed()), myEntities.end());
}

bool EntityManager::hasEntityWithType(Object::Type type)
{
    for(EntityVector::iterator i = myEntities.begin(); i != myEntities.end(); ++i)
        if((*i)->getType() == type)
            return true;

    return false;
}

void EntityManager::addNewEntities()
{
    for(EntityVector::iterator i = myNewEntities.begin(); i != myNewEntities.end(); ++i)
        myEntities.push_back(*i);

    myNewEntities.clear();
}

void EntityManager::manageCollisions()
{
    // Entities with entities
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

    // Playable entities with entities
    for(std::size_t i = 0; i < myPlayableEntities.size(); ++i)
    {
        for(std::size_t j = 0; j < myEntities.size(); ++j)
        {
            sf::FloatRect collisionArea;
            
            if(isCollide(*myPlayableEntities[i], *myEntities[j], collisionArea))
            {
                 myPlayableEntities[i]->onCollision((myEntities[j])->getType(), collisionArea);
                 myEntities[j]->onCollision((myPlayableEntities[i])->getType(), collisionArea);
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

void EntityManager::onMultimodalEvent(Multimodal::Event event)
{
    for(std::vector<std::shared_ptr<PlayableEntity>>::iterator i = myPlayableEntities.begin(); i != myPlayableEntities.end(); ++i)
    {
        (*i)->onMultimodalAction(event);
    }
}
