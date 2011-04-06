#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics/Shape.hpp>

class Entity
{
    public:
        enum Type
        {
            NEUTRAL,
            PLAYER,
            DESTRUCTIVE,
            WEAPON,
        };

        Entity(Type type = NEUTRAL);
        virtual ~Entity();

        virtual void update(float frameTime) = 0;
        virtual void draw(sf::RenderTarget& window) const = 0;
        
        virtual sf::FloatRect getBoundingRect() const = 0;
        virtual void onCollision(Type otherType, const sf::FloatRect& area);

        Type getType() const;
        void destroy();
        bool isDestroyed() const;

    protected:
        Type myType;

    private:
        Entity(const Entity&);
        Entity& operator =(const Entity&);

        bool myIsDestroyed;
};

#endif // ENTITY_H