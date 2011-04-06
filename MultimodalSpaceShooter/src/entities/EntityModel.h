#ifndef ENTITYMODEL_H
#define ENTITYMODEL_H

#include <string>

class EntityModel
{
    public:
        EntityModel(const std::string& type, const std::string& imageFile, float xCoordinate, float speed, float time);
        std::string getType() const;
        std::string getImageFile() const;
        float getXCoordinate() const;
        float getSpeed() const;
        float getTime() const;

    private:
        std::string myType;
        std::string myImageFile;
        float myXCoordinate;
        float mySpeed;
        float myTime;
};

struct CompareTime
{
    bool operator()(const EntityModel& e1, const EntityModel& e2)
    {
        return e1.getTime() > e2.getTime();
    }
};

#endif // ENTITYMODEL_H