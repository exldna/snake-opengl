//
// Created by asuka on 10.03.2023.
//

# ifndef SNAKE_KEYS_INPUT_HPP
# define SNAKE_KEYS_INPUT_HPP

struct GLFWwindow;
# include <virtual_keys.hpp>

namespace snake {

    class Window;

    class KeysInput {
    public:
        explicit KeysInput(const Window& window);
        ~KeysInput() = default;

        KeysInput(const KeysInput&) = default;
        KeysInput& operator=(const KeysInput&) = delete;

        KeysInput(KeysInput&&) noexcept = default;
        KeysInput& operator=(KeysInput&&) noexcept = delete;

        [[nodiscard]] VirtualKeyAction get_key_state(VirtualKey key) const noexcept;

    private:
        const GLFWwindow* const& window_;
    };

} // snake

# endif // SNAKE_KEYS_INPUT_HPP
