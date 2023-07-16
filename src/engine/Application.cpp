//
// Created by m4tex on 2023-06-29.
//

#include "engine/Application.h"
#include "engine/Input.h"

int Application::windowWidth = 0;
int Application::windowHeight = 0;
bool Application::fullscreen;
int Application::lastWidth, Application::lastHeight;
int Application::lastPosX, Application::lastPosY;


GLFWwindow* Application::_window = nullptr;

void Application::Update() {
    if(Input::GetInputState(KEY_ESC, INPUT_DOWN_FRAME))
        glfwSetWindowShouldClose(_window, GLFW_TRUE);


    if(Input::GetInputState(KEY_F11, INPUT_DOWN_FRAME))
    {
        fullscreen = !fullscreen;

        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);

        if(fullscreen)
        {
            glfwGetWindowSize(_window, &lastWidth, &lastHeight);
            glfwGetWindowPos(_window, &lastPosX, &lastPosY);
            glfwSetWindowMonitor(_window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        }
        else
        {
            glfwSetWindowMonitor(_window, nullptr, lastPosX, lastPosY, lastWidth, lastHeight, mode->refreshRate);
        }
    }
}

void Application::Initialize(GLFWwindow *window) {
    _window = window;
}
