#pragma once
#include <vector>
#include <memory>
#include "Components/Component.hpp"

// Object class which can hold multiple components
class SceneObject {
public:
    SceneObject(const std::string& objName);

    template <typename T>
    std::shared_ptr<T> getComponent();


    template <typename T>
    void addComponent(std::shared_ptr<T> component);

    std::vector<std::shared_ptr<Component>> getComponents() {
        return components;
    }

    std::string selfName;
private:
    std::vector<std::shared_ptr<Component>> components;
};

//Constructor
SceneObject::SceneObject(const std::string& objName) : selfName(objName) {

}

// Template implementation
template<typename T>
std::shared_ptr<T> SceneObject::getComponent() {
    for (auto& component : components) {
        if (typeid(T) == component->getType()) {
            return std::dynamic_pointer_cast<T>(component);
        }
    }
    return nullptr;
}

template<typename T>
void SceneObject::addComponent(std::shared_ptr<T> component) {
    components.push_back(component);
}
