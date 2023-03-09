//
// Created by asuka on 09.03.2023.
//

# ifndef SNAKE_BOARD_HPP
# define SNAKE_BOARD_HPP

# include <glm/vec2.hpp>

namespace snake {

    class Snake;

    class Board {
    public:
        Board() = default;
        ~Board() = default;

        explicit Board(glm::ivec2 size);

        Board(const Board&) = delete;
        Board& operator=(const Board&) = delete;

        Board(Board&&) noexcept = delete;
        Board& operator=(Board&&) noexcept = delete;

        [[nodiscard]] glm::ivec2 get_size() const noexcept;

    private:
        glm::ivec2 size_ = {20, 20};
    };

}

# endif // SNAKE_BOARD_HPP
