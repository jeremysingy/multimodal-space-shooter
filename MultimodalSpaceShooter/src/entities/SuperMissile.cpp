#include "entities/SuperMissile.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include "core/Game.h"
#include "managers/Managers.h"
#include "utils/Utils.h"
#include <iostream>
#include <string.h>

const float SuperMissile::SPEED = 250.f;

SuperMissile::SuperMissile(const sf::Vector2f& initialPosition, float angle) :
mySprite(*imageManager().get("superbullet.png")),
myAngle(utils::degToRad(angle)),
Entity(Object::WEAPON)
{
    mySprite.SetPosition(initialPosition);
}


SuperMissile::~SuperMissile()
{

}

void SuperMissile::onCollision(Object::Type otherType, const sf::FloatRect& area)
{
    if(otherType == Object::DESTRUCTIVE)
        destroy();
}

void SuperMissile::update(float frameTime)
{
    float y = SPEED * frameTime;

    mySprite.Move(std::cos(myAngle) * SPEED * frameTime, std::sin(myAngle) * SPEED * frameTime);

    if(mySprite.GetPosition().y <= 0  || mySprite.GetPosition().x <= 0 || mySprite.GetPosition().x >= Game::instance().getScreenSize().x)
        destroy();
}

sf::FloatRect SuperMissile::getBoundingRect() const
{
    return sf::FloatRect(mySprite.GetPosition(), mySprite.GetSize());
}

void SuperMissile::draw(sf::RenderTarget& window) const
{
    window.Draw(mySprite);
}