//
// Created by m4tex on 2023-06-28.
//

#include "game/Game.h"
#include "game/Terrain.h"

std::vector<std::unique_ptr<M4xObject>> Game::_sceneObjects;
std::vector<Camera*> Game::_cameras;
Camera* Game::activeCamera = nullptr;

void Game::Start() {
    auto cam = Instantiate<FreeCamera>();
    AddCamera(cam);
}

void Game::Update(double deltaTime) {
    for(auto& object : _sceneObjects) {
        object->Update(deltaTime);
    }
}

template<typename T>
T* Game::Instantiate() {
    _sceneObjects.push_back(std::make_unique<T>());

    auto cast = dynamic_cast<T*>(_sceneObjects[_sceneObjects.size() - 1].get());
    if(cast) return cast;

    throw std::exception();
}

//template<typename T>
//T* Game::Instantiate() {
//    static_assert(std::is_base_of<M4xObject, T>::value,
//                  "T must derive from MyBaseClass");
//
//    auto ptr = std::make_unique<T>();
//
//    _sceneObjects.push_back(ptr);
//
//    return dynamic_cast<T*>(_sceneObjects[_sceneObjects.size() - 1].get());
//}

M4xObject* Game::GetObject(std::string& name) {
    return nullptr;
}

std::vector<std::unique_ptr<M4xObject>>* Game::GetSceneObjects() {
    return &_sceneObjects;
}

void Game::AddCamera(FreeCamera* cam) {
    if(activeCamera == nullptr) activeCamera = &(cam->camera);
}