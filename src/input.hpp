#pragma once

#include <glm/glm.hpp>
#include "window.hpp"

class Input {
public:
    static bool isKeyPressed(int key);
    static bool isMouseButtonPressed(int mouseButton);
    static glm::vec2 getMousePos();

    static void setWindow(Window* window);
private:
    static Window* window;
};