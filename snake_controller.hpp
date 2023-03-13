//
// Created by asuka on 10.03.2023.
//

# ifndef SNAKE_SNAKE_CONTROLLER_HPP
# define SNAKE_SNAKE_CONTROLLER_HPP

# include <snake.hpp>

namespace snake {

    class KeysInput;

    class SnakeController {
    public:
        explicit SnakeController(Snake& snake);
        ~SnakeController() = default;

        SnakeController(const SnakeController&) = delete;
        SnakeController& operator=(const SnakeController&) = delete;

        SnakeController(SnakeController&&) noexcept = delete;
        SnakeController& operator=(SnakeController&&) noexcept = delete;

        void input(const KeysInput& keys_input);
        void update();

    private:
        Snake& snake_;
        SnakeMove direction{SnakeMove::up};
    };

} // snake

# endif // SNAKE_SNAKE_CONTROLLER_HPP
