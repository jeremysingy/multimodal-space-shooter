#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

class PhysicsObject
{
    public:
        PhysicsObject();
        virtual ~PhysicsObject();

        virtual void update(float frameTime) = 0;
};

#endif // PHYSICSOBJECT_H