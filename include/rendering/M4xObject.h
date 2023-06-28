//
// Created by m4tex on 5/19/23.
//

#pragma once

#include <glm/glm.hpp>
#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "Texture.h"
#include <memory>

struct LightData {
    glm::vec3 lightDir;
    glm::vec3 ambient;
    float bias;
};

struct Model {
    std::unique_ptr<VertexArray> va = nullptr;
    std::unique_ptr<IndexBuffer> ib = nullptr;
    std::unique_ptr<VertexBuffer> vb = nullptr;

    Model() = default;
    
    explicit Model (const std::string& filepath) {
        LoadFromFile(filepath);
    }

    void LoadFromFile(const std::string& filepath);
};

const ShaderConfig defaultShaderConfig = {
        "../res/shaders/standard/basic_vertex.glsl",
        "../res/shaders/standard/basic_lit_fragment.glsl",
        "../res/shaders/standard/basic_lit_geometry.glsl"
};

struct Material {
    glm::vec3 color = { 1.0f, 1.0f, 1.0f };
    float shininess = 0.5f;
    Texture* texture = nullptr;
    ShaderConfig shaderConfig = defaultShaderConfig;
    Shader* shader;
};

class M4xObject {
public:
    std::string name;
    std::string tag;

    glm::vec3 position;
    glm::vec3 eulerAngles;
    glm::vec3 scale;

    M4xObject();
    M4xObject(std::string name, glm::vec3 pos, glm::vec3 rot = { 0, 0, 0 });
    M4xObject(Material& material, Model& model);

    void SetMaterial(Material& material);
    void SetModel(Model& model);
    void PrepareDraw(glm::mat4 perspective, glm::mat4 view, LightData lightData);

//    virtual void Init();
    virtual void Update();

    Model* model = nullptr;
    Material* material = nullptr;
};
