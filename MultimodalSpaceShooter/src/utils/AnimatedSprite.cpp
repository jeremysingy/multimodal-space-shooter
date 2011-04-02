#include "utils/AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(const sf::Image& image, unsigned int frameWidth, unsigned int frameHeight, float frameTime) :
sf::Sprite(image),
myFrameTime(frameTime),
myCrtFrame(0)
{
    unsigned int nbFrameX = image.GetWidth()  / frameWidth;
    unsigned int nbFrameY = image.GetHeight() / frameHeight;

    for(unsigned int i = 0; i < nbFrameY; ++i)
    {
        unsigned int y = i * frameHeight;

        for(unsigned int j = 0; j < nbFrameX; ++j)
        {
            unsigned int x = j * frameWidth;
            
            myFrames.push_back(sf::IntRect(x, y, frameWidth, frameHeight));
        }
    }

    SetSubRect(myFrames[myCrtFrame]);
}

void AnimatedSprite::update()
{
    unsigned int framesToSkip = static_cast<unsigned int>(myClock.GetElapsedTime() / myFrameTime);

    if(framesToSkip > 0)
    {
        myCrtFrame = (myCrtFrame + framesToSkip) % myFrames.size();
        SetSubRect(myFrames[myCrtFrame]);
        myClock.Reset();
    }
}

float AnimatedSprite::getFrameTime() const
{
    return myFrameTime;
}

unsigned int AnimatedSprite::getNbFrames() const
{
    return myFrames.size();
}

unsigned int AnimatedSprite::getCrtFrame() const
{
    return myCrtFrame;
}
