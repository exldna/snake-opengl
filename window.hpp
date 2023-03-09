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

    class Window {
    public:
        explicit Window(const DisplayData& display_data);
        ~Window();

    private:
        GLFWwindow* window_ = nullptr;
    };

} // snake

# endif // SNAKE_WINDOW_HPP
