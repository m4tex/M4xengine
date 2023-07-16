//
// Created by m4tex on 2023-07-16.
//

#pragma once

#include <memory>
#include "rendering/VertexArray.h"
#include "rendering/IndexBuffer.h"
#include "rendering/VertexBufferLayout.h"

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

