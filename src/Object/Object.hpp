#pragma once
#include <vector>
#include <memory>
#include "Components/Component.hpp"

// Object class which can hold multiple components
class Object {
public:
    template <typename T>
    std::shared_ptr<T> getComponent();


    template <typename T>
    void addComponent(std::shared_ptr<T> component);

    void update();

private:
    std::vector<std::shared_ptr<Component>> components;
};

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
