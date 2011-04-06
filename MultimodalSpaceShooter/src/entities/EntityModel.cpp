#include "entities/EntityModel.h"

EntityModel::EntityModel(const std::string& type, const std::string& imageFile, float xCoordinate, float speed, float time) :
myType(type),
myImageFile(imageFile),
myXCoordinate(xCoordinate),
mySpeed(speed),
myTime(time)
{

}

std::string EntityModel::getType() const
{
    return myType;
}

std::string EntityModel::getImageFile() const
{
    return myImageFile;
}

float EntityModel::getXCoordinate() const
{
    return myXCoordinate;
}

float EntityModel::getSpeed() const
{
    return mySpeed;
}

float EntityModel::getTime() const
{
    return myTime;
}