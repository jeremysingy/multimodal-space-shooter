#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <set>
#include <SFML/Window.hpp>

class EventListener;

//////////////////////////////////////////////////
/// Manage the events of the game
//////////////////////////////////////////////////
class EventManager
{
    public:
        void addListener(EventListener* listener);
        void removeListener(EventListener* listener);
        void update(sf::Window& window);
        const sf::Input& getInput() const;
 
    private:
        EventManager(const sf::Input& input);
        ~EventManager();

        std::set<EventListener*> myListeners;
        const sf::Input& myInput;

        friend class Game;
};

#endif // EVENTMANAGER_H