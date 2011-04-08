#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics/Shape.hpp>

namespace Object
{
    enum Type
    {
        NEUTRAL,
        PLAYER,
        DESTRUCTIVE,
        WEAPON,
    };
}

class Entity
{
    public:
        Entity(Object::Type type = Object::NEUTRAL);
        virtual ~Entity();

        virtual void update(float frameTime) = 0;
        virtual void draw(sf::RenderTarget& window) const = 0;
        
        virtual sf::FloatRect getBoundingRect() const = 0;
        virtual void onCollision(Object::Type otherType, const sf::FloatRect& area);

        Object::Type getType() const;
        void destroy();
        bool isDestroyed() const;

    protected:
        Object::Type myType;

    private:
        Entity(const Entity&);
        Entity& operator =(const Entity&);

        bool myIsDestroyed;
};

#endif // ENTITY_H