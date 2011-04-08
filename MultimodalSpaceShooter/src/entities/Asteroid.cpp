#include "entities/Asteroid.h"
#include "entities/Explosion.h"
#include "managers/Managers.h"

Asteroid::Asteroid(const sf::Image& image, const sf::Vector2f& position, const float initialSpeed) :
Entity(Object::DESTRUCTIVE),
mySprite(image),
mySpeed(initialSpeed)
{
    mySprite.SetPosition(position);
}


Asteroid::~Asteroid()
{

}

void Asteroid::update(float frameTime)
{
    mySprite.Move(0, mySpeed * frameTime);
}

void Asteroid::onCollision(Object::Type otherType, const sf::FloatRect& area)
{
    if(otherType == Object::WEAPON)
    {
        sf::Vector2f decal(320 / 2 - 80 / 2, 240 / 2 - 80 / 2);

        std::shared_ptr<Explosion> explosion(new Explosion(mySprite.GetPosition() - decal));
        entityManager().addEntity(explosion);

        destroy();
    }
}

sf::FloatRect Asteroid::getBoundingRect() const
{
    return sf::FloatRect(mySprite.GetPosition(), sf::Vector2f(80, 80));
}

void Asteroid::draw(sf::RenderTarget& window) const
{
    window.Draw(mySprite);
}
