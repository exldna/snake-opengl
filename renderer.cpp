//
// Created by asuka on 13.03.2023.
//

# include <renderer.hpp>
# include <game.hpp>
# include <make_program.hpp>
# include <glad/glad.h>
# include <glm/mat4x4.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <glm/gtc/type_ptr.hpp>

namespace snake {

    Renderer::Renderer(Game& game)
            : snake_renderer_(game.get_snake()), apple_renderer_(game.get_apple()) {
        program_ = make_program("snake.vert", "snake.geom", "snake.frag");
        auto projection_loc = glGetUniformLocation(program_, "projection");
        auto board_size = game.get_board().get_size();
        auto board_x = static_cast<float>(board_size.x);
        auto board_y = static_cast<float>(board_size.y);
        auto projection = glm::ortho(0.f, board_x, 0.f, board_y);
        glUseProgram(program_);
        glUniformMatrix4fv(projection_loc, 1, false, glm::value_ptr(projection));
        color_loc_ = glGetUniformLocation(program_, "color");
    }

    Renderer::~Renderer() {
        glDeleteProgram(program_);
    }

    void Renderer::draw() {
        glUseProgram(program_);
        glUniform3f(color_loc_, 1, 0, 0);
        snake_renderer_.draw();
        glUniform3f(color_loc_, 0, 1, 0);
        apple_renderer_.draw();
    }

} // snake