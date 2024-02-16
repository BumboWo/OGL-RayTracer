#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include "Scene/Scene.hpp"
#include "uiManager/uiManager.hpp"
#include "renderer/renderer.hpp"

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Set GLFW to use OpenGL Core Profile, version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(1520, 680, "Ray Tracer", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    // Print OpenGL version
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    Scene scene("MainScene");

    // Create UIManager and Renderer
    UIManager uiManager(window);
    Renderer renderer;

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Render Scene using the Renderer class

        if (renderer.RenderScene((int)uiManager.viewportSize.x, (int)uiManager.viewportSize.y, scene))
        {
            // Render UI using the UIManager class
            uiManager.RenderUI(scene, renderer.GetFramebufferTexture());
        }

        // Swap buffers, handle events, etc.
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
