#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include "gui/Widget.h"
#include <SFML/Graphics.hpp>

class ButtonListener;

//////////////////////////////////////////////////
/// Represents a progress bar
//////////////////////////////////////////////////
class ProgressBar : public Widget
{
    public:
        ProgressBar(const sf::Vector2f& position, const sf::Color& color);

        virtual void onEvent(const sf::Event& event);
        virtual void onMultimodalEvent(Multimodal::Event event);
        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;

        void setLevel(float level);

    private:
        static const float WIDTH;
        static const float HEIGHT;

        sf::Shape myFilling;
        sf::Shape myOutline;
};

#endif // PROGRESSBAR_H