#pragma once

#include <unitypes.h>

class VAO {
public:
    VAO();
    ~VAO();

    void bind() const;
    void unbind() const;
private:
    uint32_t id;
};