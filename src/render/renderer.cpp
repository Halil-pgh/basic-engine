#include "renderer.hpp"

#include <glad/glad.h>

#include <cassert>

void Renderer::init(GLADloadproc proc) {
    if (!gladLoadGLLoader(proc)) {
        assert("Opengl context cant created!");
    }
}

void Renderer::resizeCallback(int width, int height) {
    glViewport(0, 0, width, height);
}

void Renderer::render(Shader& shader, VBO& vbo) {
    vbo.bind();
    shader.bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Renderer::clear(float r, float g, float b) {
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}