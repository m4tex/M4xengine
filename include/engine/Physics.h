//
// Created by m4tex on 2023-07-16.
//

#pragma once

#include <vector>
#include "M4xObject.h"

class Physics {
public:
    static void Update(float deltaTime);
    static void Add(M4xObject* obj);
    static void Remove(M4xObject* obj);

private:
    static std::vector<M4xObject> m_physicalObjects;
};