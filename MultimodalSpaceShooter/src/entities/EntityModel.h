#ifndef ENTITYMODEL_H
#define ENTITYMODEL_H

#include <string>

class EntityModel{
    public:
        std::string& getType();
        int getXCoordinate();
        int getTime();

    private:
        EntityModel(const std::string& type, int xCoordinate, int time);

        std::string myType;
        int myXCoordinate;
        int myTime;
};

class CompareTime {
public:
    bool operator()(const EntityModel& e1, const EntityModel& e2)
    {
        //TODO
        return true;
        //return e1.getTime()<e2.getTime();
    }
};

#endif // ENTITYMODEL_H