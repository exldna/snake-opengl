//
// Created by asuka on 13.03.2023.
//

# ifndef SNAKE_APPLE_RENDERER_HPP
# define SNAKE_APPLE_RENDERER_HPP

namespace snake {

    class Apple;

    class AppleRenderer {
    public:
        AppleRenderer(Apple& apple);
        ~AppleRenderer();

        AppleRenderer(const AppleRenderer&) = delete;
        AppleRenderer& operator=(const AppleRenderer&) = delete;

        AppleRenderer(AppleRenderer&&) noexcept = delete;
        AppleRenderer& operator=(AppleRenderer&&) noexcept = delete;

        void draw();

    private:
        Apple& apple_;
        unsigned int buffer_ = 0;
        unsigned int vertex_array_ = 0;
    };

} // snake

# endif // SNAKE_APPLE_RENDERER_HPP
