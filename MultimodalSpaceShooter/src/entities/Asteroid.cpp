#include "entities/Asteroid.h"
#include "entities/Explosion.h"
#include "core/Managers.h"
#include "utils/Utils.h"
#include "core/Game.h"

Asteroid::Asteroid(const sf::Image& image, const sf::Vector2f& position, float initialSpeed, float angle, float rotationSpeed) :
Entity(Object::DESTRUCTIVE),
mySprite(image),
mySpeed(initialSpeed),
myAngle(utils::degToRad(90.f + angle)),
myRotationSpeed(rotationSpeed)
{
    mySprite.SetPosition(position);

    // Put the origin to the center of the sprite to have proper rotations
    mySprite.SetOrigin(mySprite.GetSize() / 2.f);
}

void Asteroid::update(float frameTime)
{
    mySprite.Rotate(myRotationSpeed * frameTime);

    mySprite.Move(std::cos(myAngle) * mySpeed * frameTime, std::sin(myAngle) * mySpeed * frameTime);

    const sf::Vector2f& position = mySprite.GetPosition();
    const sf::Vector2i& screen   = Game::instance().getScreenSize();

    if(position.y >= screen.y || position.x + mySprite.GetSize().x < 0.f || position.x > screen.x)
        destroy();
}

void Asteroid::onCollision(Object::Type otherType, const sf::FloatRect& area)
{
    if(otherType == Object::WEAPON || otherType == Object::PLAYER)
    {
        sf::Vector2f decal(Explosion::FRAME_SIZE / 2.f - mySprite.GetSize() / 2.f);

        std::shared_ptr<Explosion> explosion(new Explosion(mySprite.GetPosition() - mySprite.GetOrigin() - decal));
        entityManager().addEntity(explosion);

        destroy();
    }
}

sf::FloatRect Asteroid::getBoundingRect() const
{
    return sf::FloatRect(mySprite.GetPosition() - mySprite.GetOrigin(), mySprite.GetSize());
}

void Asteroid::draw(sf::RenderTarget& window) const
{
    window.Draw(mySprite);
}
