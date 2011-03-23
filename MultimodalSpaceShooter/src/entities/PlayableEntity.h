#ifndef PLAYABLEENTITY_H
#define PLAYABLEENTITY_H

#include "Entity.h"
#include <SFML/Window/Event.hpp>

class PlayableEntity : public Entity
{
    public:
        PlayableEntity();
        virtual ~PlayableEntity();

        virtual void onPlayerAction(const sf::Event& event) = 0;
        virtual void onMultimodalAction(const sf::Event& event) = 0;
};

#endif // PLAYABLEENTITY_H