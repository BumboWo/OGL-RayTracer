// camera.hpp

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    Camera(const glm::vec3& position, const glm::vec3& up, const glm::vec3& front);
    ~Camera() = default;

    glm::mat4 GetViewMatrix() const;
    glm::mat4 GetProjectionMatrix(float aspectRatio) const;
    void Rotate(const glm::vec3& rotation);

    float fov;
    float nearClip;
    float farClip;

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 up;
    glm::vec3 front;


private:

};
