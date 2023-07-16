//
// Created by m4tex on 2023-07-16.
//

#pragma once

#include <glm/vec3.hpp>
#include "rendering/Model.h"

class Collider {
public:
    Model* mesh = nullptr;

    glm::vec3 boundingBox[8];
    void RecalculateBoundingBox();
};
