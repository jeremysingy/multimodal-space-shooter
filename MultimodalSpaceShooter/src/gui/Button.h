#ifndef BUTTON_H
#define BUTTON_H

#include "Widget.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Button : public Widget
{
    public:
        Button(const sf::Vector2f& position, const std::string& text, const sf::Image& backgroundImage,
               const sf::Color& textColor = sf::Color::White, const sf::Color& selectedTextColor = sf::Color::White);
        virtual ~Button();

        virtual void onEvent(const sf::Event& event);
        virtual void draw(sf::RenderTarget& window) const;

    private:
        sf::Sprite myBackground;
        sf::Text   myText;

        sf::Color  myTextColor;
        sf::Color  mySelectedTextColor;

};

#endif // BUTTON_H