#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <set>
//#include <vector>
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

        std::set<PhysicsObject*> myObjects;
        //std::vector<PhysicsObject*> myObjects;

        friend class Game;
};

#endif // PHYSICSENGINE_H