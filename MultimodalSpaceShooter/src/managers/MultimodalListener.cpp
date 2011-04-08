#include "managers/MultimodalListener.h"
#include "managers/Managers.h"

MultimodalListener::MultimodalListener()
{
    multimodalManager().addListener(this);
}


MultimodalListener::~MultimodalListener()
{
    multimodalManager().removeListener(this);
}

void MultimodalListener::onTrackingStateChanged(Tracking::State newState)
{

}

void MultimodalListener::onMultimodalEvent(Multimodal::Event event)
{

}
