//
// Created by asuka on 13.03.2023.
//

# include <snake_renderer.hpp>
# include <snake.hpp>

# include <glad/glad.h>

namespace snake {

    const int SnakeRenderer::vertex_byte_size = sizeof(glm::vec2);

    SnakeRenderer::SnakeRenderer(Snake& snake)
            : snake_(snake) {
        glCreateBuffers(1, &buffer_);
        glCreateVertexArrays(1, &vertex_array_);
        glVertexArrayVertexBuffer(vertex_array_, 0, buffer_, 0, vertex_byte_size);
        glEnableVertexArrayAttrib(vertex_array_, 0);
        glVertexArrayAttribFormat(vertex_array_, 0, 2, GL_FLOAT, false, 0);
        glVertexArrayAttribBinding(vertex_array_, 0, 0);
    }

    SnakeRenderer::~SnakeRenderer() {
        glDeleteVertexArrays(1, &vertex_array_);
        glDeleteBuffers(1, &buffer_);
    }

    void SnakeRenderer::draw() {
        auto vertices_count = static_cast<int>(snake_.tail_.size() + 1);
        glNamedBufferData(buffer_, vertices_count * vertex_byte_size, nullptr, GL_DYNAMIC_DRAW);
        auto* mapped_ptr = reinterpret_cast<glm::vec2*>(glMapNamedBuffer(buffer_, GL_WRITE_ONLY));
        mapped_ptr[0] = snake_.head_;
        std::copy(snake_.tail_.begin(), snake_.tail_.end(), mapped_ptr + 1);
        glUnmapNamedBuffer(buffer_);
        glBindVertexArray(vertex_array_);
        glDrawArrays(GL_POINTS, 0, vertices_count);
    }

} // snake