//
// Created by asuka on 09.03.2023.
//

# ifndef SNAKE_GLFW_SYSTEM_HPP
# define SNAKE_GLFW_SYSTEM_HPP

namespace snake {

    class GLFWSystem {
    public:
        GLFWSystem();
        ~GLFWSystem();

        GLFWSystem(const GLFWSystem&) = delete;
        GLFWSystem& operator=(const GLFWSystem&) = delete;

        GLFWSystem(GLFWSystem&&) noexcept = delete;
        GLFWSystem& operator=(GLFWSystem&&) noexcept = delete;

        static bool is_initialized() noexcept;

        void pool_events() const noexcept;
        [[nodiscard]] double get_time() const noexcept;

    private:
        static inline bool is_initialized_ = false;
    };

}

# endif // SNAKE_GLFW_SYSTEM_HPP
