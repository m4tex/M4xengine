//
// Created by m4tex on 2023-06-29.
//

#include "../rendering/Renderer.h"
#include "engine/M4xObject.h"
#pragma once

class FreeCamera : public M4xObject {
public:
    FreeCamera();
    Camera camera;
//    glm::vec3 forward;
//    glm::vec3 right;
//    glm::vec3 up;
    float movementSpeed = 40.0f;
    float mouseSensitivity = 20.0f;
private:
    void Update(double deltaTime) override;
};