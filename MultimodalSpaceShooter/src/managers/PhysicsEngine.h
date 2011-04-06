#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <set>
#include <SFML/Graphics/Rect.hpp>

class PhysicsObject;

class PhysicsEngine
{
    public:
        void addObject(PhysicsObject* object);
        void removeObject(PhysicsObject* object);
        void updateScene(float frameTime);

    private:
        PhysicsEngine();
        ~PhysicsEngine();

        bool isCollide(const PhysicsObject* object1, const PhysicsObject* object2, sf::FloatRect& collisionArea);
        void manageCollisions();

        std::set<PhysicsObject*> myObjects;

        friend class Game;
};

#endif // PHYSICSENGINE_H