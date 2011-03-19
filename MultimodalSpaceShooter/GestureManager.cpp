#include "GestureManager.h"
#include "NiCallbacksWrapper.h"
#include <iostream>
#include <algorithm>
#include <exception>

const std::string GestureManager::CONFIG_PATH("./config/OpenNIConfig.xml");

GestureManager::GestureManager() :
needPose(false)
{
    std::fill(strPose, strPose + 20, 0);

    //if(!initOpenNI())
    //    throw std::runtime_error("cannot init OpenNI");
}


GestureManager::~GestureManager()
{

}

bool GestureManager::initOpenNI()
{
    XnStatus nRetVal = XN_STATUS_OK;
    xn::EnumerationErrors errors;

    nRetVal = niContext.InitFromXmlFile(CONFIG_PATH.c_str(), &errors);

    if(nRetVal == XN_STATUS_NO_NODE_PRESENT)
    {
        XnChar strError[1024];
        errors.ToString(strError, 1024);
        std::cerr << strError << std::endl;

        return false;
    }
    else if(nRetVal != XN_STATUS_OK)
    {
        std::cerr << "Open failed: " << xnGetStatusString(nRetVal);
        return false;
    }

    // Get the depth and user nodes
    if(niContext.FindExistingNode(XN_NODE_TYPE_DEPTH, niDepthGenerator))
        std::cerr << "error: " << xnGetStatusString(nRetVal) << std::endl;
    if(niContext.FindExistingNode(XN_NODE_TYPE_USER, niUserGenerator))
        if(niUserGenerator.Create(niContext))
            std::cerr << "error: " << xnGetStatusString(nRetVal) << std::endl;

    // Create callbacks
    XnCallbackHandle userCallbacks;
    XnCallbackHandle calibrationCallbacks;
    XnCallbackHandle poseCallbacks;

    if(!niUserGenerator.IsCapabilitySupported(XN_CAPABILITY_SKELETON))
    {
        std::cerr << "User generator doesn't support skeleton" << std::endl;
        return false;
    }

    niUserGenerator.RegisterUserCallbacks(NiCallbacksWrapper::onNewUser, NiCallbacksWrapper::onLostUser, this, userCallbacks);
    niUserGenerator.GetSkeletonCap().RegisterCalibrationCallbacks(NiCallbacksWrapper::onCalibrationStart, NiCallbacksWrapper::onCalibrationEnd, this, calibrationCallbacks);

    if(niUserGenerator.GetSkeletonCap().NeedPoseForCalibration())
    {
        needPose = true;
        if(!niUserGenerator.IsCapabilitySupported(XN_CAPABILITY_POSE_DETECTION))
        {
            std::cerr << "Pose required but not supported" << std::endl;
            return false;
        }

        niUserGenerator.GetPoseDetectionCap().RegisterToPoseCallbacks(NiCallbacksWrapper::onPoseDetected, NULL, this, poseCallbacks);
        niUserGenerator.GetSkeletonCap().GetCalibrationPose(strPose);
    }

    niUserGenerator.GetSkeletonCap().SetSkeletonProfile(XN_SKEL_PROFILE_ALL);

    // Start generators
    if(niContext.StartGeneratingAll())
    {
        std::cerr << "Error while generating: " << xnGetStatusString(nRetVal) << std::endl;
        return false;
    }

    return true;
}

void GestureManager::update()
{
    xn::SceneMetaData sceneMD;
    xn::DepthMetaData depthMD;
    niDepthGenerator.GetMetaData(depthMD);

    niContext.WaitAndUpdateAll();

    niDepthGenerator.GetMetaData(depthMD);
    niUserGenerator.GetUserPixels(0, sceneMD);

    // We get only one user
    XnUserID user;
    XnUInt16 nUsers = 1;
    niUserGenerator.GetUsers(&user, nUsers);

    if(nUsers >= 1)
    {
        XnPoint3D bodyPos;

        niUserGenerator.GetCoM(user, bodyPos);
        setConvertedPos(myBodyPos, bodyPos);

        if(niUserGenerator.GetSkeletonCap().IsTracking(user))
        {
            XnSkeletonJointPosition leftHandPos;
            XnSkeletonJointPosition rightHandPos;

            niUserGenerator.GetSkeletonCap().GetSkeletonJointPosition(user, XN_SKEL_LEFT_HAND, leftHandPos);
            niUserGenerator.GetSkeletonCap().GetSkeletonJointPosition(user, XN_SKEL_RIGHT_HAND, rightHandPos);

            if(leftHandPos.fConfidence >= 0.5)
                setConvertedPos(myLeftHandPos, leftHandPos.position);
            if(rightHandPos.fConfidence >= 0.5)
                setConvertedPos(myRightHandPos, rightHandPos.position);
        }
    }
}

const sf::Vector2f& GestureManager::getBodyPosition() const
{
    return myBodyPos;
}

const sf::Vector2f& GestureManager::getLeftHandPosition() const
{
    return myLeftHandPos;
}

const sf::Vector2f& GestureManager::getRightHandPosition() const
{
    return myRightHandPos;
}

void GestureManager::setConvertedPos(sf::Vector2f& dest, const XnPoint3D& src)
{
    XnVector3D converted;
    niDepthGenerator.ConvertRealWorldToProjective(1, &src, &converted);

    dest.x = converted.X;
    dest.y = converted.Y;
}

// Callback: New user was detected
void GestureManager::onNewUser(xn::UserGenerator& generator, XnUserID nId)
{
    std::cout << "New user " << nId << std::endl;

    // New user found
    if(needPose)
        niUserGenerator.GetPoseDetectionCap().StartPoseDetection(strPose, nId);
    else
        niUserGenerator.GetSkeletonCap().RequestCalibration(nId, TRUE);
}

// Callback: An existing user was lost
void GestureManager::onLostUser(xn::UserGenerator& generator, XnUserID nId)
{
    std::cout << "Lost user " << nId << std::endl;
}

// Callback: Started calibration
void GestureManager::onCalibrationStart(xn::SkeletonCapability& capability, XnUserID nId)
{
    std::cout << "Calibration started for user " << nId << std::endl;
}
// Callback: Finished calibration
void GestureManager::onCalibrationEnd(xn::SkeletonCapability& capability, XnUserID nId, XnBool bSuccess)
{
    if(bSuccess)
    {
        // Calibration succeeded
        std::cout << "Calibration complete, start tracking user " << nId << std::endl;
        niUserGenerator.GetSkeletonCap().StartTracking(nId);
    }
    else
    {
        // Calibration failed
        std::cout << "Calibration failed for user " << nId << std::endl;

        if(needPose)
            niUserGenerator.GetPoseDetectionCap().StartPoseDetection(strPose, nId);
        else
            niUserGenerator.GetSkeletonCap().RequestCalibration(nId, TRUE);
    }
}

// Callback: Detected a pose
void GestureManager::onPoseDetected(xn::PoseDetectionCapability& capability, const XnChar* strPose, XnUserID nId)
{
    std::cout << "Pose " << strPose << " detected for user " << nId << std::endl;
    niUserGenerator.GetPoseDetectionCap().StopPoseDetection(nId);
    niUserGenerator.GetSkeletonCap().RequestCalibration(nId, TRUE);
}
