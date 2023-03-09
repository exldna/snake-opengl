//
// Created by asuka on 09.03.2023.
//

# include "snake.hpp"
#include <algorithm>

namespace snake {

    Snake::Snake(glm::ivec2 head)
            : head_(head) {}

    void Snake::move(SnakeMove move) {
        move_head(move);
        move_tail();
        validate();
    }

    void Snake::move_head(SnakeMove move) {
        glm::ivec2 direction = {0, 0};
        switch (move) {
            case SnakeMove::up:
                direction = {0, 1};
                break;
            case SnakeMove::down:
                direction = {0, -1};
                break;
            case SnakeMove::right:
                direction = {1, 0};
                break;
            case SnakeMove::left:
                direction = {-1, 0};
                break;
        }
        head_ += direction;
    }

    void Snake::move_tail() {
        if (!tail_.empty()) {
            tail_.push_front(tail_.back());
            tail_.pop_back();
        }
    }

    bool Snake::validate() const {
        return std::ranges::none_of(tail_.begin(), tail_.end(),
                [this](glm::ivec2 item) { return item == head_; });
    }

} // snake