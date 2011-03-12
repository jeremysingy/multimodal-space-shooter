template <typename ResType>
ResourceManager<ResType>::ResourceManager(const std::string& resourcePath) :
myPath(resourcePath)
{

}

template <typename ResType>
ResourceManager<ResType>::~ResourceManager()
{
    
}

template <typename ResType>
std::shared_ptr<ResType> ResourceManager<ResType>::get(const std::string& name)
{
    typename MapResources::const_iterator it = myResources.find(name);

    if(it != myResources.end())
        return it->second;

    return load(name);
}

template <typename ResType>
void ResourceManager<ResType>::remove(const std::string& name)
{
    if(myResources.find(name) == myResources.end())
        throw std::invalid_argument(name + ": resource not found");

    myResources.erase(name);
}

template <typename ResType>
void ResourceManager<ResType>::put(const std::string& name, std::shared_ptr<ResType> resource)
{
    myResources[name] = resource;
}