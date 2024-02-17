#pragma once
#include "../Component.hpp"
#include <glm/glm.hpp>

// Transform component
class Transform : public Component {
public:
    Transform(const glm::vec3& position) : position(position) {}

    void update() override {
        // Implement transform update logic if needed
    }

    const std::type_info& getType() const override {
        return typeid(Transform);
    }

    // Accessor methods for position
    const glm::vec3& getPosition() const {
        return position;
    }

    void setPosition(const glm::vec3& newPosition) {
        position = newPosition;
    }

private:
    glm::vec3 position;
};
