//
// Created by m4tex on 2023-06-14.
//

#include "engine/Input.h"

GLFWwindow* Input::_window = nullptr;
std::unordered_map<int, KeyTrack> Input::m_SubscribedKeysCache;
std::unordered_set<int> Input::m_KeyUpdateScheduler;

void Input::KeyInputCallback(GLFWwindow*, int key, int, int action, int) {
//    std::cout << (action == GLFW_PRESS) << ' ' << (action == GLFW_REPEAT) << ' ' << (action == GLFW_RELEASE) << std::endl;

    if (m_SubscribedKeysCache.find(key) != m_SubscribedKeysCache.end()) {
        switch (action) {
            case GLFW_PRESS:
                m_SubscribedKeysCache[key].keyDownFrame = true;
                m_KeyUpdateScheduler.insert(key);
                m_SubscribedKeysCache[key].isDown = true;
                break;
            case GLFW_RELEASE:
                m_SubscribedKeysCache[key].keyUpFrame = true;
                m_KeyUpdateScheduler.insert(key);
                m_SubscribedKeysCache[key].isDown = false;
                break;
            case GLFW_REPEAT: break;
            default:
                std::cout << "[Error]: Unhandled key state - '" << action << "'." << std::endl;
        }
    }
}

void Input::MouseInputCallback(GLFWwindow* window, int button, int action, int) {

}

void Input::Initialize(GLFWwindow* window) {
    _window = window;

    glfwSetKeyCallback(_window, KeyInputCallback);
//    glfwSetMouseButtonCallback(_window, MouseInputCallback);
}


bool Input::GetKeyState(int key, int inputState) {
    if (m_SubscribedKeysCache.find(key) != m_SubscribedKeysCache.end()){
        auto states = m_SubscribedKeysCache[key];

        switch (inputState) {
            case INPUT_DOWN_FRAME:
                return states.keyDownFrame;
            case INPUT_HOLDING:
                return states.isDown;
            case INPUT_UP_FRAME:
                return states.keyUpFrame;
        }
    }

    m_SubscribedKeysCache[key] = KeyTrack();

    return false;
}

void Input::Update() {
    for(int key : m_KeyUpdateScheduler) {
        m_SubscribedKeysCache[key].keyUpFrame = false;
        m_SubscribedKeysCache[key].keyDownFrame = false;
        m_KeyUpdateScheduler.erase(key);
    }
}