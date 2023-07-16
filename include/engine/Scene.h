//
// Created by m4tex on 2023-06-15.
//

#pragma once

#include <engine/M4xObject.h>

class Scene {
public:
    M4xObject children; //I guess you could say this is where the root node sits.

private:
    std::string _filepath;
};
