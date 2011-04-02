#ifndef PAUSABLECLOCK_H
#define PAUSABLECLOCK_H

#include <SFML/System/Clock.hpp>

class PausableClock
{
    public :

        PausableClock(bool paused = false);

        void pause();
        void start();
        float getElapsedTime() const;
        void reset(bool paused = false);

    private :
        bool myIsPaused;
        float myTime;

        sf::Clock myClock;
};

#endif // PAUSABLECLOCK_H