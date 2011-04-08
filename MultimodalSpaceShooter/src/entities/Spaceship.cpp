#include "entities/Spaceship.h"
#include "entities/Missile.h"
#include "entities/SuperMissile.h"
#include "managers/Managers.h"
#include "core/Game.h"
#include <SFML/Graphics.hpp>

const float Spaceship::SPEED               = 200.f;
const float Spaceship::MISSILE_LEFT_ANGLE  = 360.f - 55.f;
const float Spaceship::MISSILE_UP_ANGLE    = 360.f - 90.f;
const float Spaceship::MISSILE_RIGHT_ANGLE = 360.f - 125.f;

Spaceship::Spaceship() :
mySprite(*imageManager().get("spaceship.png"),150, 165, 0.05f), myFire(),
myLife(DEFAULT_LIFE)
{
    mySprite.Move(Game::instance().getScreenSize().x / 2.f, Game::instance().getScreenSize().y - 165.f);

    myFire.setPosition(mySprite.GetPosition().x + 66.f, mySprite.GetPosition().y);
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

        if(event.Key.Code == sf::Key::Y)
            fireSuperMissiles();
    }
}

void Spaceship::onMultimodalAction(Multimodal::Event event)
{
    if(event == Multimodal::VolumeChangedArmDown && multimodalManager().getMicroLevel() == Volume::Medium)
        fireMissile();

    else if(event == Multimodal::VolumeChangedArmUp && multimodalManager().getMicroLevel() == Volume::High)
        fireSuperMissiles();
}

unsigned int Spaceship::getLife()
{
    return myLife;
}

void Spaceship::update(float frameTime)
{
    if(eventManager().getInput().IsKeyDown(sf::Key::Left))
        mySprite.Move(-SPEED * frameTime, 0);
    if(eventManager().getInput().IsKeyDown(sf::Key::Right))
        mySprite.Move( SPEED * frameTime, 0);

    sf::Vector2f newPos(0.f, mySprite.GetPosition().y);

    if(multimodalManager().getTrackingState() == Tracking::UserTracked)
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

    checkBorders();

    myFire.setPosition(mySprite.GetPosition().x+66,mySprite.GetPosition().y);
    myFire.update(frameTime);
    mySprite.update();
}

void Spaceship::onCollision(Object::Type otherType, const sf::FloatRect& area)
{
    if(otherType == Object::DESTRUCTIVE)
        if(myLife > 0)
            --myLife;
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
    sf::Vector2f position((mySprite.GetPosition().x + mySprite.GetSize().x / 2)-2, mySprite.GetPosition().y-10);

    std::shared_ptr<Missile> missile(new Missile(position));
    entityManager().addEntity(missile);

    audioEngine().playSound("piou.wav", 10.f);

    myFire.setOnFire(true);
}

void Spaceship::fireSuperMissiles()
{
    sf::Vector2f leftPos(mySprite.GetPosition().x + 9.f, mySprite.GetPosition().y - 6.f);
    sf::Vector2f rightPos(mySprite.GetPosition().x + 133.f, mySprite.GetPosition().y - 6.f);

    std::shared_ptr<SuperMissile> supermissileLL(new SuperMissile(leftPos, MISSILE_LEFT_ANGLE));
    entityManager().addEntity(supermissileLL);

    std::shared_ptr<SuperMissile> supermissileLM(new SuperMissile(leftPos, MISSILE_UP_ANGLE));
    entityManager().addEntity(supermissileLM);

    std::shared_ptr<SuperMissile> supermissileLR(new SuperMissile(leftPos, MISSILE_RIGHT_ANGLE));
    entityManager().addEntity(supermissileLR);

    std::shared_ptr<SuperMissile> supermissileRL(new SuperMissile(rightPos, MISSILE_LEFT_ANGLE));
    entityManager().addEntity(supermissileRL);

    std::shared_ptr<SuperMissile> supermissileRM(new SuperMissile(rightPos, MISSILE_UP_ANGLE));
    entityManager().addEntity(supermissileRM);

    std::shared_ptr<SuperMissile> supermissileRR(new SuperMissile(rightPos, MISSILE_RIGHT_ANGLE));
    entityManager().addEntity(supermissileRR);

    audioEngine().playSound("piou.wav", 10.f);
}

void Spaceship::checkBorders()
{
    float minPosX = -20.f;
    float maxPosX = Game::instance().getScreenSize().x - mySprite.GetSize().x + 20.f;

    if(mySprite.GetPosition().x < minPosX)
        mySprite.SetX(minPosX);
    else if(mySprite.GetPosition().x > maxPosX)
        mySprite.SetX(maxPosX);
}
