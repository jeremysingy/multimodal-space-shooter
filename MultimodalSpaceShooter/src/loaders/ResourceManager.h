#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <memory>
#include <map>
#include <string>
#include <stdexcept>

template <typename ResType>
class ResourceManager
{
    public:
        ResourceManager(const std::string& resourcePath = "./");
        virtual ~ResourceManager();

        virtual std::shared_ptr<ResType> load(const std::string& name) = 0;
        std::shared_ptr<ResType> get(const std::string& name);
        void remove(const std::string& name);

    protected:
        void put(const std::string& name, std::shared_ptr<ResType> resource);
        std::string myPath;
    
    private:
        typedef std::shared_ptr<ResType> ResourcePtr;
        typedef std::map<std::string, ResourcePtr> MapResources;

        MapResources myResources;
};

#include "ResourceManager.inl"

#endif // RESOURCEMANAGER_H