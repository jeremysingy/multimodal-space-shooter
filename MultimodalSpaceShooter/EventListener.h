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
        /*virtual void onKeyPressed(int code);
        virtual void onButtonPressed(int code);
        virtual void onResize(int width, int height);*/

    protected:
        EventListener();
};

#endif // EVENTLISTENER_H