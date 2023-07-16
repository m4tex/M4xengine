//
// Created by m4tex on 2023-06-29.
//

#include "game/FreeCamera.h"
#include "engine/Input.h"
#include "engine/Application.h"

glm::vec2* cameraRotation = new glm::vec2();

FreeCamera::FreeCamera() {
    camera.position = &position;
    camera.eulerAngles = cameraRotation;
    cameraRotation->x = 90.0f;

    Input::SetCursorMode(CURSOR_HIDDEN);
}

void FreeCamera::Update(double deltaTime) {
//    if(eulerAngles.z != 0.0f) {
//        eulerAngles.z = 0.0f;
//        std::cout << "[Message]: Attempted rotation on Z-axis, rolling rotation for _cameras is not allowed." << std::endl;
//    }

    camera.aspect = (float)Application::windowWidth / (float)Application::windowHeight;

    glm::vec2 radCamRot = { glm::radians(cameraRotation->x), glm::radians(cameraRotation->y) };

    glm::vec3 forward = {
          glm::sin(radCamRot.y) * glm::cos(radCamRot.x),
          glm::sin(radCamRot.x),
            glm::cos(radCamRot.y) * glm::cos(radCamRot.x),
    };

    forward = glm::normalize(forward);

    glm::vec3 right = glm::normalize(glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f)));

    glm::vec3 up = glm::normalize(glm::cross(right, forward));

    if(Input::GetInputState(GLFW_KEY_LEFT_SHIFT, INPUT_DOWN_FRAME))
        movementSpeed *= 3;

    if(Input::GetInputState(GLFW_KEY_LEFT_SHIFT, INPUT_UP_FRAME))
        movementSpeed /= 3;

    if(Input::GetInputState(KEY_W, INPUT_HOLDING))
        position += forward * (float)(movementSpeed * deltaTime);

    if(Input::GetInputState(KEY_S, INPUT_HOLDING))
        position -= forward * (float)(movementSpeed * deltaTime);

    if(Input::GetInputState(KEY_A, INPUT_HOLDING))
        position -= right * (float)(movementSpeed * deltaTime);

    if(Input::GetInputState(KEY_D, INPUT_HOLDING))
        position += right * (float)(movementSpeed * deltaTime);

    if(Input::GetInputState(KEY_Q, INPUT_HOLDING))
        position -= up * (float)(movementSpeed * deltaTime);

    if(Input::GetInputState(KEY_E, INPUT_HOLDING))
        position += up * (float)(movementSpeed * deltaTime);

    auto mouseDelta = Input::GetMouseDelta() * (float)(deltaTime * mouseSensitivity);

    eulerAngles.x += mouseDelta.y;
    eulerAngles.y += mouseDelta.x;

    if(eulerAngles.x > 89.9f) eulerAngles.x = 89.9f;
    if(eulerAngles.x < -89.9f) eulerAngles.x = -89.9f;

    *cameraRotation = { eulerAngles.x, eulerAngles.y };
}