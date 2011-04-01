#ifndef GESTUREMANAGER_H
#define GESTUREMANAGER_H

#include <XnCppWrapper.h>
#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/System.hpp>

class GestureManager
{
    public:
        GestureManager();
        ~GestureManager();

        void initialize();
        bool isInitialized();
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

        static const std::string CONFIG_PATH;
        static const float       RESOLUTION_X;
        static const float       RESOLUTION_Y;

        sf::Thread         myThread;

        bool               myIsInitialized;
        bool               myIsTracking;
        xn::Context        niContext;
        xn::DepthGenerator niDepthGenerator;
        xn::UserGenerator  niUserGenerator;
        bool               needPose;
        XnChar             strPose[20];

        sf::Vector2f myBodyPos;
        sf::Vector2f myLeftHandPos;
        sf::Vector2f myRightHandPos;
};

#endif // GESTUREMANAGER_H