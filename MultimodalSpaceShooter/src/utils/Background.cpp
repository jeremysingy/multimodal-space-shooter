#include "Background.h"
#include "core/Game.h"

Background::Background(const sf::Image& image, float scrollingSpeed) :
myFirstSprite(image),
mySecondSprite(image),
myScrollingSpeed(scrollingSpeed)
{
    setInitialPosition();
}

void Background::update(float frameTime)
{
    myFirstSprite.Move(0.f, myScrollingSpeed * frameTime);
    mySecondSprite.Move(0.f, myScrollingSpeed * frameTime);

    if(mySecondSprite.GetPosition().y >= Game::instance().getScreenSize().y - myFirstSprite.GetSize().y)
        setInitialPosition();
}

void Background::draw(sf::RenderTarget& window) const
{
    window.Draw(myFirstSprite);
    window.Draw(mySecondSprite);
}

void Background::setInitialPosition()
{
    myFirstSprite.SetPosition(0.f, Game::instance().getScreenSize().y - myFirstSprite.GetSize().y);
    mySecondSprite.SetPosition(0.f, myFirstSprite.GetPosition().y - myFirstSprite.GetSize().y);
}
