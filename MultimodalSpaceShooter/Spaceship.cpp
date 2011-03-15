#include "Spaceship.h"
#include "Missile.h"
#include "Managers.h"
#include <SFML/Graphics.hpp>

const float Spaceship::SPEED = 200.f;

Spaceship::Spaceship() :
mySprite(*imageManager().get("spaceship.png"))
{
    //mySprite.SetImage(*imageManager().get("spaceship.png"));
    mySprite.Move(400, 500);
}

Spaceship::~Spaceship()
{

}

void Spaceship::onEvent(const sf::Event& event)
{
    if(event.Type == sf::Event::KeyPressed)
    {
        if(event.Key.Code == sf::Key::Space)
            fireMissile();
    }
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
    sf::Vector2f position(mySprite.GetPosition().x + mySprite.GetSize().x / 2, mySprite.GetPosition().y);

    std::shared_ptr<Missile> missile(new Missile(position));
    sceneManager().addEntity(missile);
	
	audioEngine().playSound("piou.wav", 10.f);
}
