//
// Created by asuka on 09.03.2023.
//

# include <game.hpp>
# include <glad/glad.h>

namespace snake {

    Game::Game() {
    }

    void Game::update() {
        if (!snake_.move(SnakeMove::up)) {
            std::exit(0);
        }
    }

    void Game::draw() {
        snake_renderer_.draw();
    }

} // snake