//
// Created by asuka on 09.03.2023.
//

# ifndef SNAKE_SNAKE_HPP
# define SNAKE_SNAKE_HPP

# include <deque>
# include <glm/vec2.hpp>

namespace snake {

    enum class SnakeMove : std::uint8_t {
        up, down, right, left,
    };

    class Snake {
    public:
        explicit Snake(glm::ivec2 head);
        ~Snake() = default;

        Snake(const Snake&) = delete;
        Snake& operator=(const Snake&) = delete;

        Snake(Snake&&) noexcept = delete;
        Snake& operator=(Snake&&) noexcept = delete;

        void move(SnakeMove move);

    private:
        void move_head(SnakeMove move);
        void move_tail();
        bool validate() const;

        glm::ivec2 head_ = {0, 0};
        std::deque<glm::ivec2> tail_{};
    };

} // snake

# endif // SNAKE_SNAKE_HPP
