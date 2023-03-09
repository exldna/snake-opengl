//
// Created by asuka on 09.03.2023.
//

# ifndef SNAKE_WINDOW_HPP
# define SNAKE_WINDOW_HPP

struct GLFWwindow; // GLFW/glfw3.h

namespace snake {

    class Window {
    public:

    private:
        GLFWwindow* window_ = nullptr;
    };

} // snake

# endif // SNAKE_WINDOW_HPP
