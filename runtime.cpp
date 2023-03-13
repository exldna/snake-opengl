//
// Created by asuka on 13.03.2023.
//

# include <runtime.hpp>
#include <glad/glad.h>

namespace snake {

    void Runtime::run() {
        double last_time, curr_time = glfw_.get_time(),
                upd_time_count = 0,
                fps_time_count = 0;

        bool should_redraw = true;

        while (!window_.should_close()) {
            last_time = curr_time;
            curr_time = glfw_.get_time();
            auto duration = curr_time - last_time;
            upd_time_count += duration;
            fps_time_count += duration;

            if (should_redraw && fps_time_count >= fps_rate_) {
                fps_time_count -= fps_rate_;
                glClear(GL_COLOR_BUFFER_BIT);
                renderer_.draw();
                window_.swap_buffers();
                should_redraw = false;
            }

            while (upd_time_count >= upd_rate_) {
                upd_time_count -= upd_rate_;
                if (!should_redraw) should_redraw = true;
                glfw_.pool_events();
                game_.input();
                game_.update();
            }
        }

    }

} // snake