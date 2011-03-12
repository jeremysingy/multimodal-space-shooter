#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <set>

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

        std::set<PhysicsObject*> myObjects;

        friend class Game;
};

#endif // PHYSICSENGINE_H