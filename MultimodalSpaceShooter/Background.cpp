#include "Background.h"
#include "core/Game.h"
#include <sstream>
#include <iostream>
#include <string>


Background::Background(const sf::Image& image, float frameTime, int imgHeight) :
sf::Sprite(image),
myFrameTime(frameTime)
{
    myImageHeight = imgHeight;
    setInitialPosition();
}

void Background::update()
{
    unsigned int framesToSkip = static_cast<unsigned int>(myClock.GetElapsedTime() / myFrameTime);

    if(framesToSkip > 0)
    {
        SetPosition(GetPosition().x,GetPosition().y+1);
        myClock.Reset();
    }
}

float Background::getFrameTime() const
{
    return myFrameTime;
}

void Background::setInitialPosition()
{
    SetPosition(0,Game::instance().getScreenSize().y-myImageHeight);
    //SetPosition(0,0);
}
