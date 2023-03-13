//
// Created by asuka on 13.03.2023.
//

# include <apple.hpp>
# include <board.hpp>

# include <iostream>

namespace snake {

    Apple::Apple(Board& board)
            : x_dist_(0, board.get_size().x - 1),
              y_dist_(0, board.get_size().y - 1) {
        // generate first state
        update();
    }

    void Apple::update() {
        position_.x = x_dist_(rng);
        position_.y = y_dist_(rng);
    }

    glm::ivec2 Apple::get_position() const {
        return position_;
    }

} // snake