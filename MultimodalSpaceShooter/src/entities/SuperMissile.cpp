#include "entities/SuperMissile.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include "core/Game.h"
#include "managers/Managers.h"
#include <iostream>
#include <string.h>

const float SuperMissile::SPEED = 250.f;

SuperMissile::SuperMissile(const sf::Vector2f& initialPos, direction direc, float angle) :
mySprite(*imageManager().get("superbullet.png")),
myDirection(direc),
myAngle(angle),
Entity(WEAPON)
{
    mySprite.SetPosition(initialPos);
}


SuperMissile::~SuperMissile()
{

}

void SuperMissile::onCollision(Type otherType, const sf::FloatRect& area)
{
    if(otherType == DESTRUCTIVE)
        destroy();
}

void SuperMissile::update(float frameTime)
{
    float y = SPEED*frameTime;

    if(myDirection == right)
    {
        mySprite.Move(tan(myAngle)*y,-y);
    }
    else if(myDirection == left)
    {
        mySprite.Move(-tan(myAngle)*y,-y);
    }
    else
    {
        mySprite.Move(0, -y);
    }

    if(mySprite.GetPosition().y <= 0  || 
        mySprite.GetPosition().x <= 0 || 
        mySprite.GetPosition().x >= Game::instance().getScreenSize().x)
        destroy();
}

sf::FloatRect SuperMissile::getBoundingRect() const
{
    return sf::FloatRect(mySprite.GetPosition(), sf::Vector2f(1, 10));
}

void SuperMissile::draw(sf::RenderTarget& window) const
{
    window.Draw(mySprite);
}