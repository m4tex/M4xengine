//
// Created by m4tex on 2023-06-15.
//

#pragma once

#include <string>
#include <rendering/M4xObject.h>

template<class T>
class Blueprint {
private:
    std::string _filepath;
    Blueprint* children;

public:
    Blueprint();
    Blueprint(std::string name, std::string path); //TODO: add MakeBlueprint() to M4xObject class.
    Blueprint ReadFromPath(std::string path);
    T Instantiate();
};