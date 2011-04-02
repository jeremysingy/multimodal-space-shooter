#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "PlayableEntity.h"
#include "utils/AnimatedSprite.h"
#include <SFML/Graphics.hpp>

class Spaceship : public PlayableEntity
{
    public:
        Spaceship();
        ~Spaceship();

        virtual void update(float frameTime);
        virtual sf::FloatRect getBoundingRect() const;
        virtual void draw(sf::RenderTarget& window) const;

        virtual void onPlayerAction(const sf::Event& event);
        virtual void onMultimodalAction(MultimodalEvent event);

    private:
        void fireMissile();

        AnimatedSprite mySprite;

        static const float SPEED;
};

#endif // SPACESHIP_H