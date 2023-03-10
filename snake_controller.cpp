//
// Created by asuka on 10.03.2023.
//

# include <snake_controller.hpp>
# include <keys_input.hpp>
# include <snake.hpp>

namespace snake {

    SnakeController::SnakeController(Snake& snake)
            : snake_(snake) {}

    void SnakeController::update(const KeysInput& keys_input) {
        if (keys_input.get_key_state(VirtualKey::key_w) == VirtualKeyAction::press) {
            direction = SnakeMove::up;
        }
        if (keys_input.get_key_state(VirtualKey::key_s) == VirtualKeyAction::press) {
            direction = SnakeMove::down;
        }
        if (keys_input.get_key_state(VirtualKey::key_d) == VirtualKeyAction::press) {
            direction = SnakeMove::right;
        }
        if (keys_input.get_key_state(VirtualKey::key_a) == VirtualKeyAction::press) {
            direction = SnakeMove::left;
        }
        snake_.move(direction);
    }

} // snake