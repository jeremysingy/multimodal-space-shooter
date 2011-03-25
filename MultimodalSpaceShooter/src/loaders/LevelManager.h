#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <string>
#include <tinyxml.h>
#include <iostream>

class LevelManager {
    public:
        virtual int loadFromFile(const std::string& name);
        
    private:
        LevelManager();
        ~LevelManager();
}

#endif // LEVELMANAGER_H