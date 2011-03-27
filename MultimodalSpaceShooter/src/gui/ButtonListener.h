#ifndef BUTTONLISTENER_H
#define BUTTONLISTENER_H

//////////////////////////////////////////////////
/// Base class for an event listener
//////////////////////////////////////////////////
class ButtonListener
{
    public:
        ButtonListener();
        virtual ~ButtonListener();

        virtual void onButtonPress();
};

#endif // BUTTONLISTENER_H