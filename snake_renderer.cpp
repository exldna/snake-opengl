//
// Created by asuka on 09.03.2023.
//

# include <snake_renderer.hpp>
# include <snake.hpp>

# include <make_program.hpp>
# include <glad/glad.h>

# include <glm/vec3.hpp>
# include <glm/mat4x4.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <glm/gtc/type_ptr.hpp>

namespace snake {

    SnakeRenderer::SnakeRenderer(Snake& snake)
            : snake_(snake) {
        program_ = make_program("snake.vert", "snake.geom", "snake.frag");
        glUseProgram(program_);
        auto mvp_loc = glGetUniformLocation(program_, "mvp");
        auto projection = glm::ortho(0.f, 20.f, 0.f, 20.f);
        glUniformMatrix4fv(mvp_loc, 1, false, glm::value_ptr(projection));

        glCreateBuffers(1, &buffer_);
        glCreateVertexArrays(1, &vertex_array_);
        glVertexArrayVertexBuffer(vertex_array_, 0, buffer_, 0, sizeof(glm::vec2));
        glEnableVertexArrayAttrib(vertex_array_, 0);
        glVertexArrayAttribFormat(vertex_array_, 0, 2, GL_FLOAT, false, 0);
        glVertexArrayAttribBinding(vertex_array_, 0, 0);
    }

    SnakeRenderer::~SnakeRenderer() {
        glDeleteBuffers(1, &buffer_);
        glDeleteVertexArrays(1, &vertex_array_);
        glDeleteProgram(program_);
    }

    void SnakeRenderer::draw() const {
        auto bytes_buffer_size = static_cast<int>((snake_.tail_.size() + 1) * sizeof(glm::vec2));
        glNamedBufferData(buffer_, bytes_buffer_size, nullptr, GL_DYNAMIC_DRAW);
        auto* buffer_ptr = reinterpret_cast<glm::vec2*>(glMapNamedBuffer(buffer_, GL_WRITE_ONLY));
        buffer_ptr[0] = snake_.head_;
        for (std::ptrdiff_t i = 0; i < snake_.tail_.size(); ++i) {
            buffer_ptr[i + 1] = snake_.tail_[i];
        }
        glUnmapNamedBuffer(buffer_);
        // draw buffer
        glUseProgram(program_);
        glBindVertexArray(vertex_array_);
        glDrawArrays(GL_POINTS, 0, 3);
    }

} // snake