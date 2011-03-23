#include "gui/Button.h"
#include <SFML/Graphics.hpp>

Button::Button(const sf::Vector2f& position, const std::string& text, const sf::Image& backgroundImage,
               const sf::Color& textColor, const sf::Color& selectedTextColor) :
myBackground(backgroundImage, position),
myText(text, sf::Font::GetDefaultFont(), 40),
myTextColor(textColor),
mySelectedTextColor(mySelectedTextColor)
{
    myBackground.SetSubRect(sf::IntRect(0, 0, 500, 80));
    myText.SetPosition(position.x + 10, position.y + 10);
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
