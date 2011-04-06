#include "entities/Spaceship.h"
#include "entities/Missile.h"
#include "entities/SuperMissile.h"
#include "managers/Managers.h"
#include "core/Game.h"
#include <SFML/Graphics.hpp>

const float Spaceship::SPEED = 200.f;

Spaceship::Spaceship() :
mySprite(*imageManager().get("spaceship.png"),150,165,0.05f), myFire()
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
    sf::Vector2f position(mySprite.GetPosition().x + 9.f, mySprite.GetPosition().y - 6.f);
    sf::Vector2f position2(mySprite.GetPosition().x + 133.f, mySprite.GetPosition().y - 6.f);

    std::shared_ptr<SuperMissile> supermissileLL(new SuperMissile(position, left, 0.3f));
    entityManager().addEntity(supermissileLL);

    std::shared_ptr<SuperMissile> supermissileLM(new SuperMissile(position, straight, 0.3f));
    entityManager().addEntity(supermissileLM);

    std::shared_ptr<SuperMissile> supermissileLR(new SuperMissile(position, right, 0.3f));
    entityManager().addEntity(supermissileLR);

    std::shared_ptr<SuperMissile> supermissileRL(new SuperMissile(position2, left, 0.3f));
    entityManager().addEntity(supermissileRL);

    std::shared_ptr<SuperMissile> supermissileRM(new SuperMissile(position2, straight, 0.3f));
    entityManager().addEntity(supermissileRM);

    std::shared_ptr<SuperMissile> supermissileRR(new SuperMissile(position2, right, 0.3f));
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
