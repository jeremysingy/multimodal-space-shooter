#include "entities/Planet.h"
#include "entities/Explosion.h"
#include "core/Managers.h"
#include "core/Game.h"

Planet::Planet(const sf::Image& image, const sf::Vector2f& position, const float initialSpeed) :
Entity(Object::DESTRUCTIVE),
mySprite(image),
mySpeed(initialSpeed)
{
    mySprite.SetPosition(position);
}

void Planet::update(float frameTime)
{
    mySprite.Move(0, mySpeed * frameTime);

    if(mySprite.GetPosition().y >= Game::instance().getScreenSize().y)
        destroy();
}

void Planet::onCollision(Object::Type otherType, const sf::FloatRect& area)
{
    if(otherType == Object::WEAPON || otherType == Object::PLAYER)
    {
        sf::Vector2f decal(Explosion::FRAME_SIZE / 2.f - mySprite.GetSize() / 2.f);

        std::shared_ptr<Explosion> explosion(new Explosion(mySprite.GetPosition() - decal));
        entityManager().addEntity(explosion);

        destroy();
    }
}

sf::FloatRect Planet::getBoundingRect() const
{
    return sf::FloatRect(mySprite.GetPosition(), mySprite.GetSize());
}

void Planet::draw(sf::RenderTarget& window) const
{
    window.Draw(mySprite);
}
