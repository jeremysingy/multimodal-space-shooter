#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "PlayableEntity.h"
#include "utils/AnimatedSprite.h"
#include "Fire.h"
#include <SFML/Graphics.hpp>

class Spaceship : public PlayableEntity
{
    public:
        Spaceship();
        ~Spaceship();

        virtual void update(float frameTime);
        virtual void onCollision(Object::Type otherType, const sf::FloatRect& area);

        virtual sf::FloatRect getBoundingRect() const;
        virtual void draw(sf::RenderTarget& window) const;

        virtual void onPlayerAction(const sf::Event& event);
        virtual void onMultimodalAction(MultimodalEvent event);

        unsigned int getLife();

        static const float SPEED;
        static const int DEFAULT_LIFE = 5;

    private:
        void fireMissile();
        void fireSuperMissiles();
        void checkBorders();

        AnimatedSprite mySprite;
        Fire           myFire;
        unsigned int   myLife;
};

#endif // SPACESHIP_H