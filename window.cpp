//
// Created by asuka on 09.03.2023.
//

# include "window.hpp"
# include "glfw_system.hpp"

# include <glad/glad.h>
# include <GLFW/glfw3.h>

# include <stdexcept>

namespace snake {

    Window::Window(const DisplayData& display_data) {
        if (!GLFWSystem::is_initialized()) {
            throw std::runtime_error("GLFW must be initialized");
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
        glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_NATIVE_CONTEXT_API);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

        window_ = glfwCreateWindow(display_data.size.x, display_data.size.y,
                display_data.title.c_str(), nullptr, nullptr);

        if (window_ == nullptr) {
            throw std::runtime_error("Failed to create window");
        }

        glfwMakeContextCurrent(window_);

        if (!gladLoadGL()) {
            throw std::runtime_error("Failed to load OpenGL");
        }
    }

    Window::~Window() {
        if (window_ != nullptr) {
            glfwDestroyWindow(window_);
        }
    }

} // snake