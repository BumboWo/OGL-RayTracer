#pragma once
#include <vector>
#include <memory>
#include "Components/Component.hpp"

// Object class which can hold multiple components
class Object {
public:
    Object(const std::string& name);

    template <typename T>
    std::shared_ptr<T> getComponent();


    template <typename T>
    void addComponent(std::shared_ptr<T> component);

    std::string name;
private:
    std::vector<std::shared_ptr<Component>> components;
};

//Constructor
Object::Object(const std::string& name) : name(name) {
    
}

// Template implementation
template<typename T>
std::shared_ptr<T> Object::getComponent() {
    for (auto& component : components) {
        if (typeid(T) == component->getType()) {
            return std::dynamic_pointer_cast<T>(component);
        }
    }
    return nullptr;
}

template<typename T>
void Object::addComponent(std::shared_ptr<T> component) {
    components.push_back(component);
}
