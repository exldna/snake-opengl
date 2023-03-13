//
// Created by asuka on 10.03.2023.
//

# include <snake_controller.hpp>
# include <keys_input.hpp>

namespace snake {

    SnakeController::SnakeController(Snake& snake)
            : snake_(snake) {}

    void SnakeController::input(const KeysInput& keys_input) {
        if (keys_input.get_key_state(VirtualKey::key_w) == VirtualKeyAction::press ||
            keys_input.get_key_state(VirtualKey::key_up) == VirtualKeyAction::press) {
            direction = SnakeMove::up;
        }
        if (keys_input.get_key_state(VirtualKey::key_s) == VirtualKeyAction::press ||
            keys_input.get_key_state(VirtualKey::key_down) == VirtualKeyAction::press) {
            direction = SnakeMove::down;
        }
        if (keys_input.get_key_state(VirtualKey::key_d) == VirtualKeyAction::press ||
            keys_input.get_key_state(VirtualKey::key_right) == VirtualKeyAction::press) {
            direction = SnakeMove::right;
        }
        if (keys_input.get_key_state(VirtualKey::key_a) == VirtualKeyAction::press ||
            keys_input.get_key_state(VirtualKey::key_left) == VirtualKeyAction::press) {
            direction = SnakeMove::left;
        }
    }

    void SnakeController::update() {
        snake_.move(direction);
    }

} // snake