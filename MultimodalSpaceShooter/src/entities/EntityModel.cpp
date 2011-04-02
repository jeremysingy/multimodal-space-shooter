#include "entities/EntityModel.h"

EntityModel::EntityModel(const std::string& type, float xCoordinate, float time) :
myType(type),
myXCoordinate(xCoordinate),
myTime(time)
{

}

std::string EntityModel::getType() const{
    return myType;
}

float EntityModel::getXCoordinate() const {
    return myXCoordinate;
}

float EntityModel::getTime() const{
    return myTime;
}