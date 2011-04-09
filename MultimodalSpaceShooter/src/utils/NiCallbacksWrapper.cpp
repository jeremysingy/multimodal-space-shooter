#include "utils/NiCallbacksWrapper.h"
#include "input/GestureManager.h"

NiCallbacksWrapper::NiCallbacksWrapper(const GestureManager& gestureManager)
{

}

// Callback: New user was detected
void XN_CALLBACK_TYPE NiCallbacksWrapper::onNewUser(xn::UserGenerator& generator, XnUserID nId, void* pCookie)
{
    GestureManager* gestureMgr = reinterpret_cast<GestureManager*>(pCookie);
    
    if(gestureMgr)
        gestureMgr->onNewUser(generator, nId); 
}

// Callback: An existing user was lost
void XN_CALLBACK_TYPE NiCallbacksWrapper::onLostUser(xn::UserGenerator& generator, XnUserID nId, void* pCookie)
{
    GestureManager* gestureMgr = reinterpret_cast<GestureManager*>(pCookie);
    
    if(gestureMgr)
        gestureMgr->onLostUser(generator, nId); 
}

// Callback: Started calibration
void XN_CALLBACK_TYPE NiCallbacksWrapper::onCalibrationStart(xn::SkeletonCapability& capability, XnUserID nId, void* pCookie)
{
    GestureManager* gestureMgr = reinterpret_cast<GestureManager*>(pCookie);
    
    if(gestureMgr)
        gestureMgr->onCalibrationStart(capability, nId); 
}
// Callback: Finished calibration
void XN_CALLBACK_TYPE NiCallbacksWrapper::onCalibrationEnd(xn::SkeletonCapability& capability, XnUserID nId, XnBool bSuccess, void* pCookie)
{
    GestureManager* gestureMgr = reinterpret_cast<GestureManager*>(pCookie);
    
    if(gestureMgr)
        gestureMgr->onCalibrationEnd(capability, nId, bSuccess); 
}

// Callback: Detected a pose
void XN_CALLBACK_TYPE NiCallbacksWrapper::onPoseDetected(xn::PoseDetectionCapability& capability, const XnChar* strPose, XnUserID nId, void* pCookie)
{
    GestureManager* gestureMgr = reinterpret_cast<GestureManager*>(pCookie);
    
    if(gestureMgr)
        gestureMgr->onPoseDetected(capability, strPose, nId); 
}