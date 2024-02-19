#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <GL/glew.h>
#include "../Scene/Scene.hpp"

class Renderer {
public:
    Renderer();
    ~Renderer();

    int RenderScene(int width, int height, Scene currentScene);
    GLuint GetFramebufferTexture() const;

private:
    GLuint framebuffer;
    GLuint textureColorbuffer;

    int framebufferWidth;
    int framebufferHeight;



    void InitializeFramebuffer(int width, int height);
};

#endif // RENDERER_HPP
