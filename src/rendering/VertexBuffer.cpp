//
// Created by m4tex on 4/16/23.
//

#include "rendering/VertexBuffer.h"
#include "rendering/Renderer.h"
#include <iostream>

VertexBuffer::VertexBuffer(const void *data, unsigned int size) : m_RendererID(-1) {
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
    std::cout << "Destructing VB" << std::endl;
    glDeleteBuffers(1, &m_RendererID);
}

void VertexBuffer::Bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void VertexBuffer::Unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
