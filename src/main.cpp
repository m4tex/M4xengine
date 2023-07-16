#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 750

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <engine/Physics.h>

#include "engine/Input.h"
#include "engine/Application.h"
#include "rendering/Renderer.h"

#include "game/Game.h"

void GLAPIENTRY MessageCallback(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar* message, const void*) {
    std::cout << "[GL Message]: " << message << std::endl;
}

void window_resize_callback(GLFWwindow*, int width, int height) {
    glViewport(0, 0, width, height);
    Application::windowWidth = width;
    Application::windowHeight = height;
}

int main()
{
    if (!glfwInit())
        return -1;

    //#region GLFW Window Creation
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    glfwWindowHint(GLFW_SAMPLES, 4);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Solar Engine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (glfwRawMouseMotionSupported()) {
        glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
    }

    glfwSetWindowSizeCallback(window, window_resize_callback);
    //#endregion

    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initiate Glew" << std::endl;
        return -1;
    }

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, nullptr);

    std::cout << glGetString(GL_VERSION) << std::endl;

    Input::Initialize(window);

    Game::Start();

    Renderer renderer(*Game::activeCamera);

    Application::windowWidth = WINDOW_WIDTH;
    Application::windowHeight = WINDOW_HEIGHT;
    Application::Initialize(window);

    double lastFrame = 0.0;
    double time;
    double deltaTime;

    glClearColor(0.15f, 0.15f, 0.15f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        time = glfwGetTime();
        deltaTime = time - lastFrame;
        lastFrame = time;

        Physics::Update(deltaTime);
        Game::Update(deltaTime);

        renderer.DrawScene(*Game::GetSceneObjects());

        Application::Update();

        Input::Update();

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}