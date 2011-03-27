#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include <memory>

#include "entities/Entity.h"
#include "entities/PlayableEntity.h"

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

        void checkDestroyedEntities();

    private:
        std::vector<std::shared_ptr<Entity>>         myEntities;
        std::vector<std::shared_ptr<PlayableEntity>> myPlayableEntities;
};

#endif // ENTITYMANAGER_H