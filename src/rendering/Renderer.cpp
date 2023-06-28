//
// Created by m4tex on 4/16/23.
//

#include "rendering/Renderer.h"

void Renderer::Draw(M4xObject& object) const {
    object.PrepareDraw(_camera->PerspectiveMatrix(), _camera->ViewMatrix(), { lightDir, ambient, bias });

    glDrawElements(GL_TRIANGLES, object.model->ib->GetCount(), GL_UNSIGNED_INT, nullptr);
}

#define GRID_SPACING 5
#define GRID_SIZE (2000 + GRID_SPACING)

const int lineCount = (GRID_SIZE / GRID_SPACING);
const int floatCount = lineCount * 2 * 2 * 4; // Positions and colors, 2 vertices per line, horizontal and vertical lines
const float halfGrid = (float)GRID_SIZE / 2;

const int originLineIndex = (int)(lineCount / 2);

float gridVertices[floatCount];

float LineBrightness(int index) {
    if (index == originLineIndex) return 0.5f;
    if (index % 5 == 0) return 0.25f;
    return 0.175f;
}

void GenGrid() {
    // X lines
    for (int i = 0; i < lineCount; ++i) {
        int index = i * 8;

        float rowCoordinates = -halfGrid + (GRID_SPACING * ((float)i + 0.5f));
        float brightness = LineBrightness(i);

        gridVertices[index] = -halfGrid + 2;
        gridVertices[index+1] = 0;
        gridVertices[index+2] = rowCoordinates;

        gridVertices[index+3] = brightness;

        gridVertices[index+4] = halfGrid;
        gridVertices[index+5] = 0;
        gridVertices[index+6] = rowCoordinates;

        gridVertices[index+7] = brightness;
    }

    // Z lines
    for (int i = 0; i < lineCount; ++i) {
        int start = floatCount / 2;
        int index = start + (i * 8);

        float rowCoordinates = -halfGrid + (GRID_SPACING * ((float)i + 0.5f));
        float brightness = LineBrightness(i);

        gridVertices[index] = rowCoordinates;
        gridVertices[index+1] = 0;
        gridVertices[index+2] = -halfGrid;

        gridVertices[index+3] = brightness;

        gridVertices[index+4] = rowCoordinates;
        gridVertices[index+5] = 0;
        gridVertices[index+6] = halfGrid;

        gridVertices[index+7] = brightness;
    }
}


void Renderer::DrawScene(std::vector<std::unique_ptr<M4xObject>>& objects) {
    _gridShader.Bind();
    _gridShader.SetUniformMat4f("u_MVP", _camera->PerspectiveMatrix() * _camera->ViewMatrix() * glm::mat4(1.0f));
    _gridShader.SetUniform3f("u_CamPos", _camera->position.x, _camera->position.y, _camera->position.z);
    _gridModel.va->Bind();

    glDisable(GL_DEPTH_TEST);
    glDrawArrays(GL_LINES, 0, floatCount);
    glEnable(GL_DEPTH_TEST);

    for (auto& object : objects) {
        object->PrepareDraw(_camera->PerspectiveMatrix(), _camera->ViewMatrix(), { lightDir, ambient, bias });
        glDrawElements(GL_TRIANGLES, (int)object->model->ib->GetCount(), GL_UNSIGNED_INT, nullptr);
    }
}

void Renderer::SwitchCamera(Camera& camera) {
    _camera = &camera;
}

Renderer::Renderer(Camera& camera) : _camera(&camera), _gridShader(ShaderConfig::Grid()) {
    GenGrid();

    _gridShader.Bind();
    _gridShader.SetUniform3f("u_Color", 0.25f, 0.25f, 0.25f);
    _gridShader.SetUniformMat4f("u_MVP", _camera->PerspectiveMatrix() * _camera->ViewMatrix() * glm::mat4(1.0f));
    _gridShader.SetUniform3f("u_CamPos", camera.position.x, camera.position.y, camera.position.z);

    _gridModel.vb = std::make_unique<VertexBuffer>(gridVertices, floatCount * sizeof(float));
    VertexBufferLayout layout;
    layout.PushF(3);
    layout.PushF(1);
    _gridModel.va = std::make_unique<VertexArray>();
    _gridModel.va->AddBuffer(*_gridModel.vb, layout);

    SwitchCamera(camera);
}