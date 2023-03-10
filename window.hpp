//
// Created by asuka on 09.03.2023.
//

# ifndef SNAKE_WINDOW_HPP
# define SNAKE_WINDOW_HPP

# include <glm/vec2.hpp>
# include <string>

struct GLFWwindow; // GLFW/glfw3.h

namespace snake {

    struct DisplayData {
        glm::ivec2 size;
        std::string title;
    };

    class KeysInput;

    class Window {
        friend KeysInput;

    public:
        explicit Window(const DisplayData& display_data);
        ~Window();

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        Window(Window&& other) noexcept;
        Window& operator=(Window&& other) noexcept;

        [[nodiscard]] bool should_close() const;
        void swap_buffers() const;

    private:
        GLFWwindow* window_ = nullptr;
    };

} // snake

# endif // SNAKE_WINDOW_HPP
