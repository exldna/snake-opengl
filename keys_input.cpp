//
// Created by asuka on 10.03.2023.
//

# include <keys_input.hpp>
# include <window.hpp>

# include <GLFW/glfw3.h>

namespace snake {

    KeysInput::KeysInput(const Window& window)
            : window_(window.window_) {
        glfwSetInputMode(const_cast<GLFWwindow*>(window_), GLFW_STICKY_KEYS, GLFW_TRUE);
    }

    VirtualKeyAction KeysInput::get_key_state(VirtualKey key) const noexcept {
        return static_cast<VirtualKeyAction>(glfwGetKey(const_cast<GLFWwindow*>(window_), snake::to_numeric(key)));
    }

} // snake