#include "gui/Menu.h"
#include "managers/Managers.h"
#include "core/Game.h"
#include <SFML/Graphics.hpp>

const float Menu::MARGIN(10.f);

Menu::Menu(const std::string& title, const sf::Image& backgroundImage) :
myBackground(backgroundImage),
myTitle(title, sf::Font::GetDefaultFont(), 40),
myNextButtonPos(150.f)
{
    const sf::Vector2i screenSize = Game::instance().getScreenSize();
    const sf::Vector2f spriteSize = myBackground.GetSize();
    myBackground.SetPosition(screenSize.x / 2.f - spriteSize.x / 2.f, screenSize.y / 2.f - spriteSize.y / 2.f);

    const sf::FloatRect titleSize = myTitle.GetRect();
    myTitle.SetPosition(screenSize.x / 2.f - titleSize.Width / 2.f, myBackground.GetPosition().y + 10);
}


Menu::~Menu()
{

}

void Menu::addButton(const std::string& text)
{
    sf::Image& img     = *imageManager().get("button.png");
    sf::Image& imgOver = *imageManager().get("button_sel.png");

    const sf::Vector2i screenSize = Game::instance().getScreenSize();
    myButtons.push_back(Button(sf::Vector2f(screenSize.x / 2.f - 500.f / 2.f, myNextButtonPos), text, img, imgOver));

    myNextButtonPos += img.GetHeight() + MARGIN;
}

void Menu::onEvent(const sf::Event& event)
{
    // TODO
}

void Menu::draw(sf::RenderTarget& window) const
{
    window.Draw(myBackground);
    window.Draw(myTitle);

    for(std::vector<Button>::const_iterator i = myButtons.begin(); i != myButtons.end(); ++i)
        i->draw(window);
}
