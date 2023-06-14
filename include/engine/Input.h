//
// Created by m4tex on 2023-06-14.
//

#pragma once

#include <GLFW/glfw3.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

#define KEY_A GLFW_KEY_A
#define KEY_B GLFW_KEY_B
#define KEY_C GLFW_KEY_C
#define KEY_D GLFW_KEY_D
#define KEY_E GLFW_KEY_E
#define KEY_F GLFW_KEY_F
#define KEY_G GLFW_KEY_G
#define KEY_H GLFW_KEY_H
#define KEY_I GLFW_KEY_I
#define KEY_J GLFW_KEY_J
#define KEY_K GLFW_KEY_K
#define KEY_L GLFW_KEY_L
#define KEY_M GLFW_KEY_M
#define KEY_O GLFW_KEY_O
#define KEY_P GLFW_KEY_P
#define KEY_Q GLFW_KEY_Q
#define KEY_R GLFW_KEY_R
#define KEY_S GLFW_KEY_S
#define KEY_T GLFW_KEY_T
#define KEY_U GLFW_KEY_U
#define KEY_V GLFW_KEY_V
#define KEY_W GLFW_KEY_W
#define KEY_X GLFW_KEY_X
#define KEY_Y GLFW_KEY_Y
#define KEY_Z GLFW_KEY_Z
#define KEY_A0 GLFW_KEY_0
#define KEY_A1 GLFW_KEY_1
#define KEY_A2 GLFW_KEY_2
#define KEY_A3 GLFW_KEY_3
#define KEY_A4 GLFW_KEY_4
#define KEY_A5 GLFW_KEY_5
#define KEY_A6 GLFW_KEY_6
#define KEY_A7 GLFW_KEY_7
#define KEY_A8 GLFW_KEY_8
#define KEY_A9 GLFW_KEY_9
#define KEY_LCTRL GLFW_KEY_LEFT_CONTROL
#define KEY_RCTRL GLFW_KEY_RIGHT_CONTROL
#define KEY_LALT GLFW_KEY_LEFT_ALT
#define KEY_RALT GLFW_KEY_RIGHT_ALT
#define KEY_LSHIFT GLFW_KEY_LEFT_SHIFT
#define KEY_RSHIFT GLFW_KEY_RIGHT_SHIFT
#define KEY_ENTER GLFW_KEY_ENTER
#define KEY_TAB GLFW_KEY_TAB
#define KEY_CAPS GLFW_KEY_CAPS_LOCK
#define KEY_COMMA GLFW_KEY_COMMA
#define KEY_PERIOD GLFW_KEY_PERIOD
#define KEY_SLASH GLFW_KEY_SLASH
#define KEY_BACKSLASH GLFW_KEY_BACKSLASH
#define KEY_SEMICOLON GLFW_KEY_SEMICOLON
#define KEY_APOSTROPHE GLFW_KEY_APOSTROPHE
#define KEY_BACKSPACE GLFW_KEY_BACKSPACE
#define KEY_LARROW GLFW_KEY_LEFT
#define KEY_RARROW GLFW_KEY_RIGHT
#define KEY_UPARROW GLFW_KEY_UP
#define KEY_DOWNARROW GLFW_KEY_RIGHT
#define KEY_ESC GLFW_KEY_ESCAPE
#define KEY_F1 GLFW_KEY_F1
#define KEY_F2 GLFW_KEY_F2
#define KEY_F3 GLFW_KEY_F3
#define KEY_F4 GLFW_KEY_F4
#define KEY_F5 GLFW_KEY_F5
#define KEY_F6 GLFW_KEY_F6
#define KEY_F7 GLFW_KEY_F7
#define KEY_F8 GLFW_KEY_F8
#define KEY_F9 GLFW_KEY_F9
#define KEY_F10 GLFW_KEY_F10
#define KEY_F11 GLFW_KEY_F11
#define KEY_F12 GLFW_KEY_F12

#define MOUSE_LEFT GLFW_MOUSE_BUTTON_LEFT
#define MOUSE_MIDDLE GLFW_MOUSE_BUTTON_MIDDLE
#define MOUSE_RIGHT GLFW_MOUSE_BUTTON_RIGHT

#define INPUT_DOWN_FRAME 0
#define INPUT_HOLDING 1
#define INPUT_UP_FRAME 2

struct KeyTrack {
    bool keyDownFrame;
    bool isDown;
    bool keyUpFrame;
};

class Input {

private:
    static std::unordered_map<int, KeyTrack> m_SubscribedKeysCache;
    static std::unordered_set<int> m_KeyUpdateScheduler;
    static void KeyInputCallback(GLFWwindow*, int key, int, int action, int);
    static void MouseInputCallback(GLFWwindow* window, int button, int action, int);
    static GLFWwindow* _window;

public:
    static void Initialize(GLFWwindow* window);

    static void Update();
    static bool GetInputState(int input, int inputState);
};