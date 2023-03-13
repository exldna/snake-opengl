//
// Created by asuka on 13.03.2023.
//

# ifndef SNAKE_RUNTIME_HPP
# define SNAKE_RUNTIME_HPP

# include <glfw_system.hpp>
# include <window.hpp>
# include <game.hpp>

namespace snake {

    class Runtime {
    public:
        Runtime() = default;
        ~Runtime() = default;

        Runtime(const Runtime&) = delete;
        Runtime& operator=(const Runtime&) = delete;

        Runtime(Runtime&&) noexcept = delete;
        Runtime& operator=(Runtime&&) noexcept = delete;

        void run();

    private:
        const double upd_ = 4;
        const double fps_ = 10;

        const double upd_rate_ = 1. / upd_;
        const double fps_rate_ = 1. / fps_;

        GLFWSystem glfw_{};
        Window window_{{{500, 500}, "Snake"}};
        KeysInput keys_input_{window_};
        Game game_{keys_input_};
    };

} // snake

# endif // SNAKE_RUNTIME_HPP
