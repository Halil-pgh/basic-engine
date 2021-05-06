#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <string>

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    void update();
    
    inline bool isClosed() const { return glfwWindowShouldClose(window); }
    inline GLFWwindow* getWindow() const { return window; }
private:
    GLFWwindow* window;
};