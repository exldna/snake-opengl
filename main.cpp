//
// Created by asuka on 09.03.2023.
//

# include <glad/glad.h>
# include <glfw_system.hpp>

# include <window.hpp>
# include <game.hpp>

int main() {
    auto glfw = snake::GLFWSystem();
    auto window = snake::Window({{500, 500}, "snake"});

    auto game = snake::Game(snake::KeysInput{window});

    const double upd = 4;
    const double fps = 10;

    double upd_rate = 1. / upd;
    double fps_rate = 1. / fps;

    double last_time, curr_time = glfw.get_time(),
            upd_time_count = 0,
            fps_time_count = 0;

    bool should_redraw = true;

    while (!window.should_close()) {
        last_time = curr_time;
        curr_time = glfw.get_time();
        auto duration = curr_time - last_time;
        upd_time_count += duration;
        fps_time_count += duration;

        if (should_redraw && fps_time_count >= fps_rate) {
            fps_time_count -= fps_rate;
            glClear(GL_COLOR_BUFFER_BIT);
            game.draw();
            window.swap_buffers();
            should_redraw = false;
        }

        while (upd_time_count >= upd_rate) {
            upd_time_count -= upd_rate;
            if (!should_redraw) should_redraw = true;
            glfw.pool_events();
            game.update();
        }
    }

    return 0;
}
