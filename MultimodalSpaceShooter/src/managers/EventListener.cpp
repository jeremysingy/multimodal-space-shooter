#include "managers/EventListener.h"
#include "managers/Managers.h"

EventListener::EventListener()
{
    eventManager().addListener(this);
}

EventListener::~EventListener()
{
    eventManager().removeListener(this);
}

void EventListener::onEvent(const sf::Event& event)
{
    
}