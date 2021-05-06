#pragma once

#include "vbo.hpp"
#include "shader.hpp"

typedef void *(*GLADloadproc)(const char *name);

class Renderer {
public:
    static void init(GLADloadproc proc);
    static void resizeCallback(int width, int height);

    static void clear(float r, float g, float b);
    static void render(Shader& shader, VBO& vbo);
};