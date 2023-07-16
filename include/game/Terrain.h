//
// Created by m4tex on 2023-06-28.
//

#include <engine/M4xObject.h>

#pragma once

class Terrain : public M4xObject {
public:
    void Update(double deltaTime) override;
};