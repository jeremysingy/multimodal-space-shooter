#include "entities/Missile.h"
#include <SFML/Graphics.hpp>
#include "managers/Managers.h"

const float Missile::SPEED = 500.f;

Missile::Missile(const sf::Vector2f& initialPos) :
Entity(WEAPON),
mySprite(*imageManager().get("bullet.png"))
{
    mySprite.SetPosition(initialPos);
}


Missile::~Missile()
{

}

void Missile::onCollision(Type otherType, const sf::FloatRect& area)
{
    if(otherType == DESTRUCTIVE)
        destroy();
}

void Missile::update(float frameTime)
{
    mySprite.Move(0, -SPEED * frameTime);

    if(mySprite.GetPosition().y <= 0)
        destroy();
}

sf::FloatRect Missile::getBoundingRect() const
{
    return sf::FloatRect(mySprite.GetPosition(), sf::Vector2f(1, 10));
}

void Missile::draw(sf::RenderTarget& window) const
{
    window.Draw(mySprite);
}
