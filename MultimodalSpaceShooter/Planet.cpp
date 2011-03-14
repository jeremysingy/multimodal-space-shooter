#include "Planet.h"
#include "Explosion.h"
#include "Managers.h"

Planet::Planet(const sf::Vector2f& position)
: mySprite(sf::Shape::Circle(0, 0, 40, sf::Color::Color(255, 128, 0, 255)))
{
    mySprite.SetOrigin(-40, -40);
    mySprite.SetPosition(position);
}


Planet::~Planet()
{

}

void Planet::update(float frameTime)
{

}

void Planet::onCollision(const sf::FloatRect& area)
{
    sf::Vector2f decal(320 / 2 - 80 / 2, 240 / 2 - 80 / 2);

    std::shared_ptr<Explosion> explosion(new Explosion(mySprite.GetPosition() - decal));
    sceneManager().addEntity(explosion);

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
