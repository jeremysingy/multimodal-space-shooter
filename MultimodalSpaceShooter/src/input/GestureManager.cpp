#include "input/GestureManager.h"
#include "utils/NiCallbacksWrapper.h"
#include "core/Game.h"
#include <iostream>
#include <algorithm>
#include <exception>

const std::string GestureManager::CONFIG_PATH("./config/OpenNIConfig.xml");
const float       GestureManager::RESOLUTION_X = 640.f;
const float       GestureManager::RESOLUTION_Y = 480.f;
const float       GestureManager::FPS = 20.f;

GestureManager::GestureManager() :
myThread(&GestureManager::processThread, this),
myCrtState(Tracking::NotInitialized),
myIsTracking(false),
myNeedPose(false)
{
    std::fill(myStrPose, myStrPose + 20, 0);
}

GestureManager::~GestureManager()
{
    myNiContext.Shutdown();
}

bool GestureManager::initialize()
{
    if(initOpenNI())
        myCrtState = Tracking::Initialized;

    return myCrtState == Tracking::Initialized;
}

Tracking::State GestureManager::getState()
{
    return myCrtState;
}

bool GestureManager::initOpenNI()
{
    XnStatus nRetVal = XN_STATUS_OK;
    xn::EnumerationErrors errors;

    nRetVal = myNiContext.InitFromXmlFile(CONFIG_PATH.c_str(), &errors);

    if(nRetVal == XN_STATUS_NO_NODE_PRESENT)
    {
        XnChar strError[1024];
        errors.ToString(strError, 1024);
        std::cerr << "OpenNI node: " << strError << std::endl;

        return false;
    }
    else if(nRetVal != XN_STATUS_OK)
    {
        std::cerr << "OpenNI failed: " << xnGetStatusString(nRetVal);
        return false;
    }

    // Get the depth and user nodes
    if(myNiContext.FindExistingNode(XN_NODE_TYPE_DEPTH, myNiDepthGenerator))
        std::cerr << "error: " << xnGetStatusString(nRetVal) << std::endl;
    if(myNiContext.FindExistingNode(XN_NODE_TYPE_USER, myNiUserGenerator))
        if(myNiUserGenerator.Create(myNiContext))
            std::cerr << "error: " << xnGetStatusString(nRetVal) << std::endl;

    // Create callbacks
    XnCallbackHandle userCallbacks;
    XnCallbackHandle calibrationCallbacks;
    XnCallbackHandle poseCallbacks;

    if(!myNiUserGenerator.IsCapabilitySupported(XN_CAPABILITY_SKELETON))
    {
        std::cerr << "User generator doesn't support skeleton" << std::endl;
        return false;
    }

    myNiUserGenerator.RegisterUserCallbacks(NiCallbacksWrapper::onNewUser, NiCallbacksWrapper::onLostUser, this, userCallbacks);
    myNiUserGenerator.GetSkeletonCap().RegisterCalibrationCallbacks(NiCallbacksWrapper::onCalibrationStart, NiCallbacksWrapper::onCalibrationEnd, this, calibrationCallbacks);

    if(myNiUserGenerator.GetSkeletonCap().NeedPoseForCalibration())
    {
        myNeedPose = true;
        if(!myNiUserGenerator.IsCapabilitySupported(XN_CAPABILITY_POSE_DETECTION))
        {
            std::cerr << "Pose required but not supported" << std::endl;
            return false;
        }

        myNiUserGenerator.GetPoseDetectionCap().RegisterToPoseCallbacks(NiCallbacksWrapper::onPoseDetected, NULL, this, poseCallbacks);
        myNiUserGenerator.GetSkeletonCap().GetCalibrationPose(myStrPose);
    }

    myNiUserGenerator.GetSkeletonCap().SetSkeletonProfile(XN_SKEL_PROFILE_ALL);

    // Start generators
    if(myNiContext.StartGeneratingAll())
    {
        std::cerr << "Error while generating: " << xnGetStatusString(nRetVal) << std::endl;
        return false;
    }

    return true;
}

