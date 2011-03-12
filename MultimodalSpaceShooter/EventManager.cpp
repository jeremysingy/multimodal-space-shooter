#include "EventManager.h"

#include <SFML/Window.hpp>
#include "EventListener.h"
#include "Spaceship.h"

EventManager::EventManager(const sf::Input& input)
: myInput(input)
{
    
}

EventManager::~EventManager()
{
    
}

void EventManager::addListener(EventListener* listener) 
{
    if(listener)
        myListeners.insert(listener);
}

void EventManager::removeListener(EventListener* listener) 
{
    myListeners.erase(listener);
}

const sf::Input& EventManager::getInput() const
{
    return myInput;
}

void EventManager::update(sf::Window& window)
{
    sf::Event event;

    while(window.GetEvent(event))
    {
        // Manage high level events
        if(event.Type == sf::Event::Closed || (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Escape))
            window.Close();

        // Send other events to the listeners
        for(std::set<EventListener*>::iterator i = myListeners.begin(); i != myListeners.end(); ++i)
        {
            (*i)->onEvent(event);
        }
    }
}