#include "Object.hpp"

void Object::update() {
    for (auto& component : components) {
        component->update();
    }
}
