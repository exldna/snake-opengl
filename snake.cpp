//
// Created by asuka on 09.03.2023.
//

# include <snake.hpp>
# include <board.hpp>
# include <algorithm>

namespace snake {

    Snake::Snake(Board& board, glm::ivec2 head)
            : board_(board), head_(head) {}

    bool Snake::move(SnakeMove move) {
        move_tail();
        move_head(move);
        return validate();
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
            tail_.push_front(head_);
            tail_.pop_back();
        }
    }

    bool Snake::validate() const {
        bool head_didnt_crushed_into_tail = std::ranges::none_of(tail_.begin(), tail_.end(),
                [this](glm::ivec2 item) { return item == head_; });
        bool head_didnt_out_of_board = (head_.x >= 0 && head_.x < board_.get_size().x) &&
                                       (head_.y >= 0 && head_.y < board_.get_size().y);
        return head_didnt_crushed_into_tail && head_didnt_out_of_board;
    }

} // snake