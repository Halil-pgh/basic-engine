#pragma once

#include <unitypes.h>

class VBO {
public:
    VBO() = default;
    VBO(float* data, uint32_t size, uint32_t usage);
    ~VBO();

    void create(float* data, uint32_t size, uint32_t usage);

    void bind() const;
    void unbind() const;

private:
    uint32_t id;
};