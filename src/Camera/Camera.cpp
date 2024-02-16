// camera.cpp

#include "Camera.hpp"
#include <iostream>

Camera::Camera(const glm::vec3& position, const glm::vec3& up, const glm::vec3& front)
    : position(position), up(up), front(front), rotation(glm::vec3(0.0f, 0.0f, 0.0f)),
    fov(glm::radians(45.0f)), nearClip(0.1f), farClip(100.0f) {
    // Note: You can initialize the rotation angles in the member initializer list.
}

void Camera::Rotate(const glm::vec3& rotation) {
    // Update the rotation angles
    this->rotation += rotation;

    // Create rotation matrices
    glm::mat4 pitchMat = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 yawMat = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 rollMat = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

    // Combine the rotation matrices
    glm::mat4 rotationMat = yawMat * pitchMat * rollMat; // Corrected order of multiplication

    // Apply the rotation to the front and up vectors
    front = glm::mat3(rotationMat) * front;
    up = glm::mat3(rotationMat) * up;
}

glm::mat4 Camera::GetViewMatrix() const {
    return glm::lookAt(position, position + front, up);
}

glm::mat4 Camera::GetProjectionMatrix(float aspectRatio) const {
    return glm::perspective(glm::radians(fov), aspectRatio, nearClip, farClip);
}

