#include "gui/Menu.h"
#include "managers/Managers.h"
#include "core/Game.h"
#include "ButtonListener.h"
#include <SFML/Graphics.hpp>

const float Menu::MARGIN(10.f);

Menu::Menu(const std::string& title, const sf::Image& backgroundImage) :
myBackground(backgroundImage),
myTitle(title, sf::Font::GetDefaultFont(), 40),
myNextButtonPos(250.f)
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

void Menu::addButton(const std::string& id, const std::string& text, ButtonListener* listener)
{
    sf::Image& img     = *imageManager().get("button.png");
    sf::Image& imgOver = *imageManager().get("button_sel.png");

    const sf::Vector2i screenSize = Game::instance().getScreenSize();

    Button button(id, sf::Vector2f(screenSize.x / 2.f - 500.f / 2.f, myNextButtonPos), text, img, imgOver);
    if(listener)
        button.addListener(listener);

    myButtons.push_back(button);

    myNextButtonPos += img.GetHeight() + MARGIN;
}

void Menu::onEvent(const sf::Event& event)
{
    for(std::vector<Button>::iterator i = myButtons.begin(); i != myButtons.end(); ++i)
        i->onEvent(event);
}

void Menu::onMultimodalEvent(MultimodalEvent event)
{
    for(std::vector<Button>::iterator i = myButtons.begin(); i != myButtons.end(); ++i)
        i->onMultimodalEvent(event);
}

void Menu::update(float frameTime)
{
    for(std::vector<Button>::iterator i = myButtons.begin(); i != myButtons.end(); ++i)
        i->update(frameTime);
}

void Menu::draw(sf::RenderTarget& window) const
{
    window.Draw(myBackground);
    window.Draw(myTitle);

    for(std::vector<Button>::const_iterator i = myButtons.begin(); i != myButtons.end(); ++i)
        i->draw(window);
}
