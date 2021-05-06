#include "vbo.hpp"

#include <glad/glad.h>

VBO::VBO(float* data, uint32_t size, uint32_t usage) {
    create(data, size, usage);
}

VBO::~VBO() {
    glDeleteBuffers(1, &id);
}

void VBO::create(float* data, uint32_t size, uint32_t usage) {
    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
}

void VBO::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
