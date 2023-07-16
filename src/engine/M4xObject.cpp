//
// Created by m4tex on 5/19/23.
//

#include "engine/M4xObject.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/euler_angles.hpp"
#include <iostream>
#include <utility>
#include <vector>

void M4xObject::SetMaterial(Material &newMaterial) {
    newMaterial.shader = new Shader(newMaterial.shaderConfig);
    material = &newMaterial;

    if (newMaterial.texture != nullptr)
        material->shader->SetUniform1i("u_Texture", 0);

}

void M4xObject::SetModel(Model& value) {
    this->model = &value;
}

void M4xObject::PrepareDraw(glm::mat4 perspectiveMatrix, glm::mat4 viewMatrix, LightData lightData) {
    if(model != nullptr) {
        model->va->Bind();
        model->ib->Bind();
    }

    if (material != nullptr) {
        material->shader->Bind();

        glm::mat4 translate = glm::translate(glm::mat4(1.0f), position);

        glm::vec3 eaRad = eulerAngles * glm::radians(1.0f);

        glm::mat4 rotate = glm::eulerAngleXYZ(eaRad.x, eaRad.y, eaRad.z);
        glm::mat4 scaleMat = glm::scale(glm::mat4(1.0f), scale);

        glm::mat4 modelMatrix = translate * rotate * scaleMat;

        material->shader->SetUniformMat4f("u_Model", modelMatrix);
        material->shader->SetUniformMat4f("u_ViewPerspective", perspectiveMatrix * viewMatrix);

        auto color = material->color;
        material->shader->SetUniform3f("u_Color", color.x, color.y, color.z);

        material->shader->SetUniform1f("u_Shininess", material->shininess);

        material->shader->SetUniform1f("u_Bias", lightData.bias);

        auto lDir = lightData.lightDir;
        material->shader->SetUniform3f("u_LightDir", lDir.x, lDir.y, lDir.z);

        auto amb = lightData.ambient;
        material->shader->SetUniform3f("u_Ambient", amb.x, amb.y, amb.z);

        if (material->texture != nullptr)
            material->texture->Bind(0);
    }
}

M4xObject::M4xObject(std::string name, glm::vec3 pos, glm::vec3 rot) :  name(std::move(name)),
                                                                        position(pos),
                                                                        eulerAngles(rot) {}

M4xObject::M4xObject() : position(), eulerAngles(), scale(1.0f) {}

M4xObject::M4xObject(Material &material, Model &model) : position(), eulerAngles(), scale(1.0f) {
    SetMaterial(material);
    SetModel(model);
}

//void M4xObject::Init() {
//    std::cout << "[Message]: Empty object Init function" << std::endl;
//}

void M4xObject::Update(double deltaTime) {
    std::cout << "[Message]: Empty object Update function" << std::endl;
}