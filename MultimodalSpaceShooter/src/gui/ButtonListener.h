#ifndef BUTTONLISTENER_H
#define BUTTONLISTENER_H

#include <string>

//////////////////////////////////////////////////
/// Base class for a button listener
//////////////////////////////////////////////////
class ButtonListener
{
    public:
        ButtonListener();
        virtual ~ButtonListener();

        virtual void onButtonPress(const std::string& buttonId); 
};

#endif // BUTTONLISTENER_H