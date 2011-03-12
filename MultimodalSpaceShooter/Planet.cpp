#include "Planet.h"
#include <SFML/Graphics.hpp>

Planet::Planet(const sf::Vector2f& position)
: mySprite(sf::Shape::Circle(0, 40, 40, sf::Color::Color(255, 128, 0, 255)))
{
    mySprite.SetPosition(position);
}


Planet::~Planet()
{

}

void Planet::update(float frameTime)
{

}

void Planet::draw(sf::RenderTarget& window) const
{
    window.Draw(mySprite);
}
