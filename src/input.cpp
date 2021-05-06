#include "input.hpp"

Window* Input::window = nullptr;

bool Input::isKeyPressed(int key) {
    GLFWwindow* GLFWwin = window->getWindow();

    int state = glfwGetKey(GLFWwin, key);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool Input::isMouseButtonPressed(int mouseButton) {
    GLFWwindow* GLFWwin = window->getWindow();

    int state = glfwGetMouseButton(GLFWwin, mouseButton);
    return state == GLFW_PRESS;
}

glm::vec2 Input::getMousePos() {
    GLFWwindow* GLFWwin = window->getWindow();
    
    double xpos, ypos;
    glfwGetCursorPos(GLFWwin, &xpos, &ypos);
    return glm::vec2((float)xpos, (float)ypos);
}

void Input::setWindow(Window* window) {
    Input::window = window;
}