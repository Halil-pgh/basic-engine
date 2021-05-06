#pragma once

#include "window.hpp"

#include "render/vao.hpp"
#include "render/vbl.hpp"
#include "render/vbo.hpp"
#include "render/shader.hpp"

class Application {
public:
    Application();

    void run();
private:
    Window window;

    Shader shader;
    VBO vbo;
    VBL vbl;
    VAO vao;
};