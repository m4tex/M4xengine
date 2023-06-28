//
// Created by m4tex on 2023-06-28.
//

#include "game/game.h"
#include "game/Terrain.h"
#include "game/TestObject.h"

std::vector<std::unique_ptr<M4xObject>> Game::sceneObjects;

void Game::Start() {
//    sceneObjects.push_back(std::make_unique<Terrain>());
    sceneObjects.push_back(std::make_unique<TestObject>());
}

void Game::Update() {
    for(auto& object : sceneObjects) {
        object->Update();
    }
}