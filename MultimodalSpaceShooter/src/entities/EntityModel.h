#ifndef ENTITYMODEL_H
#define ENTITYMODEL_H

#include <string>

class EntityModel{
    public:
        EntityModel(const std::string& type, float xCoordinate, float time);
        std::string getType() const;
        float getXCoordinate() const;
        float getTime() const;

    private:

        std::string myType;
        float myXCoordinate;
        float myTime;
};

class CompareTime {
public:
    bool operator()(const EntityModel& e1, const EntityModel& e2)
    {
        return e1.getTime()<e2.getTime();
    }
};

#endif // ENTITYMODEL_H