#ifndef NICALLBACKSWRAPPER_H
#define NICALLBACKSWRAPPER_H

#include <XnCppWrapper.h>

class GestureManager;

//////////////////////////////////////////////////
/// Wrapper for OpenNI global callbacks functions
/// Simplifies the use of OpenNI in the GestureManager
/// class
//////////////////////////////////////////////////
class NiCallbacksWrapper
{
    public:
        NiCallbacksWrapper(const GestureManager& gestureManager);

        // Callback functions prototypes used by OpenNI
        static void XN_CALLBACK_TYPE onNewUser(xn::UserGenerator& generator, XnUserID nId, void* pCookie);
        static void XN_CALLBACK_TYPE onLostUser(xn::UserGenerator& generator, XnUserID nId, void* pCookie);
        static void XN_CALLBACK_TYPE onCalibrationStart(xn::SkeletonCapability& capability, XnUserID nId, void* pCookie);
        static void XN_CALLBACK_TYPE onCalibrationEnd(xn::SkeletonCapability& capability, XnUserID nId, XnBool bSuccess, void* pCookie);
        static void XN_CALLBACK_TYPE onPoseDetected(xn::PoseDetectionCapability& capability, const XnChar* strPose, XnUserID nId, void* pCookie);
};


#endif // NICALLBACKSWRAPPER_H