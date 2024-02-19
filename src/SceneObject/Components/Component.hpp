#pragma once
#include <typeinfo> // for typeid

// Base class for components
class Component {
public:
    virtual void update() = 0;
    virtual ~Component() {}

    // Get the type of the component
    virtual const std::type_info& getType() const = 0;
};
