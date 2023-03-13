//
// Created by asuka on 13.03.2023.
//

# include <apple_renderer.hpp>
# include <apple.hpp>
# include <glad/glad.h>
# include <glm/vec2.hpp>

namespace snake {

    AppleRenderer::AppleRenderer(Apple& apple)
            : apple_(apple) {
        glCreateBuffers(1, &buffer_);
        glCreateVertexArrays(1, &vertex_array_);
        glVertexArrayVertexBuffer(vertex_array_, 0, buffer_, 0, sizeof(glm::vec2));
        glEnableVertexArrayAttrib(vertex_array_, 0);
        glVertexArrayAttribFormat(vertex_array_, 0, 2, GL_FLOAT, false, 0);
        glVertexArrayAttribBinding(vertex_array_, 0, 0);
    }

    AppleRenderer::~AppleRenderer() {
        glDeleteVertexArrays(1, &vertex_array_);
        glDeleteBuffers(1, &buffer_);
    }

    void AppleRenderer::draw() {
        auto apple_position = static_cast<glm::vec2>(apple_.get_position());
        glNamedBufferData(buffer_, sizeof(glm::vec2), &apple_position, GL_DYNAMIC_DRAW);
        glBindVertexArray(vertex_array_);
        glDrawArrays(GL_POINTS, 0, 1);
    }

} // snake