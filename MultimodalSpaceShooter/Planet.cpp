#include "Planet.h"
#include <SFML/Graphics.hpp>
#include <iostream>

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

void Planet::onCollision(const sf::FloatRect& area)
{
    std::cout << "Collision!" << std::endl;
}

sf::FloatRect Planet:: getBoundingRect() const
{
    return sf::FloatRect(mySprite.GetPosition(), sf::Vector2f(40, 40));
}

void Planet::draw(sf::RenderTarget& window) const
{
    window.Draw(mySprite);
}
