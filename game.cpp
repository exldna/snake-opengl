//
// Created by asuka on 09.03.2023.
//

# include <game.hpp>

namespace snake {

    Game::Game(KeysInput keys_input)
            : keys_input_(keys_input) {}

    void Game::update() {
        snake_controller_.update(keys_input_);
        if (!snake_.validate()) {
            exit(0);
        }
    }

    void Game::draw() {
        snake_renderer_.draw();
    }

} // snake