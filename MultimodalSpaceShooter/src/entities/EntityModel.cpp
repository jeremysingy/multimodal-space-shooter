#include "entities/EntityModel.h"

EntityModel::EntityModel(const std::string& type, const std::string& imageFile, float xCoordinate, float time) :
myType(type),
myImageFile(imageFile),
myXCoordinate(xCoordinate),
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

float EntityModel::getTime() const
{
    return myTime;
}