#include "loaders/LevelManager.h"
#include <utils/tinyxml/tinyxml.h>

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

    //Get first 
    TiXmlHandle hdl(&doc);
    TiXmlElement *elem = hdl.FirstChild("world").FirstChild("enemies").FirstChild("enemy").ToElement();
    if(elem){
        //std::cout << "first ennemy should be planet : " << elem->Attribute("time") << std::endl;
        //myEntityModels.push(new EntityModel(elem->Attribute("type"), elem->Attribute("xCoordinate"), elem->Attribute("time")));
    }

    return 0;
}
