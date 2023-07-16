//
// Created by m4tex on 2023-07-16.
//

#include "rendering/Model.h"
#include <fstream>
#include <sstream>

void Model::LoadFromFile(const std::string& filepath) {
    std::vector<float> vertices;
    std::vector<GLuint> indices;

    std::ifstream file(filepath);

    if(file.fail()) std::cout << "[Error]: Failed to load in a model from file." << std::endl;

    std::string line;
    while (std::getline(file, line)) {
        if (line[0] == 'v') {
            std::istringstream s(line.substr(2));
            float x, y, z;

            s >> x;
            s >> y;
            s >> z;

            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
        }
        else if (line[0] == 'f') {
            std::istringstream s(line.substr(2));
            unsigned int i, j, k;

            s >> i;
            s >> j;
            s >> k;

            indices.push_back(i-1);
            indices.push_back(j-1);
            indices.push_back(k-1);
        }
    }

    va = std::make_unique<VertexArray>();

    vb = std::make_unique<VertexBuffer>(vertices.data(),
                                        vertices.size() * sizeof(float));

    ib = std::make_unique<IndexBuffer>(indices.data(), indices.size());

    VertexBufferLayout layout;
    layout.PushF(3);

    va->AddBuffer(*vb, layout);

    vb->Unbind();
}