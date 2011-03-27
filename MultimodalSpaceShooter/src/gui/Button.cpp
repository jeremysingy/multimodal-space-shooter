#include "gui/Button.h"
#include <SFML/Graphics.hpp>

const sf::Vector2f Button::TEXT_PADDING(10, 10);

Button::Button(const sf::Vector2f& position, const std::string& text, const sf::Image& background, const sf::Image& backgroundOver,
               const sf::Color& textColor, const sf::Color& selectedTextColor, unsigned int textSize) :
myImg(background),
myImgOver(backgroundOver),
myBackground(background, position),
myText(text, sf::Font::GetDefaultFont(), textSize),
myTextColor(textColor),
mySelectedTextColor(mySelectedTextColor)
{
    myText.SetPosition(position + TEXT_PADDING);
}


Button::~Button()
{

}

void Button::onEvent(const sf::Event& event)
{
    // TODO
}

void Button::draw(sf::RenderTarget& window) const
{
    window.Draw(myBackground);
    window.Draw(myText);
}
