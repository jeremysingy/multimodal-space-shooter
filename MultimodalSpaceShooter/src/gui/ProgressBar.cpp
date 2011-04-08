#include "gui/ProgressBar.h"
#include "managers/Managers.h"

const float ProgressBar::WIDTH  = 100.f;
const float ProgressBar::HEIGHT = 5.f;

ProgressBar::ProgressBar(const sf::Vector2f& position, const sf::Color& color)
{
    myFilling = sf::Shape::Rectangle(sf::FloatRect(0, 0, /*1*/WIDTH, HEIGHT), color);
    myFilling.SetPosition(position);

    myOutline = sf::Shape::Rectangle(sf::FloatRect(0, 0, WIDTH, HEIGHT), sf::Color(0, 0, 0, 0), 1.f, color);
    myOutline.SetPosition(position);

    setLevel(0.f);
}

ProgressBar::~ProgressBar()
{

}

void ProgressBar::onEvent(const sf::Event& event)
{

}

void ProgressBar::onMultimodalEvent(Multimodal::Event event)
{

}

void ProgressBar::update(float frameTime)
{

}

void ProgressBar::draw(sf::RenderTarget& window) const
{
    window.Draw(myFilling);
    window.Draw(myOutline);
}

void ProgressBar::setLevel(float level)
{
    if(level < 0.f)
        level = 0.f;
    if(level > 100.f)
        level = 100.f;
    
    myFilling.SetScaleX(level / 100.f + 0.01f);
}
