//
// Created by m4tex on 2023-06-28.
//

#include "game/TestObject.h"
#include "engine/Input.h"

void TestObject::Update() {
    if(Input::GetInputState(KEY_J, INPUT_HOLDING)) {
        material->color.g += 0.025f;
        if(material->color.g >= 1.0f) material->color.g = 0.0f;
    }
}

TestObject::TestObject() {
    auto* model = new Model("./models/among.obj");
    auto* material = new Material();
    material->shaderConfig = ShaderConfig::BasicLit();
    SetMaterial(*material);
    SetModel(*model);
}