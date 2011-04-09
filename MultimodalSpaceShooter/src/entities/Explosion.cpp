#include "entities/Explosion.h"
#include "core/Managers.h"

const sf::Vector2f Explosion::FRAME_SIZE(320, 240);

Explosion::Explosion(const sf::Vector2f& initialPos) :
mySprite(*imageManager().get("explosion.png"), static_cast<int>(FRAME_SIZE.x), static_cast<int>(FRAME_SIZE.y), 0.05f)
{
    mySprite.SetPosition(initialPos);
    audioEngine().playSound("boum.wav");
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

sf::FloatRect Explosion::getBoundingRect() const
{
    return sf::FloatRect(mySprite.GetPosition(), FRAME_SIZE);
}
