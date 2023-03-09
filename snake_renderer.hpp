//
// Created by asuka on 09.03.2023.
//

# ifndef SNAKE_SNAKE_RENDERER_HPP
# define SNAKE_SNAKE_RENDERER_HPP

namespace snake {

    class Snake;

    class SnakeRenderer {
    public:
        explicit SnakeRenderer(Snake& snake);
        ~SnakeRenderer();

        SnakeRenderer(const SnakeRenderer&) = delete;
        SnakeRenderer& operator=(const SnakeRenderer&) = delete;

        SnakeRenderer(SnakeRenderer&&) noexcept = delete;
        SnakeRenderer& operator=(SnakeRenderer&&) noexcept = delete;

        void draw() const;

    private:
        Snake& snake_;
        unsigned int buffer_ = 0, vertex_array_ = 0, program_ = 0;
    };

} // snake

# endif // SNAKE_SNAKE_RENDERER_HPP
