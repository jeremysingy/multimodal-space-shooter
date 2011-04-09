#include "input/MultimodalListener.h"
#include "core/Managers.h"

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
