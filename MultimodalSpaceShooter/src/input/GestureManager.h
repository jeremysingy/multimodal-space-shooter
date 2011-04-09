#ifndef GESTUREMANAGER_H
#define GESTUREMANAGER_H

#include <XnCppWrapper.h>
#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/System.hpp>

namespace Tracking
{
    enum State
    {
        NotInitialized,    // OpenNI not initialized
        Initialized,       // Initialized but no user detected
        UserDetected,      // A user is detected
        UserTracked        // A user is tracked
    };
}

//////////////////////////////////////////////////
/// Manage the gestural events of the game with a
/// Kinect using OpenNI
//////////////////////////////////////////////////
class GestureManager
{
    public:
        GestureManager();
        ~GestureManager();

        bool initialize();
        Tracking::State getState();
        void startTracking();
        void stopTracking();

        const sf::Vector2f& getBodyPosition() const;
        const sf::Vector2f& getLeftHandPosition() const;
        const sf::Vector2f& getRightHandPosition() const;

    private:
        bool initOpenNI();
        void processThread();
        void update();
        void setConvertedPos(sf::Vector2f& dest, const XnPoint3D& src);

        // Callbacks
        void onNewUser(xn::UserGenerator& generator, XnUserID nId);
        void onLostUser(xn::UserGenerator& generator, XnUserID nId);
        void onCalibrationStart(xn::SkeletonCapability& capability, XnUserID nId);
        void onCalibrationEnd(xn::SkeletonCapability& capability, XnUserID nId, XnBool bSuccess);
        void onPoseDetected(xn::PoseDetectionCapability& capability, const XnChar* strPose, XnUserID nId);

        friend class NiCallbacksWrapper;

        // Constants
        static const std::string CONFIG_PATH;
        static const float       RESOLUTION_X;
        static const float       RESOLUTION_Y;
        static const float       FPS;

        // Attributes
        sf::Thread         myThread;
        Tracking::State    myCrtState;
        bool               myIsTracking;
        sf::Vector2f       myBodyPos;
        sf::Vector2f       myLeftHandPos;
        sf::Vector2f       myRightHandPos;

        // OpenNI variables
        xn::Context        myNiContext;
        xn::DepthGenerator myNiDepthGenerator;
        xn::UserGenerator  myNiUserGenerator;
        bool               myNeedPose;
        XnChar             myStrPose[20];
};

#endif // GESTUREMANAGER_H