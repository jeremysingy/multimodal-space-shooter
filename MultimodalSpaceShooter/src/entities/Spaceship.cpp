#include "entities/Spaceship.h"
#include "entities/Missile.h"
#include "managers/Managers.h"
#include "core/Game.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <string>

const float Spaceship::SPEED = 200.f;

Spaceship::Spaceship() :
mySprite(*imageManager().get("spaceship.png"),150,165,0.002f), myFire()
{
    mySprite.Move(Game::instance().getScreenSize().x/2, Game::instance().getScreenSize().y-165);

    myFire.setPosition(mySprite.GetPosition().x+67,mySprite.GetPosition().y);
}


Spaceship::~Spaceship()
{
    myFire.destroy();
}

void Spaceship::onPlayerAction(const sf::Event& event)
{
    if(event.Type == sf::Event::KeyPressed)
    {
        if(event.Key.Code == sf::Key::Space)
            fireMissile();
    }
}

void Spaceship::onMultimodalAction(MultimodalEvent event)
{
    fireMissile();
}

void Spaceship::update(float frameTime)
{
    if(eventManager().getInput().IsKeyDown(sf::Key::Left))
        mySprite.Move(-SPEED * frameTime, 0);
    if(eventManager().getInput().IsKeyDown(sf::Key::Right))
        mySprite.Move( SPEED * frameTime, 0);

    sf::Vector2f newPos(0.f, mySprite.GetPosition().y);

    if(multimodalManager().isGestureEnabled())
    {
        sf::Vector2f newPos(multimodalManager().getBodyPosition().x, mySprite.GetPosition().y);
        mySprite.SetPosition(newPos);
    }
    else
    {
        if(eventManager().getInput().IsKeyDown(sf::Key::Left))
            mySprite.Move(-SPEED * frameTime, 0);
        if(eventManager().getInput().IsKeyDown(sf::Key::Right))
            mySprite.Move( SPEED * frameTime, 0);
    }

    myFire.setPosition(mySprite.GetPosition().x+67,mySprite.GetPosition().y);
    myFire.update(frameTime);
    mySprite.update();
}

sf::FloatRect Spaceship::getBoundingRect() const
{
    return sf::FloatRect(mySprite.GetPosition(), mySprite.GetSize());
}

void Spaceship::draw(sf::RenderTarget& window) const
{
    window.Draw(mySprite);
    myFire.draw(window);
}

void Spaceship::fireMissile()
{
    sf::Vector2f position(mySprite.GetPosition().x + mySprite.GetSize().x / 2, mySprite.GetPosition().y-20);

    std::shared_ptr<Missile> missile(new Missile(position));
    entityManager().addEntity(missile);

    audioEngine().playSound("piou.wav", 10.f);

    myFire.setOnFire(true);
}


