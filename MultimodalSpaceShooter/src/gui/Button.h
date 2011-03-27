#ifndef BUTTON_H
#define BUTTON_H

#include "Widget.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Button : public Widget
{
    public:
        Button(const sf::Vector2f& position, const std::string& text, const sf::Image& background, const sf::Image& backgroundOver,
               const sf::Color& textColor = sf::Color::White, const sf::Color& selectedTextColor = sf::Color::White, unsigned int textSize = 40);
        virtual ~Button();

        virtual void onEvent(const sf::Event& event);
        virtual void draw(sf::RenderTarget& window) const;

    private:
        sf::Image  myImg;
        sf::Image  myImgOver;
        sf::Sprite myBackground;
        sf::Text   myText;

        sf::Color  myTextColor;
        sf::Color  mySelectedTextColor;

        static const sf::Vector2f TEXT_PADDING;

};

#endif // BUTTON_H