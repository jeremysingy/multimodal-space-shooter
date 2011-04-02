#include "entities/Fire.h"
#include "managers/Managers.h"

Fire::Fire() :
mySprite(*imageManager().get("fire.png"), 18, 37, 0.05f)
{
}

Fire::~Fire()
{

}

void Fire::update(float frameTime)
{
    if(onFire)
    {
        mySprite.update();

        if(myClock.GetElapsedTime() >= mySprite.getNbFrames() * mySprite.getFrameTime())
            onFire = false;
    }
}

void Fire::draw(sf::RenderTarget& window) const
{
    if(onFire)window.Draw(mySprite);
}

sf::FloatRect Fire:: getBoundingRect() const
{
    return sf::FloatRect(mySprite.GetPosition(), sf::Vector2f(80, 80));
}

void Fire::setOnFire(bool value)
{
    if(onFire == false && value == true)
        myClock.Reset();

    onFire = value;

}

void Fire::setPosition(float x, float y)
{
    mySprite.SetPosition(x,y);
}