#pragma once
#include "../Component.hpp"
#include <glm/glm.hpp>

// Transform component
class Transform : public Component {
public:
    Transform(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale) : position(position), rotation(rotation), scale(scale) {}

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

    const glm::vec3& getRotation() const {
        return rotation;
    }

    void setRotation(const glm::vec3& newRotation) {
        rotation = newRotation;
    }

    const glm::vec3& getScale() const {
        return scale;
    }

    void setScale(const glm::vec3& newScale) {
        scale = newScale;
    }

private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};
