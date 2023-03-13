//
// Created by asuka on 09.03.2023.
//

# include <snake.hpp>
# include <board.hpp>
# include <apple.hpp>
# include <algorithm>

namespace snake {

    Snake::Snake(Board& board, Apple& apple, glm::ivec2 head)
            : board_(board), apple_(apple), head_(head) {}

    void Snake::move(SnakeMove move) {
        if (should_move_tail_) {
            move_tail();
        } else {
            should_move_tail_ = true;
        }
        move_head(move);
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

    void Snake::try_eat() {
        if (head_ == apple_.get_position()) {
            tail_.push_front(head_);
            should_move_tail_ = false;
            apple_.update();
        }
    }

    bool Snake::validate() const {
        bool head_didnt_crushed_into_tail = std::ranges::none_of(tail_.begin(), tail_.end(),
                [this](glm::ivec2 item) { return item == head_; });
        bool head_didnt_out_of_board = (head_.x >= 0 && head_.x < board_.get_size().x) &&
                                       (head_.y >= 0 && head_.y < board_.get_size().y);
        return head_didnt_crushed_into_tail && head_didnt_out_of_board || (!should_move_tail_);
    }

} // snake