void GestureManager::startTracking()
{
    if(myCrtState == Tracking::Initialized)
    {
        myIsTracking = true;
        myThread.Launch();
    }
}

void GestureManager::stopTracking()
{
    if(myIsTracking)
    {
        myIsTracking = false;
        myThread.Wait();
    }
}

void GestureManager::processThread()
{
    while(myIsTracking)
    {
        update();
        sf::Sleep(1.f / FPS);
    }
}

void GestureManager::update()
{
    xn::SceneMetaData sceneMD;
    xn::DepthMetaData depthMD;
    myNiDepthGenerator.GetMetaData(depthMD);

    myNiContext.WaitAndUpdateAll();

    myNiDepthGenerator.GetMetaData(depthMD);
    myNiUserGenerator.GetUserPixels(0, sceneMD);

    // We get only one user
    XnUserID user;
    XnUInt16 nUsers = 1;
    myNiUserGenerator.GetUsers(&user, nUsers);

    if(nUsers >= 1)
    {
        XnPoint3D bodyPos;

        myNiUserGenerator.GetCoM(user, bodyPos);
        setConvertedPos(myBodyPos, bodyPos);

        if(myNiUserGenerator.GetSkeletonCap().IsTracking(user))
        {
            XnSkeletonJointPosition leftHandPos;
            XnSkeletonJointPosition rightHandPos;

            myNiUserGenerator.GetSkeletonCap().GetSkeletonJointPosition(user, XN_SKEL_LEFT_HAND, leftHandPos);
            myNiUserGenerator.GetSkeletonCap().GetSkeletonJointPosition(user, XN_SKEL_RIGHT_HAND, rightHandPos);

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
    XnPoint3D converted;
    myNiDepthGenerator.ConvertRealWorldToProjective(1, &src, &converted);
    
    converted.X = converted.X / RESOLUTION_X * Game::instance().getScreenSize().x;
    converted.Y = converted.Y / RESOLUTION_Y * Game::instance().getScreenSize().y;

    dest.x = converted.X;
    dest.y = converted.Y;
}

// Callback: New user was detected
void GestureManager::onNewUser(xn::UserGenerator& generator, XnUserID nId)
{
    std::cout << "New user " << nId << std::endl;
    myCrtState = Tracking::UserDetected;

    // New user found
    if(myNeedPose)
        myNiUserGenerator.GetPoseDetectionCap().StartPoseDetection(myStrPose, nId);
    else
        myNiUserGenerator.GetSkeletonCap().RequestCalibration(nId, TRUE);
}

// Callback: An existing user was lost
void GestureManager::onLostUser(xn::UserGenerator& generator, XnUserID nId)
{
    myCrtState = Tracking::Initialized;
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
        // Calibration succeeded£
        myCrtState = Tracking::UserTracked;
        std::cout << "Calibration complete, start tracking user " << nId << std::endl;
        myNiUserGenerator.GetSkeletonCap().StartTracking(nId);
    }
    else
    {
        // Calibration failed
        std::cout << "Calibration failed for user " << nId << std::endl;

        if(myNeedPose)
            myNiUserGenerator.GetPoseDetectionCap().StartPoseDetection(myStrPose, nId);
        else
            myNiUserGenerator.GetSkeletonCap().RequestCalibration(nId, TRUE);
    }
}

// Callback: Detected a pose
void GestureManager::onPoseDetected(xn::PoseDetectionCapability& capability, const XnChar* strPose, XnUserID nId)
{
    std::cout << "Pose " << strPose << " detected for user " << nId << std::endl;
    myNiUserGenerator.GetPoseDetectionCap().StopPoseDetection(nId);
    myNiUserGenerator.GetSkeletonCap().RequestCalibration(nId, TRUE);
}
