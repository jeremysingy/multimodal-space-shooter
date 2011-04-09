#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include <SFML/Window/Event.hpp>

//////////////////////////////////////////////////
/// Base class for an event listener
//////////////////////////////////////////////////
class EventListener
{
    public:
        virtual ~EventListener();

        virtual void onEvent(const sf::Event& event);

    protected:
        EventListener();
};

#endif // EVENTLISTENER_H