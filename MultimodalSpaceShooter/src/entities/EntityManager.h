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

//////////////////////////////////////////////////
/// Manage all the entities of the game like
/// the spaceship, the planets, etc.
//////////////////////////////////////////////////
class EntityManager
{
    public:
        typedef std::shared_ptr<Entity> EntityPtr;
        typedef std::vector<EntityPtr>  EntityVector;

        typedef std::shared_ptr<PlayableEntity> PlayablePtr;
        typedef std::vector<PlayablePtr>        PlayableVector;

        void reset();
        void addEntity(std::shared_ptr<Entity> entity);
        void addPlayableEntity(std::shared_ptr<PlayableEntity> playableEntity);
        EntityManager::PlayableVector getPlayableEntities();
        void onEvent(const sf::Event& event);
        void onMultimodalEvent(Multimodal::Event event);

        void updateEntities(float frameTime);
        void drawEntities(sf::RenderTarget& window);
        void checkDestroyedEntities();
        bool hasEntityWithType(Object::Type type);

    private:
        void manageCollisions();
        void addNewEntities();
        static bool isCollide(const Entity& entity1, const Entity& entity2, sf::FloatRect& collisionArea);

        EntityVector   myEntities;
        EntityVector   myNewEntities;
        PlayableVector myPlayableEntities;
};

#endif // ENTITYMANAGER_H