#include "window.hpp"

#include <cassert>

#include "render/renderer.hpp"
#include "input.hpp"

Window::Window(int width, int height, const std::string& title) {
    if (!glfwInit())
        assert("GLFW can't initialized!");
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (window == nullptr)
        assert("Window can't created!");
    glfwMakeContextCurrent(window);
    Renderer::init((GLADloadproc)glfwGetProcAddress);
    glfwSwapInterval(1);

    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        Renderer::resizeCallback(width, height);
    });

    Input::setWindow(this);
}

Window::~Window() {
    glfwTerminate();
}

void Window::update()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}