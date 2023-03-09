//
// Created by asuka on 09.03.2023.
//

# ifndef SNAKE_GAME_HPP
# define SNAKE_GAME_HPP

# include <board.hpp>
# include <snake.hpp>
# include <snake_renderer.hpp>

namespace snake {

    class Game {
    public:
        Game();
        ~Game() = default;

        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;

        Game(Game&&) noexcept = delete;
        Game& operator=(Game&&) noexcept = delete;

        void update();
        void draw();

    private:
        Board board_{};
        Snake snake_{board_, {5, 7}};
        SnakeRenderer snake_renderer_{snake_};
    };

} // snake

# endif // SNAKE_GAME_HPP
