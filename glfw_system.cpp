//
// Created by asuka on 09.03.2023.
//

# include "glfw_system.hpp"
# include <GLFW/glfw3.h>
# include <stdexcept>

namespace snake {

    GLFWSystem::GLFWSystem() {
        if (!is_initialized_) {
            if (!glfwInit()) {
                throw std::runtime_error("failed to init GLFW");
            }
            is_initialized_ = true;
        }
    }

    GLFWSystem::~GLFWSystem() {
        if (is_initialized_) {
            glfwTerminate();
            is_initialized_ = false;
        }
    }

    bool GLFWSystem::is_initialized() noexcept {
        return is_initialized_;
    }

    void GLFWSystem::pool_events() const noexcept {
        glfwPollEvents();
    }

    double GLFWSystem::get_time() const noexcept {
        return glfwGetTime();
    }

}