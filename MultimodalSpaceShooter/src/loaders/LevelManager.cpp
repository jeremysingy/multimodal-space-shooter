#include "loaders/LevelManager.h"
#include <utils/tinyxml/tinyxml.h>
#include <sstream>

LevelManager::LevelManager(){

}

LevelManager::~LevelManager(){

}

int LevelManager::loadFromFile(const std::string& name){
    TiXmlDocument doc(name.c_str());
    if(!doc.LoadFile()){
        std::cerr << "Error while loading world" << std::endl;
        std::cerr << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc() << std::endl;
        return 1;
    }

    //temp variables
    float coordinate;
    float time;

    //Get first 
    TiXmlHandle hdl(&doc);
    TiXmlElement *elem = hdl.FirstChild("world").FirstChild("enemies").FirstChild("enemy").ToElement();
    while(elem){
        std::istringstream issCoordinate(elem->Attribute("xCoordinate"));
        issCoordinate>>coordinate;
        
        std::istringstream issTime(elem->Attribute("time"));
        issTime>>time;

        std::cout << "enemy with time : " << elem->Attribute("time") << std::endl;
        myEntityModels.push(EntityModel(elem->Attribute("type"), coordinate, time));
        elem=elem->NextSiblingElement();
    }

    return 0;
}
