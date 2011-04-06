#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include <memory>

#include "entities/Entity.h"
#include "entities/PlayableEntity.h"
#include <iostream>

//////////////////////////////////////////////////
/// Functor to get destroyed entities
//////////////////////////////////////////////////
struct CheckDestroyed 
{ 
    bool operator()(const std::shared_ptr<Entity>& entity) const 
    { 
        return entity->isDestroyed(); 
    } 
};

class EntityManager
{
    public:
        EntityManager();
        ~EntityManager();

        void addEntity(std::shared_ptr<Entity> entity);
        void addPlayableEntity(std::shared_ptr<PlayableEntity> playableEntity);
        //void removeEntity(std::shared_ptr<Entity> entity);
        void onEvent(const sf::Event& event);
        void onMultimodalEvent(MultimodalEvent event);

        void updateEntities(float frameTime);
        void drawEntities(sf::RenderTarget& window);
        void checkDestroyedEntities();

    private:
        void manageCollisions();
        void addNewEntities();
        static bool isCollide(const Entity& entity1, const Entity& entity2, sf::FloatRect& collisionArea);

        typedef std::shared_ptr<Entity> EntityPtr;
        typedef std::vector<EntityPtr>  EntityVector;

        typedef std::shared_ptr<PlayableEntity> PlayablePtr;
        typedef std::vector<PlayablePtr>        PlayableVector;

        EntityVector   myEntities;
        EntityVector   myNewEntities;
        PlayableVector myPlayableEntities;
};

#endif // ENTITYMANAGER_H