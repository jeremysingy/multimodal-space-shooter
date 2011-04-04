#include "entities/Planet.h"
#include "entities/Explosion.h"
#include "managers/Managers.h"

Planet::Planet(const sf::Vector2f& position, const float initialSpeed) :
mySprite(*imageManager().get("planet1.png")),
mySpeed(initialSpeed)
{
    mySprite.SetPosition(position);
}


Planet::~Planet()
{

}

void Planet::update(float frameTime)
{
    mySprite.Move(0, mySpeed * frameTime);
}

void Planet::onCollision(const sf::FloatRect& area)
{
    sf::Vector2f decal(320 / 2 - 80 / 2, 240 / 2 - 80 / 2);

    std::shared_ptr<Explosion> explosion(new Explosion(mySprite.GetPosition() - decal));
    entityManager().addEntity(explosion);

    destroy();
}

sf::FloatRect Planet::getBoundingRect() const
{
    return sf::FloatRect(mySprite.GetPosition(), sf::Vector2f(80, 80));
}

void Planet::draw(sf::RenderTarget& window) const
{
    window.Draw(mySprite);
}
