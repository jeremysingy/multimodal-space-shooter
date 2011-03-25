#include "gui/Menu.h"
#include "managers/Managers.h"
#include <SFML/Graphics.hpp>

Menu::Menu(const std::string& title, const sf::Image& backgroundImage) :
myTitle(title, sf::Font::GetDefaultFont(), 40),
myBackground(backgroundImage)
{
    //myTestButton(sf::Vector2f(250, 100), "Test", *imageManager().get("button_test.png"))
    //myBackground.SetSubRect(sf::IntRect(0, 0, 500, 80));
    //myText.SetPosition(position.x + 10, position.y + 10);
}


Menu::~Menu()
{

}

void Menu::addButton(const std::string& text)
{
    sf::Image& img = *imageManager().get("");


    myButtons.push_back(Button(sf::Vector2f(50, 0), "text", img));
    myButtons.push_back(Button(sf::Vector2f(50, 50), "text2", img));
}

void Menu::onEvent(const sf::Event& event)
{
    // TODO
}

void Menu::draw(sf::RenderTarget& window) const
{
    window.Draw(myBackground);
    window.Draw(myTitle);
}
