#include "application.hpp"

#include "input.hpp"
#include "render/renderer.hpp"

#include <iostream>
#include <glad/glad.h>

Application::Application() : window(1024, 640, "Game") {
    vao.bind();

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 12,
         0.5f, -0.5f, 0.0f, 1,
         0.0f,  0.5f, 0.0f, 12
    };
    vbo.create(vertices, sizeof(vertices), GL_STATIC_DRAW);

    vbl.create({
        { ShaderType::float3, false },
        { ShaderType::int1, false }
    });

    shader.create("res/shaders/vertexShader.glsl", "res/shaders/fragmentShader.glsl");
}

void Application::run() {
    while (!window.isClosed()) {
        Renderer::clear(0.0f, 0.0f, 0.0f);
        Renderer::render(shader, vbo);

        window.update();
    }
}