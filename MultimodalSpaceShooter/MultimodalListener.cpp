#include "MultimodalListener.h"
#include "Managers.h"

MultimodalListener::MultimodalListener()
{
    multimodalManager().addListener(this);
}


MultimodalListener::~MultimodalListener()
{
    multimodalManager().removeListener(this);
}

void MultimodalListener::onMultimodalEvent(GestureType gestureType)
{

}
