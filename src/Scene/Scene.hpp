// scene.hpp

#pragma once

#include <vector>
#include <iostream>
#include "../Camera/Camera.hpp"

class Scene {
public:
    std::string name;

    Camera godCam = Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    // Constructor
    Scene(const std::string& sceneName);

};
