//
// Created by m4tex on 2023-06-28.
//

#pragma once
#include <vector>
#include <memory>
#include "rendering/M4xObject.h"

class Game {
public:
    static std::vector<std::unique_ptr<M4xObject>> sceneObjects;

    static void Start();
    static void Update();
};