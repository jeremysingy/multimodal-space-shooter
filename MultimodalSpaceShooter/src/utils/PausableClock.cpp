#include "utils/PausableClock.h"

PausableClock::PausableClock(bool paused) :
myIsPaused(paused),
myTime(0.f),
myClock()
{

}

void PausableClock::pause()
{
    if (!myIsPaused)
    {
        myIsPaused = true;
        myTime += myClock.GetElapsedTime();
    }
}

void PausableClock::start()
{
    if(myIsPaused)
    {
        myClock.Reset();
        myIsPaused = false;
    }
}

float PausableClock::getElapsedTime() const
{
    if(!myIsPaused)
        return myTime + myClock.GetElapsedTime();
    else
        return myTime;
}

void PausableClock::reset(bool paused)
{
    myIsPaused = paused;
    myTime = 0.f;
    myClock.Reset();
}