//
// Created by asuka on 10.03.2023.
//

# include <keys_input.hpp>
# include <window.hpp>

namespace snake {

    KeysInput::KeysInput(const Window& window)
            : window_(window.window_) {};

    VirtualKeyAction KeysInput::get_key_state(VirtualKey key) const noexcept {
        return static_cast<VirtualKeyAction>(glfwGetKey(const_cast<GLFWwindow*>(window_), snake::to_numeric(key)));
    }

} // snake