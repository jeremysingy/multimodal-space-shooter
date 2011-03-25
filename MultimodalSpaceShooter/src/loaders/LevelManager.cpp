#include "LevelManager.h"

LevelManager::LevelManager(){

}

int loadFromFile(const std::string& name){
    TiXmlDocument doc(name.c_str());
    if(!doc.LoadFile()){
        std::cerr << "Error while loading world" << std::endl;
        std::cerr << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc() << std::endl;
        return 1;
    }

    //Get first 
    TiXmlHandle hdl(&doc);
    TiXmlElement *elem = hdl.FirstChild("world").FirstChild("ennemies").ToElement();
    if(elem){
        std::cout << "first ennemy should be planet : " << elem->Attribute("type") << std::endl;
    }


    return 0;
}
