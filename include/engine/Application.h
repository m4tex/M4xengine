//
// Created by m4tex on 2023-06-29.
//

#pragma once
#include <GLFW/glfw3.h>

class Application {
public:
    static bool fullscreen, windowed;
    static int windowWidth, windowHeight;
    static void Initialize(GLFWwindow* window);
    static void Update(); //Where the application related behaviour will be handled.
private:
    static GLFWwindow* _window;
    static int lastWidth, lastHeight, lastPosX, lastPosY;
};