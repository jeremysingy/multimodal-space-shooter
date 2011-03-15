#include "Explosion.h"
#include "Managers.h"

Explosion::Explosion(const sf::Vector2f& initialPos) :
mySprite(*imageManager().get("explosion.png"), 320, 240, 0.05f)
{
    mySprite.SetPosition(initialPos);
    audioEngine().playSound("boum.wav", 100.f);
}

Explosion::~Explosion()
{

}

void Explosion::update(float frameTime)
{
    mySprite.update();

    if(myClock.GetElapsedTime() >= mySprite.getNbFrames() * mySprite.getFrameTime())
        destroy();
}

void Explosion::draw(sf::RenderTarget& window) const
{
    window.Draw(mySprite);
}

sf::FloatRect Explosion:: getBoundingRect() const
{
    return sf::FloatRect(mySprite.GetPosition(), sf::Vector2f(80, 80));
}
