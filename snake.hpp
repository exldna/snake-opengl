//
// Created by asuka on 09.03.2023.
//

# ifndef SNAKE_SNAKE_HPP
# define SNAKE_SNAKE_HPP

# include <deque>
# include <glm/vec2.hpp>

namespace snake {

    class Board;
    class Apple;
    class SnakeRenderer;

    enum class SnakeMove : std::uint8_t {
        up, down, right, left,
    };

    class Snake {
        friend SnakeRenderer;
    public:
        Snake(Board& board, Apple& apple, glm::ivec2 head);
        ~Snake() = default;

        Snake(const Snake&) = delete;
        Snake& operator=(const Snake&) = delete;

        Snake(Snake&&) noexcept = delete;
        Snake& operator=(Snake&&) noexcept = delete;

        void move(SnakeMove move);
        void try_eat();
        [[nodiscard]] bool validate() const;

    private:
        Board& board_;
        Apple& apple_;

        bool should_move_tail_ = true;
        glm::ivec2 head_ = {0, 0};
        std::deque<glm::ivec2> tail_{};

        void move_head(SnakeMove move);
        void move_tail();
    };

} // snake

# endif // SNAKE_SNAKE_HPP
