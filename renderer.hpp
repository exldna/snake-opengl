//
// Created by asuka on 13.03.2023.
//

# ifndef SNAKE_RENDERER_HPP
# define SNAKE_RENDERER_HPP

# include <snake_renderer.hpp>

namespace snake {

    class Board;
    class Snake;

    class Renderer {
    public:
        Renderer(Board& board, Snake& snake);
        ~Renderer();

        Renderer(const Renderer&) = delete;
        Renderer& operator=(const Renderer&) = delete;

        Renderer(Renderer&&) noexcept = delete;
        Renderer& operator=(Renderer&&) noexcept = delete;

        void draw();

    private:
        SnakeRenderer snake_renderer_;

        unsigned int program_ = 0;
    };

} // snake

# endif // SNAKE_RENDERER_HPP
