#include "entities/Spaceship.h"
#include "entities/Missile.h"
#include "managers/Managers.h"
#include <SFML/Graphics.hpp>

const float Spaceship::SPEED = 200.f;

Spaceship::Spaceship() :
mySprite(*imageManager().get("spaceship.png"))
{
    mySprite.Move(400, 500);
}

Spaceship::~Spaceship()
{

}

void Spaceship::onPlayerAction(const sf::Event& event)
{
    if(event.Type == sf::Event::KeyPressed)
    {
        if(event.Key.Code == sf::Key::Space)
            fireMissile();
    }
}

void Spaceship::onMultimodalAction(const sf::Event& event)
{
    // TODO
}

void Spaceship::update(float frameTime)
{
    if(eventManager().getInput().IsKeyDown(sf::Key::Left))
        mySprite.Move(-SPEED * frameTime, 0);
    if(eventManager().getInput().IsKeyDown(sf::Key::Right))
        mySprite.Move( SPEED * frameTime, 0);
}

sf::FloatRect Spaceship::getBoundingRect() const
{
    return sf::FloatRect(mySprite.GetPosition(), mySprite.GetSize());
}

void Spaceship::draw(sf::RenderTarget& window) const
{
    window.Draw(mySprite);
}

void Spaceship::fireMissile()
{
    sf::Vector2f position(mySprite.GetPosition().x + mySprite.GetSize().x / 2, mySprite.GetPosition().y-20);

    std::shared_ptr<Missile> missile(new Missile(position));
    entityManager().addEntity(missile);

    audioEngine().playSound("piou.wav", 10.f);
}