#pragma once

#include "Resource.hpp"

class ResourceManager
{
    // Twoja implementacja tutaj
    private:
    std::unique_ptr<Resource> resource;  

    public:
   
    ResourceManager() : resource(std::make_unique<Resource>()) {}

    
    ResourceManager(const ResourceManager& other) 
        : resource(std::make_unique<Resource>(*other.resource)) {}

    ResourceManager(ResourceManager&& other) noexcept = default;

    
    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            resource = std::make_unique<Resource>(*other.resource);
        }
        return *this;
    }

     ResourceManager& operator=(ResourceManager&& other) noexcept = default;

    ~ResourceManager() = default;

    double get() const {
        return resource->get();
    }
};
