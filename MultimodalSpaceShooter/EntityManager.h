#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include <memory>

#include "Entity.h"


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
        //void removeEntity(std::shared_ptr<Entity> entity);
        void checkDestroyedEntities();

    private:
        std::vector<std::shared_ptr<Entity>> myEntities;
};

#endif // ENTITYMANAGER_H