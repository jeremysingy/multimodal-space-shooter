#ifndef PLAYABLEENTITY_H
#define PLAYABLEENTITY_H

#include "Entity.h"
#include <SFML/Window/Event.hpp>
#include "input/MultimodalListener.h"

//////////////////////////////////////////////////
/// Entity that is playable, as the spaceship is
//////////////////////////////////////////////////
class PlayableEntity : public Entity
{
    public:
        PlayableEntity();

        virtual void onPlayerAction(const sf::Event& event) = 0;
        virtual void onMultimodalAction(Multimodal::Event event) = 0;
        unsigned int getLife();

        static const int MAX_LIFE;

    protected:
        unsigned int myLife;
};

#endif // PLAYABLEENTITY_H