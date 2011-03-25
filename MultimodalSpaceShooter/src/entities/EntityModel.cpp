#include "entities/EntityModel.h"

EntityModel::EntityModel(const std::string& type, int xCoordinate, int time) :
myType(type),
myXCoordinate(xCoordinate),
myTime(time)
{

}

std::string& EntityModel::getType(){
    return myType;
}

int EntityModel::getXCoordinate(){
    return myXCoordinate;
}

int EntityModel::getTime(){
    return myTime;
}