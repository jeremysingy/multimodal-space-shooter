#include "Background.h"
#include "core/Game.h"


Background::Background(const sf::Image& image, float frameTime, float imageHeight) :
firstSprite(image),
secondSprite(image),
myFrameTime(frameTime)
{
    myImageHeight = imageHeight;
    setInitialPosition();
}

void Background::update()
{
    unsigned int framesToSkip = static_cast<unsigned int>(myClock.GetElapsedTime() / myFrameTime);

    if(framesToSkip > 0)
    {
        firstSprite.SetPosition(firstSprite.GetPosition().x,firstSprite.GetPosition().y+1);
        secondSprite.SetPosition(secondSprite.GetPosition().x,secondSprite.GetPosition().y+1);
        myClock.Reset();
    }

    if(secondSprite.GetPosition().y == Game::instance().getScreenSize().y - myImageHeight)
        setInitialPosition();
}

void Background::draw(sf::RenderTarget& window) const
{
    window.Draw(firstSprite);
    window.Draw(secondSprite);
}

float Background::getFrameTime() const
{
    return myFrameTime;
}

void Background::setInitialPosition()
{
    firstSprite.SetPosition(0.f, Game::instance().getScreenSize().y - myImageHeight);
    secondSprite.SetPosition(0.f, firstSprite.GetPosition().y - myImageHeight);
}

void Background::setImage(const sf::Image &image)
{
    firstSprite.SetImage(image);
    secondSprite.SetImage(image);
}


