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

void MultimodalListener::onMultimodalEvent(MultimodalEvent event)
{

}
