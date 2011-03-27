#ifndef MENU_H
#define MENU_H

#include "Widget.h"
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Menu : public Widget
{
    public:
        Menu(const std::string& title, const sf::Image& backgroundImage);
        virtual ~Menu();

        virtual void onEvent(const sf::Event& event);
        virtual void draw(sf::RenderTarget& window) const;

        void addButton(const std::string& text);

    private:
        sf::Sprite          myBackground;
        sf::Text            myTitle;
        std::vector<Button> myButtons;
        float               myNextButtonPos;

        static const float MARGIN;
};

#endif // MENU_H