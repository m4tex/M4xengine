//
// Created by m4tex on 2023-06-28.
//

#pragma once
#include <vector>
#include <memory>
#include "engine/M4xObject.h"
#include "game/FreeCamera.h"

class Game {
public:

    static Camera* activeCamera;
    static int cameraCount;
    static int currentCameraIndex;

    static void Start();
    static void Update(double deltaTime);
    template<typename T>
    static T* Instantiate();
    static void AddCamera(FreeCamera* cam);
    static M4xObject* GetObject(std::string& name);
    static std::vector<std::unique_ptr<M4xObject>>* GetSceneObjects();

private:
    static std::vector<std::unique_ptr<M4xObject>> _sceneObjects;
    static std::vector<Camera*> _cameras;
};