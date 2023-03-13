//
// Created by asuka on 09.03.2023.
//

# include <game.hpp>

namespace snake {

    Game::Game(KeysInput keys_input)
            : keys_input_(keys_input) {}

    void Game::input() {
        snake_controller_.input(keys_input_);
    }

    void Game::update() {
        snake_controller_.update();
        if (!snake_.validate()) {
            exit(0);
        }
    }

} // snake