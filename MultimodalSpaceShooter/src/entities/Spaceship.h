#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "entities/PlayableEntity.h"
#include "utils/AnimatedSprite.h"
#include "entities/Fire.h"
#include <SFML/Graphics.hpp>

//////////////////////////////////////////////////
/// Main playable playable entity
//////////////////////////////////////////////////
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
        virtual void onMultimodalAction(Multimodal::Event event);

        static const float SPEED;
        static const float MISSILE_LEFT_ANGLE;
        static const float MISSILE_UP_ANGLE;
        static const float MISSILE_RIGHT_ANGLE;

    private:
        void fireMissile();
        void fireSuperMissiles();
        void checkBorders();

        AnimatedSprite mySprite;
        Fire           myFire;
};

#endif // SPACESHIP_H