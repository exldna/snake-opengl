//
// Created by asuka on 09.03.2023.
//

# include "board.hpp"

snake::Board::Board(glm::ivec2 size)
        : size_(size) {}

glm::ivec2 snake::Board::get_size() const noexcept {
    return size_;
}

