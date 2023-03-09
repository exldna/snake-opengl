//
// Created by asuka on 09.03.2023.
//

# ifndef SNAKE_SNAKE_HPP
# define SNAKE_SNAKE_HPP

# include <deque>
# include <glm/vec2.hpp>

namespace snake {

    class Board;
    class SnakeRenderer;

    enum class SnakeMove : std::uint8_t {
        up, down, right, left,
    };

    class Snake {
        friend SnakeRenderer;
    public:
        Snake(Board& board, glm::ivec2 head);
        ~Snake() = default;

        Snake(const Snake&) = delete;
        Snake& operator=(const Snake&) = delete;

        Snake(Snake&&) noexcept = delete;
        Snake& operator=(Snake&&) noexcept = delete;

        bool move(SnakeMove move);

    private:
        Board& board_;

        void move_head(SnakeMove move);
        void move_tail();
        [[nodiscard]] bool validate() const;

        glm::ivec2 head_ = {5, 7};
        std::deque<glm::ivec2> tail_{
                {5, 6},
                {5, 5}
        };
    };

} // snake

# endif // SNAKE_SNAKE_HPP
