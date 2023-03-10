//
// Created by asuka on 09.03.2023.
//

# ifndef SNAKE_GAME_HPP
# define SNAKE_GAME_HPP

# include <keys_input.hpp>

# include <board.hpp>
# include <snake.hpp>
# include <snake_controller.hpp>
# include <snake_renderer.hpp>

namespace snake {

    class Game {
    public:
        explicit Game(KeysInput keys_input);
        ~Game() = default;

        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;

        Game(Game&&) noexcept = delete;
        Game& operator=(Game&&) noexcept = delete;

        void update();
        void draw();

    private:
        KeysInput keys_input_;
        Board board_{};
        Snake snake_{board_, {5, 7}};
        SnakeController snake_controller_{snake_};
        SnakeRenderer snake_renderer_{snake_};
    };

} // snake

# endif // SNAKE_GAME_HPP
