// Renderer.cpp
#include "Renderer.hpp"
#include <iostream>

Renderer::Renderer() : framebufferWidth(800), framebufferHeight(600) {
    InitializeFramebuffer(framebufferWidth, framebufferHeight);
    // Additional initialization code
}

Renderer::~Renderer() {
    glDeleteFramebuffers(1, &framebuffer);
    glDeleteTextures(1, &textureColorbuffer);
}

void Renderer::InitializeFramebuffer(int width, int height) {
    // Generate framebuffer
    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

    // Create color attachment texture
    glGenTextures(1, &textureColorbuffer);
    glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureColorbuffer, 0);

    // Create render buffer object for depth and stencil attachments if needed
    // ...



    // Check if framebuffer is complete
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cout << "Framebuffer Incomplete!";

    // Unbind framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

int Renderer::RenderScene(int width, int height, Scene currentScene) {

    glm::vec3 Origin = currentScene.godCam.position;

    Camera currentCam = currentScene.godCam;

    // Check if framebuffer needs to be regenerated
    if (width != framebufferWidth || height != framebufferHeight) {
        InitializeFramebuffer(width, height);
        framebufferWidth = width;
        framebufferHeight = height;
    }

    // Render your scene to the framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glClearColor(currentCam.front[0], currentCam.front[1], currentCam.front[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // Your scene rendering logic here
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    return 1;
}

GLuint Renderer::GetFramebufferTexture() const {
    return textureColorbuffer;
}

