//
// Created by asuka on 13.03.2023.
//

# include <renderer.hpp>
# include <board.hpp>
# include <snake.hpp>
# include <make_program.hpp>
# include <glad/glad.h>
# include <glm/mat4x4.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <glm/gtc/type_ptr.hpp>

namespace snake {

    Renderer::Renderer(Board& board, Snake& snake)
            : snake_renderer_(snake) {
        program_ = make_program("snake.vert", "snake.geom", "snake.frag");
        auto projection_loc = glGetUniformLocation(program_, "projection");
        auto board_x = static_cast<float>(board.get_size().x);
        auto board_y = static_cast<float>(board.get_size().y);
        auto projection = glm::ortho(0.f, board_x, 0.f, board_y);
        glUseProgram(program_);
        glUniformMatrix4fv(projection_loc, 1, false, glm::value_ptr(projection));
    }

    Renderer::~Renderer() {
        glDeleteProgram(program_);
    }

    void Renderer::draw() {
        glUseProgram(program_);
        snake_renderer_.draw();
    }

} // snake