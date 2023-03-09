//
// Created by asuka on 09.03.2023.
//

# include <glfw_system.hpp>
# include <window.hpp>

int main() {
    auto glfw = snake::GLFWSystem();
    auto window = snake::Window({{800, 600}, "snake"});
}
