#include "Missile.h"
#include <SFML/Graphics.hpp>

const float Missile::SPEED = 500.f;

Missile::Missile(const sf::Vector2f& initialPos)
: myShape(sf::Shape::Line(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 10.f), 1.f, sf::Color::Red))
{
    myShape.SetPosition(initialPos);
}


Missile::~Missile()
{

}

void Missile::update(float frameTime)
{
    myShape.Move(0, -SPEED * frameTime);

    if(myShape.GetPosition().y <= 20)
        destroy();
}

void Missile::draw(sf::RenderTarget& window) const
{
    window.Draw(myShape);
}
