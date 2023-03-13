//
// Created by asuka on 13.03.2023.
//

# ifndef SNAKE_APPLE_HPP
# define SNAKE_APPLE_HPP

# include <random>
# include <glm/vec2.hpp>

namespace snake {

    class Board;

    class Apple {
    public:
        explicit Apple(Board& board);
        ~Apple() = default;

        Apple(const Apple&) = delete;
        Apple& operator=(const Apple&) = delete;

        Apple(Apple&&) noexcept = delete;
        Apple& operator=(Apple&&) noexcept = delete;

        void update();
        glm::ivec2 get_position() const;

    private:
        glm::ivec2 position_{};
        std::random_device rd{};
        std::mt19937 rng{rd()};
        using dist_type = std::uniform_int_distribution<int>;
        dist_type x_dist_;
        dist_type y_dist_;
    };

} // snake

# endif // SNAKE_APPLE_HPP
