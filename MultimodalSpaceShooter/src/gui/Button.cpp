#include "gui/Button.h"
#include "managers/Managers.h"
#include "gui/ButtonListener.h"
#include <SFML/Graphics.hpp>

const sf::Vector2f Button::TEXT_PADDING(20, 20);

Button::Button(const std::string& id, const sf::Vector2f& position, const std::string& text, const sf::Image& background,
               const sf::Image& backgroundOver, const sf::Color& textColor, const sf::Color& selectedTextColor, unsigned int textSize) :
myId(id),
myImg(background),
myImgOver(backgroundOver),
myBackground(background, position),
myText(text, sf::Font::GetDefaultFont(), textSize),
myTextColor(textColor),
mySelectedTextColor(mySelectedTextColor),
myIsSelected(false)
{
    myText.SetPosition(position + TEXT_PADDING);
}

Button::~Button()
{

}

void Button::onEvent(const sf::Event& event)
{
    if(myIsSelected)
    {
        if(event.Type == sf::Event::MouseButtonPressed && event.MouseButton.Button == sf::Mouse::Left)
            for(std::set<ButtonListener*>::iterator i = myListeners.begin(); i != myListeners.end(); ++i)
                (*i)->onButtonPress(myId);
    }
}

void Button::onMultimodalEvent(MultimodalEvent event)
{
    std::cout << "test" << std::endl;
    if(myIsSelected)
    {
        std::cout << "test 2" << std::endl;
        for(std::set<ButtonListener*>::iterator i = myListeners.begin(); i != myListeners.end(); ++i)
        {
            (*i)->onButtonPress(myId);
        }
    }
}

void Button::update(float frameTime)
{
    sf::FloatRect boundingRect(myBackground.GetPosition(), myBackground.GetSize());

    sf::Vector2f mousePos(static_cast<float>(eventManager().getInput().GetMouseX()),
                          static_cast<float>(eventManager().getInput().GetMouseY()));

    sf::FloatRect cursorRect(mousePos, sf::Vector2f(1.f, 1.f));

    if(multimodalManager().getTrackingState() == Tracking::UserTracked)
        cursorRect = sf::FloatRect(multimodalManager().getRightHandPosition(), sf::Vector2f(1.f, 1.f));

    bool isSelected = boundingRect.Intersects(cursorRect);

    if(isSelected && !myIsSelected)
    {
        myBackground.SetImage(myImgOver);
        myIsSelected = true;
    }

    if(!isSelected && myIsSelected)
    {
        myBackground.SetImage(myImg);
        myIsSelected = false;
    }
}

void Button::draw(sf::RenderTarget& window) const
{
    window.Draw(myBackground);
    window.Draw(myText);
}

void Button::addListener(ButtonListener* listener)
{
    myListeners.insert(listener);
}
