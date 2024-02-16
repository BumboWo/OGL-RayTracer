
// uiManager.hpp

#ifndef UIMANAGER_HPP
#define UIMANAGER_HPP

#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>

#include "../Scene/Scene.hpp"

#include <iostream>
#include <chrono>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class UIManager {
public:
    UIManager(GLFWwindow* window);
    ~UIManager();

    ImVec2 viewportSize;

    void RenderUI(Scene& _scene, GLuint textureID);

private:
    GLFWwindow* window;

    std::chrono::high_resolution_clock::time_point lastFrameTime;
    float fpsCounterBuffer = 0.0f;
    float fps = 0.0f;

    // Add ImGui initialization function
    void InitializeImGui();
};

#endif // UIMANAGER_HPP
